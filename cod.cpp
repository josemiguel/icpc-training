#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std ;

bool g[ 50 ][ 50 ];

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

vector< vector<pair<int,int>  > >  adj;
void insert( int u, int v, int w ){
	adj[u].push_back( make_pair( v, w ) ) ;
}

const int INF = 0x3fffffff;

int bf( int dest ){
  vector <int> cnt(adj.size(), 0);
    queue <int> q;
    vector <bool> inQ(adj.size(), false);
    vector< int> d( adj.size() );
    fill(d.begin(), d.end(), INF);
    d[0] = 0;
    q.push(0);
    inQ[0] = true;
    while(! q.empty()) {
        int n = q.front();
        q.pop();
        inQ[n] = false;
        for(size_t i=0; i<adj[n].size(); ++i) {
            int a = adj[n][i].first;
            int w = adj[n][i].second;
            if(d[a] > d[n] + w) {
                if(a == 0) {
                    return -INF;
                }
                d[a] = d[n] + w;
                ++cnt[a];
                if(! inQ[a] && cnt[a] < adj.size()) {
                    q.push(a);
                    inQ[a] = true;
                }
                if(cnt[a] >= adj.size()) {
                    return -INF;
                }
            }
        }
    }
    return d[dest];
}

int main(){
	int n,m,E,x,y,gg;
	while( scanf("%d%d",&n,&m)){
		if ( n == 0 && m == 0 ) break;
		adj = vector<vector<pair<int,int> > > ( n*m );
		memset( g, 0, sizeof g );

		scanf("%d",&gg);
		for( int i = 0; i < gg; i++){
			scanf("%d %d",&x,&y);
			g[x][y] = 1;
		}
		scanf("%d",&E);
		int xx,yy,W;
		for( int i = 0; i < E; i++ ){
			scanf("%d%d %d%d %d",&x,&y,&xx,&yy,&W);
			insert( x * m + y, xx * m + yy , W);
			g[x][y] = 2;
		}

		g[n-1][m-1] = 

		for( int i = 0; i < n; i++){
			for( int j = 0; j < m; j++){
			
				for( int k = 0; k < 4; k++){
					int x = i + dx[k];
					int y = j + dy[k];
					if ( x >= 0 && x < n && y >= 0 && y < m && g[x][y] != 1 ){
						insert( i * m + j , x * m + y , 1 );
					}
				}
			}
		}

		int xf = n-1,  yf = m-1;
		int fin  = xf * m + yf;

		int res = bf( fin);
		if ( res == -INF ) {
			printf("Never\n");
		}else if ( res == INF ){
			printf("Impossible\n");
		}else {
			printf("%d\n",res);
		}

	}

	return 0;
}
