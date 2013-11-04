#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std ;

typedef pair<int,int> pii;
int id[100][100];
int heat[100][100];
int che[100];

int main(){

	
	int runs,n,m;
	scanf("%d",&runs);
	while( runs-- ) {
		
		scanf("%d",&n );
		for( int i = 1; i <= n; i++){
			for( int j = 1; j <= n; j++){
				scanf("%d %d",&id[i][j],&heat[i][j]);
			}
		}
		scanf("%d",&m);
		
		for( int i = 0; i <= m; i++) {
			scanf("%d",che[i]);
			c[che[i]]++;
		}

		printf("%d\n",res); 
		char c;
		cin >> c;
	}

	return 0;
}
