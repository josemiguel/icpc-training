#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){

	int n,m;

	cin >> n >> m;
	int g[102][102], de[102];
	memset(g,0,sizeof g);
	memset(de,0,sizeof de);
	for(int i = 0; i < m; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		g[u][v]= 1;
		g[v][u]= 1;
		de[u]++;
		de[v]++;
	}
	int res = 0;
	bool entro = true;
	while( entro ){
		entro = false;
		vector< int >  us;
		vector< vector < int > > tmp ( n );
		for(int u = 0; u < n; u++){
			if ( de[ u ] == 1 ){
				us.push_back(u);
				for(int i = 0; i < n; i++){
					if ( u == i) continue;
					if ( g[i][u] || g[u][i] ){
						tmp[u].push_back(i);
					}
				}
				entro = true;
				de[ u ] = 0;
			}
		}
		if ( entro ) {
			for(int j = 0; j < us.size(); j++){
				int u = us[ j ];	
				for(int i= 0;i < tmp[ u ].size();i++){
					int k = tmp[u][i];
					g[k][u] = g[u][k] = 0;
					de[k]--;
				}	
			}
			res++;
		}

	}

	cout << res << endl;


	return 0;
}
