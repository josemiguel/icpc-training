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
#define MAX 300
int g1[MAX][MAX];
int g2[MAX][MAX];
int n1,n2;

void to_lower(string &u){
	for(int i = 0; i < u.length(); i++){
		u[i] = tolower(u[i]);
	}
}
int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		if (r!=1) putchar(10);
		scanf("%d",&n1);
		map<string,int> mpa;
		string u,v;
		int n = 0;
		memset(g1,0,sizeof(g1));
		for(int i = 0 ; i < n1 ;i++){
			cin>>u>>v;
			to_lower(u);
			to_lower(v);
			if (mpa.find(u) == mpa.end()) mpa[u] = n++;
			if (mpa.find(v) == mpa.end()) mpa[v] = n++;
			int uu = mpa[u], vv = mpa[v];
			g1[uu][vv] = g1[vv][uu] = 1;
		}
		scanf("%d",&n2);
		memset(g2,0,sizeof(g2));
		for(int i = 0 ; i < n2 ;i++){
			cin>>u>>v;
			to_lower(u);
			to_lower(v);
			if (mpa.find(u) == mpa.end()) mpa[u] = n++;
			if (mpa.find(v) == mpa.end()) mpa[v] = n++;
			int uu = mpa[u], vv = mpa[v];
			g2[uu][vv] = g2[vv][uu] = 1;			
		}
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					g1[i][j] = g1[j][i] = (g1[i][j] | (g1[i][k] & g1[k][j]));
				
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					g2[i][j] = g2[j][i] = (g2[i][j] | (g2[i][k] & g2[k][j]));
		
		bool no = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (g1[i][j] != g2[i][j]){
					no = true;
					break;
				}
			}
		}
		
		if (!no){
			puts("YES");
		}else {
			puts("NO");
		}
								
	}
	
	return 0;
}
