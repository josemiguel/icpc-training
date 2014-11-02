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
int n,m;

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		double r;
		scanf("%lf",&r);
		double m[4],n[4];;
		for(int i = 1; i <= 3; i++){
			scanf("%lf %lf",&m[i],&n[i]);
		}

		double a, b, c;

		a = m[1] + n[1];
		b = n[1] + n[1]*n[2] / m[2];
		c = m[1] + m[3]*m[1] / n[3];

		double p = (a+b+c)/2;
		double S = sqrt(p*(p-a)*(p-b)*(p-c));


		double rr = S/p;
		double B = (S*(r*r))/(rr*rr);
		printf("%.4lf\n",B);
		
	}
	
	return 0;
}
