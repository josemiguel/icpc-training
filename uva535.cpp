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
#define MAX
//int g[MAX][MAX];
//vector<vector<int> > g;
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

double dist(double lat1,double lon1,double lat2,double lon2) {

	double dlon = lon2 - lon1;
	double dlat = lat2 - lat1;
	double a = pow((sin(dlat/2)),2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double d = r * c;

	return d;
} 

double geoDistance(geo a, geo b){
    return dist(a.lat,a.lon,b.lat,b.lon);
}

int main(){
	string s;
	map<string,pair<double,double> > g;
	while(cin>>s && s!="#"){
		double x,y;
		cin>>x>>y;
		g[s] = mp(x,y);
	}
	string a,b;
	while(cin>>a>>b){
		if (a=="#" && b=="#") break;
		cout<<a<<" - "<<b<<endl;

		if (g.find(a) == g.end() || g.find(b) == g.end()){
			printf("Unknown\n");
			continue;
		}	
		geo x(g[a].first,g[a].second);
		geo y(g[b].first,g[b].second);
		double km = geoDistance(x,y);

		printf("%d km\n",(int)round(km));
	}
	
	
	
	return 0;
}
