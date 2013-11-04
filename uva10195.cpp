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

//int g[MAX][MAX];
//vector<vector<int> > g;


int main(){
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=-1){
		if( a <= 0 || b <= 0 || c <= 0){
			printf("The radius of the round table is: 0.000\n");
			continue;
		}
		double s = (a+b+c)/2;
		double r = sqrt(s*(s-a)*(s-b)*(s-c))/s;
		
		printf("The radius of the round table is: %.3lf\n",r);
	}
	
	return 0;
}
