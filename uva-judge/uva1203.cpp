#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

pair<int,int> v[ 1001 ] , p[ 50005 ];
int main(){
    char s[ 30 ];
    int x, y, m = 1 << 30, sz = 0, K, tope, N = 0;
    while( scanf("%s",s) && s[0] != '#' ){
        scanf("%d %d",&x,&y);
        v[ N++ ] = make_pair( y, x ) ;
         m = y < m ? y : m;
    }
    scanf("%d",&K);
    tope = m * K;
    for( int i = 0; i < N; i++){
        if ( v[i].first > tope ) continue;
        for( int tmp = v[ i ].first ; tmp <= tope ; tmp += v[ i ].first ){
            p[ sz++ ] = ( make_pair( tmp, v[i].second ) );
        }
    }
    sort( p , p + sz );
    for( int i = 0; i < K; i++){
        printf("%d\n",p[i].second);
    }

    return 0;
}
