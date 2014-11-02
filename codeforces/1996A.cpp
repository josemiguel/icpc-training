#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int g[100+4][100+4];

int main(){
	int n;
	int c=1;
	while(scanf("%d",&n) && n){
		map<string,int> M;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			M[s]=i;
		}
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			string a,b;
			int w;
			cin>>a>>w>>b;
			g[M[a]][M[b]]=w;
			g[M[b]][M[a]]=w;
		}
		bool t = false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if (g[i][j]!=0 && g[i][k]+g[k][j]!=0){
						g[i][j]*=g[i][k]*g[k][j];
						if (g[i][j]>0){
							t = true;
							goto A;
						}
					}
				}
			}
			
		}
A:		printf(t?"Case %d: Yes":"Case %d: No",c++);
	}
	

}
