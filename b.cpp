#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 10010
#define MAXM 102
#define MAXS 35
#define ASIZE 26

using namespace std;

int lens[MAXN];
char dict[MAXN][MAXS];
int mask[MAXN][ASIZE];
int ids[MAXN];
char results[MAXM][MAXS];
char list[ASIZE+10];
int ret, retpenalty;

bool mycmp(int a, int b) {
	return lens[a] < lens[b];
}

int sortlet;
bool mycmp2(int a, int b)
{
	return mask[a][sortlet] < mask[b][sortlet];
}

void solve(int l, int r, int lpos, int penalty)
{


	if (l == r) {
		if (penalty > retpenalty || (penalty == retpenalty && ids[l] < ret)) {
			ret = ids[l];
			retpenalty = penalty;
		}
		return;
	}

	int let = list[lpos]-'a';

	sortlet = let;
	sort(ids+l, ids+r+1, mycmp2);

	int tl = l;
	for (int i = l+1; i <= r+1; i++)
		if (i == r+1 || (mask[ids[i]][let] != mask[ids[i-1]][let])) {
			int tr = i-1;
			solve(tl, tr, lpos+1, penalty + (mask[ids[tr]][let] == 0 && mask[ids[r]][let]));
			tl = i;
		}
}

int main()
{
	int T;

	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		int n, m;

		scanf("%d %d", &n, &m);
		
		for (int i = 0; i < n; i++) {
			scanf(" %s", dict[i]);
			for (int j = 0; j < 26; j++)
				mask[i][j] = 0;
			lens[i] = strlen(dict[i]);
			for (int k = 0; k < lens[i]; k++)
				mask[i][(dict[i][k]-'a')] |= (1<<k);
		}

		for (int i = 0; i < n; i++)
			ids[i] = i;
		sort(ids, ids+n, mycmp);

		for (int i = 0; i < m; i++) {
			scanf(" %s", list);
			ret = -1;
			retpenalty = -1;

			int l = 0;
			for (int j = 1; j <= n; j++)
				if (j == n || lens[ids[j]] != lens[ids[j-1]]) {
					int r = j-1;
					solve(l, r, 0, 0);
					l = j;
				}

			strcpy(results[i], dict[ret]);
		}

		printf("Case #%d:", t+1);
		for (int i = 0; i < m; i++)
			printf(" %s", results[i]);
		printf("\n");
	}

	return 0;
}
