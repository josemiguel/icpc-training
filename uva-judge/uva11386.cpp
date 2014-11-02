#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std ;
typedef long long Int;
Int a[ 5005 ];
Int b[ 5005 ];
int f[ 5005 ];
int main(){

	int n;
	while( scanf("%d",&n)!=-1){
		for( int i = 0; i < n; i++){
			scanf("%lld",a+i);
		}
		sort( a, a + n );
		int j = 0, N = 0;
		for(int i = 0; i < n;  ){
			b[ N ] = a[ i ];
			while( a[ j ] == a[ i ] && j < n) j++;
			f[ N ] = j - i  ;
			N++;
			i = j;
		}


		Int res = 0;
		for( int i = 1 ; i < N ; i++){
			int j = 0, k = i - 1;
			while( j <= k ){
				if ( b[ j ] * 2 == b[ i ] ){
					res += f[ i ] * (f[ j ] * (f[ j ] - 1)) / 2;
					break;
				}
				if ( b[ k ] * 2 == b[ i ] ){
					res += f[ i ] * (f[ k ] * (f[ k ] - 1)) / 2;
					break;
				}
				if ( b[ k ] + b[ j ] == b[ i ] ){
					res += f[ i ] * f[ j ] * f[ k ];
					j--; k--;
				}else if ( b[ k ] + b[ j ] > b[ i ] ) k--;
				else j++;
			}
		}
		printf("%lld\n" , res );
	
	}

	return 0;	

}


