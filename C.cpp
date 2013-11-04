#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;

#define Int long long
#define MAX 105
#define tope 10000005

Int C[MAX + 5][MAX + 5];


int H[tope];

void pre(){
	memset( H , -1, sizeof H );

	H[ 1 ] = 1;
    for(int i = 0; i < MAX; i++) C[i][i] = C[i][0] = 1;
   
    for(int i = 1; i < MAX; i++) 
    	for(int j = 1; j < i; j++){   
	        C[i][j] = C[i-1][j-1] + C[i-1][j];
	        if( C[i][j] < tope && C[i][j] >=0 && H[ C[i][j] ] == -1) H[C[i][j]] = i;
		}
		
   for( int i = 1; i < tope; i++ ) if ( H[ i ] == -1 ) H[ i ] = i;
}
int main(){
   
    pre();
    int runs;
	cin>>runs;

	for(int r = 1; r <= runs; r++){
		Int S;
		cin >> S;
		int res = 1<<30;
		for( Int i = 1LL; i <= S; i++){
			if ( S % i ) continue;
			int N = H[ i ];
			int M = H[S / i];
			if ( N == -1 || M == -1 ) 	continue;
			res = min( res, N + M );
		}
		
		printf("Case #%d: %d\n",r, res);

	}
	return 0;



}
