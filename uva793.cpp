#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30

int n;
#define MAX 10005

int id[MAX], sz[MAX]; 

void Init(int n) {
	for (int i = 0; i < n; i++)
		id[i] = i, sz[i] = 1;
}

int Find(int i) {
	if (i == id[i]) return i;
	return id[i] = Find(id[i]);
}

void Union(int v, int w) {
	v = Find(v); w = Find(w);
	if (v == w) return;
	if (sz[v] > sz[w]) swap(v,w);
	id[v] = w;
	if (sz[v] == sz[w]) sz[w]++;
}
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d",&n);
		cin.ignore();
		int tot = 0, suc = 0;
		if (r!=1) putchar(10);
		char s[100];
		Init(n);
		while(fgets(s,100,stdin) && s[0] != '\n'){
			char c;
			int u,v;
			sscanf(s,"%c %d %d",&c,&u,&v);
			u--,v--;
			if (c == 'c'){
				Union(u,v);
			}else if (c == 'q'){
				tot++;
				suc += (Find(u) == Find(v));
			}
		}
		
		printf("%d,%d\n",suc,tot-suc);
	}
	
	return 0;
}
