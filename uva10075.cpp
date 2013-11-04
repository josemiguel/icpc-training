#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30
int g[105][105];
int n,m,q;

double	r = 6378;
double pi = 3.141592653589793;
struct geo
{
    double lat, lon;
    geo(double lat1, double lon1)
    {
        lat = (pi*lat1)/180;
        lon = (pi*lon1)/180;
    }
};

double geoDistance(geo a, geo b){
    return acos(sin(a.lat)*sin(b.lat)+cos(a.lat)*cos(b.lat)*cos(fabs(a.lon-b.lon)))*r;
}

int main(){
	for(int rr = 1 ; cin>>n>>m>>q && n+m+q ; rr++){
		if (rr!=1) putchar(10);
		string s,u,v;
		double x[105],y[105];
		map<string,int> h;
		
		for(int i = 0; i < 105; i++) 
			for(int j = 0; j < 105; j++) 
				if (i == j) g[i][j] = 0;
				else g[i][j] = 1<<20;
		
		for(int i = 0; i < n; i++){
			cin>>s>>x[i]>>y[i];
			h[s] = i;
		}

		for(int i = 0; i < m ; i++){
			cin>>u>>v;
			int uu = h[u], vv = h[v];
			geo xx(x[uu],y[uu]);
			geo yy(x[vv],y[vv]);
			g[h[u]][h[v]] = round(geoDistance(xx,yy));
		}
		
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					g[i][j] = min(g[i][j],g[i][k] + g[k][j]);


		printf("Case #%d\n",rr);

		while(q--){
			cin>>u>>v;
			int uu = h[u], vv = h[v];
			if (g[uu][vv] && g[uu][vv] != 1<<20){
				int dist = g[uu][vv];
				printf("%d km\n",dist);
			}else{
				puts("no route exists");
			}
		}
	}
	
	return 0;
}
