#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int buck[ 205 ][ 30 ];
char t[ 10005 ];

int main(){
	int runs;
	scanf("%d",&runs);
	while(runs--){
		int n ,m ,k; 
		scanf("%d%d%d%s",&n,&m,&k,t);
		string s( t );
		memset( buck ,0 ,sizeof buck );
		for( int i = 0; i < n - m + 1 ; i++){
			string it = s.substr( i , m )  ;
			for( int i = 0; i < m; i++ ){
				buck[ i ][ it[i] - 'a' ]++;
			}
		}
		for( int i = 0; i < m; i++ ){
			int l , coge = 1 << 20;
			for( int j = 0; j < k; j++){
				if ( buck[ i ][ j ] < coge ){
					coge = buck[ i ][ j ];
					l = j;
				}
			}
			putchar(l+'a');
		}
		putchar(10);

	}

	return 0;
}
