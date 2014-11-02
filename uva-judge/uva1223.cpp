#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 5010

int RA[MAXN], SA[MAXN], LCP[MAXN], *FC, *SC, step;
char S[MAXN];

bool cmp(const int &a, const int &b){
	if (step == -1 || FC[a] != FC[b]) return FC[a] < FC[b];
	return FC[a + (1<<step)] < FC[ b + (1<<step) ];
}

int len(char *p, char *q){
	int res = 0;
	while(*p == *q) res++,	p++, q++;
	return res;
}

#define Max(x,y) x > y ? x : y


void suffix_array(char *S, int n){
	for(int i = 0; i < n; i++) RA[i] = S[SA[i] = i];
	
	for(FC = RA, SC = LCP, step = -1; (1<<step) < n; step++){
		sort(SA,SA+n,cmp);
		int idx = 0;
		SC[SA[0]] = 0;
		for( int i = 1; i < n; i++ ){
			if ( cmp( SA[i-1],SA[i] ) ) idx++;
			SC[SA[i]] = idx;
		}
		if (idx == n-1) break;
		
		swap(FC,SC);
	}
	for(int i = 0; i< n; i++) RA[ SA[i] ] = i;
	
	int res = 0;
	for(int i = 1; i < n; i++)
		res = Max(res,len(S+SA[i-1],S+SA[i]));
	
	printf("%d\n",res);
}


int main(){
	int runs;
	scanf("%d\n",&runs);
	while(runs--){
		gets(S);
		int n = strlen(S);
		suffix_array(S, n +1 ) ;
	}	
}

