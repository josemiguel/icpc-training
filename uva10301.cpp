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
#define MAX 1000

int n,m;
struct punto
{
    double x,y;
    punto(double x=0, double y=0):x(x), y(y){}

};
struct circle{
	double x,y,r;
	punto centro;
	circle(){}
	circle(double x, double y, double r):x(x),y(y),r(r){centro.x = x, centro.y = y;}
};
double dst(punto a, punto b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int id[100010];

int Find(int n)
{
    if (id[n] < 0) return n;
    return id[n] = Find(id[n]);
}

int Union(int x, int y){
    if (x == y){
        return -id[x];
	}
    if (id[x] < id[y]) {
        id[x] += id[y];
        id[y] = x;
        return -id[x];
    }
    else{
        id[y] += id[x];
        id[x] = y;
		return -id[y];
    }
}


int main(){
	for(int r = 1 ; scanf("%d",&n) && n!=-1 ; r++){
		vector<circle> cs;
		if (n == 0) {printf("The largest component contains %d rings.\n",0);continue;}
		for(int i = 0 ; i < n ;i++){
			punto p;
			double x,y,r;
			scanf("%lf %lf %lf",&x,&y,&r);
			cs.push_back(circle(x,y,r));
		}
		int largest = 1;
		memset (id,-1,sizeof(id));

		for(int i = 0; i < n - 1; i++){
			for(int j = i + 1; j < n; j++){
				double d = dst(cs[i].centro,cs[j].centro);
				double r1 = cs[i].r, r2 = cs[j].r;
				if(r1+r2>d && r1+d>r2 && r2+d>r1){
					int x = Union(Find(i),Find(j));
					largest = max(largest,x);

				}
			}
		}

		if (largest != 1)
			printf("The largest component contains %d rings.\n",largest);
		else
			printf("The largest component contains %d ring.\n",largest);
	}
	
	return 0;
}
