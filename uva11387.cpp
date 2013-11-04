#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){

	int n ;

	while( cin >> n && n ){
		int usd[n+1];
		memset(usd, 0,sizeof usd);
		int g[n+1][n+1];
		for(int i = 1; i <= n ; i++){
			for(int j = i + 1; j <= n; j++){
				if (usd[i] == 3) break;
				usd[i]++;
				usd[j]++;
				g[i][j] = g[j][i] = 1;
			}
		}
		for(int i = 1; i <= n; i++){
			if (usd[i] != 3){
				cout << "Impossible" << endl;
				goto hell;
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if  (g[i][j] ){
				
					cout << i << " " << j <<endl;
				}
			}
		}

		hell:;
	}

	return 0;
}
