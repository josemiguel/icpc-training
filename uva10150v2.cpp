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

#define MAX 25500

int pai[MAX];
char *cads[MAX];
vector<int> g[MAX];
int n;
void track(int i){
	if (i > 0){
		track(pai[i]);
		printf("%s\n",cads[i]);
	}
}

vector<int> g[MAX];
int n;

bool bfs(int s,int e, int n){
	queue<int> q;
	q.push(s);
	for(int i = 0; i < n ; i++) pai[i] = -1;
	pai[s] = -2;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < g[v].size() ; i++){
			int u = g[v][i];
			if (pai[u] == -1){
				pai[u] = v;
				if (u == e) return true;
				q.push(u); 
			}
		}
	}
	return false;
}


bool one(char *a, char *b, int len){
	int diff = 0;
	for(int k = 0; k < len; k++){
		diff += (a[k]!=b[k]);
		if (diff > 1)return false;
	}
	return true;
}

int pos(char *s){
	for(int i = 1; i < n; i++){
		if (!strcmp(s,cads[i])) return i;
	}
	return -1;
}

int main(){

	n = 1;
	char s[100],e[100];
	for(int i=0; scanf("%s",s); i++){
		cads[n] = strdup(s);
		n++;
		cin.ignore();
		if (cin.peek() == '\n') break;
	}
	for(int i = 1; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			char *a = cads[i], *b = cads[j];
			int len = strlen(a);
			if (len != strlen(b)) continue;
			if (one(a,b,len)){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	int k = 0;
	while(scanf("%s %s",s,e)!=-1){
		if (k !=0) putchar(10);
		k = 1;
		int ss = pos(s);		
		int ee = pos(e);
		if (bfs(ss,ee,n))
			track(ee);
		else
			puts("No solution.");
		
	}

	return 0;
}
