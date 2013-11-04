#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <queue>
#include <numeric>
#include <cmath>
#define repn(a,x,y) for (int a=x; a<y; a++)
#define rep(a, n ) repn( a , 0 , n ) 
#define fd(a,x,y) for (int a=x; a>=y; a--)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define pb push_back
#define FOR(it,A) for (typeof A.begin() it=A.begin(); it!=A.end(); it++)
#define ones(x) __builtin_popcountll(x)
#define clr(A,x) memset (A, x, sizeof A)
#define oo (1<<30)
#define eps (1e-9)
#define cua(x) (x)*(x)
#define fst first
#define snd second
#define pii pair<int,int>
#define debug(x) cout << #x << " = " << x <<endl
typedef long long ll;
using namespace std;
#define MAX 10000005
int p[ MAX ];
int Fa[ MAX ], Fb[ MAX ];
int a[ 100005 ]; 
int b[ 100005 ];

void criba() {
    for( int i = 2; i * i < MAX ; i++){
        if (!p[i])
            for( int j = i * i ; j < MAX; j += i )  p[j] = i;
    }
    for( int i = 2; i < MAX; i++ ) if ( !p[i] ) p[i] = i;
}

void fact( int a[], int *F, int sz ) {
    for( int i = 0; i < sz; i++ ){
        int k = a[i];
        while ( k > 1 ) {
            F[ p[k] ] ++;
            k /= p[ k ];
        }
    }
}

void solve( int a[], int *F, int sz ) {

    for( int i = 0; i < sz; i++){
        int res = 1 ; 
	int k = a[i];
	while ( k > 1 ){
		if ( !F[p[k]] ) res *= p[k];
		else F[p[k]]--;
		k /= p[k];
	}
        if ( i ) putchar( ' ' );
        printf("%d", res );
    }
    putchar( 10 );

}

int main(){
    int n , m;
    criba();
    cin >> n >> m;
    rep( i , n ) cin >> a[i];
    rep( i , m ) cin >> b[i];

    cout << n << " " << m << endl;
    fact( a , Fa, n );
    fact( b , Fb, m );

    solve( a, Fb, n ); 
    solve( b, Fa, m ); 

    return 0;
}
