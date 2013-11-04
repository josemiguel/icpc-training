#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>


using namespace std;

typedef long long Int;


int n , m;
Int a[200] , A[200] , b[ 200 ] , B[200];
Int c[200] , C[200];

Int G( Int id , Int cap , int ini , int fin ){
    Int sum = 0;
    repn( i , ini , fin + 1 ) if( id == B[ i ] ) sum += b[ i ];
    return min( cap , sum );
}

Int GO(){
    memset( c , 0 , sizeof c );
    memset( C , 0 , sizeof C );
    cin >> n >> m;
    for( int i = 0; i < n; i++)cin >> a[ i ] >> A[ i ];
	   for( int i = 0; i < m; i++)cin >> b[ i ] >> B[ i ];
    int k = 0;
      for( int i = 0; i < n; i++){
        int j = i;
        while( j < n and A[ i ] == A[ j ] ){
            c[ k ] += a[ j ]; j++;
        }
        C[ k++ ] = A[ i ];
        i = j - 1;
    }


    Int ans=0;
    if( k == 1 ){
        Int sum = 0;
            for( int i = 0; i < m; i++)if( C[ 0 ] == B[ i ] ){
            sum += b[ i ];
        }
        return min( sum , c[ 0 ] );
    }
    else if( k == 2 ){
        ans = max( G( C[ 0 ] , c[ 0 ] , 0 , m -1 ) 
            , G( C[ 1 ], c[ 1 ] , 0 , m - 1 ) );
        rep( i , m + 1 ){
            Int tmp = G( C[ 0 ] , c[ 0 ] , 0 , i - 1 ) 
            + G( C[ 1 ] , c[ 1 ], i , m - 1 );
            ans = max( ans , tmp );
        }
        return ans;
    }
    else{
        for( int i = 0; i < k; i++)ns = max( ans , G( C[ i ] , c[ i ], 0 , m - 1 ) );
        if( C[ 0 ] == C[ 2 ] ){ 
        ans = max( ans , G( C[ 0 ] , c[ 2 ] + c[ 0 ] , 0 , m - 1 ) );
        }
            for( int i = 0; i <= m; i++)
        rep( i , m + 1 ){
            for( int j = i; j <= m; i++)
                ans = max ( ans , 
                    G( C[ 0 ] , c[ 0 ] , 0 , i - 1 ) + 
                    G( C[ 1 ] , c[ 1 ] , i , j - 1) +
                    G( C[ 2 ] , c[ 2 ] , j , m - 1 ) );
            }
        }
        
        return ans;
    }
    return ans;
}

int main(){
    int test;
    cin >> test;
    rep( t , test ){
        printf("Case #%d: ", t + 1 );
        cout << GO() << endl;
    }
    return 0;
}
