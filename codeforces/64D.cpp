#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > g, w;
bool usd[ 100005 ];
int x ;
int f( int u ){
    usd[ u ] = true;
    int res = 0;
    for( int i = 0; i < g[u].size(); i++){
        if ( usd[ g[u][i] ]) continue;
        res += w[u][i] + f( g[u][i] );
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    g = w = vector<vector<int> > (n);
    memset( usd, 0, sizeof usd);
    int sum = 0;
    for( int i = 0; i < n - 1; i++){
        int u,v,p;
        cin >> u >> v >> p;
        u--,v--;
        g[u].push_back( v );
        g[v].push_back( u );
        w[u].push_back( p );
        w[v].push_back( p );
        sum += p;
    }
    cout << 2 * sum - x << endl;
}
