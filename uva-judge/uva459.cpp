/*
*
*	UVA 459 AC
*
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define N 32


int n;
vector<vector<int> > g;
int visited[N];


inline int in(int x, int y){
	return x>=0 && y>=0 && x<n && y<n;	
}

void dfs(int u){
	visited[u] = 1;
	for(int i = 0 ; i < g[u].size() ; i++){
		int v = g[u][i];
		if (!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	int runs;
	cin>>runs;
	cin.ignore();//es como hacer un fflush
	string par;
	getline(cin,par);
	for(int r = 1 ; r <= runs; r++){
		memset(visited,0,sizeof(visited));
		while(getline(cin,par) && par!=""){
 			if (par.size() == 1){
				n = par[0] - 'A' +1;
				g = vector<vector<int> > (n);			
			}else{
				if (par.size() == 2){
					g[par[0]-'A'].push_back(par[1]-'A');
					g[par[1]-'A'].push_back(par[0]-'A');			

				}
			}
		}
		int cmp = 0;
		for(int u = 0 ; u < n ; u++){
			if (!visited[u]){
				dfs(u);
				cmp++;
			}
		}
		printf("%d\n",cmp);
		if (r != runs) putchar(10);
	}
	return 0;
}
