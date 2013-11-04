#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
char g[200][200];

int main(){
	int r;
	cin>>r;
	while(r--){
		cin>>n>>m>>q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>g[i][j];
			}
		}
		for(int k = 0; k < q; k++){
			cin>>x>>y;
			char ant = g[x][y];
			for(int i = x; i >= 0; 
			
		}
		cout<<n<<m<<q;
	}
	return 0;
}
