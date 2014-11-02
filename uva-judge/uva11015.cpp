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
#define MAX 25
int g[MAX][MAX];
//vector<vector<int> > g;
int n,m;

int main(){
	
	for(int r = 1 ; scanf("%d %d",&n,&m) && n+m ; r++){
		string p;
		vector<string> s;
		for(int i = 0; i < n; i++){
			cin>>p;
			s.push_back(p);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (i == j) g[i][j] = 0;
				else g[i][j] = 1 << 20;
			}
		}
		for(int j = 0; j < m; j++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			g[u][v] = g[v][u] = w;
		}
			
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					g[i][j] = g[j][i] = min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		
		int best = 1<<20,idx = 0;
		for(int j = 0; j < n; j++){
			int sum = 0;
			bool k = false;
			for(int i = 0; i < n; i++){
				if (g[i][j] != 1<<20)
					sum += g[i][j];
			}
			if (!sum) continue;
			if(sum < best){
				idx = j;
				best = sum;
			}
		}
		printf("Case #%d : ",r);
		cout<<s[idx]<<endl;
		
	}
	
	return 0;
}
