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
int n,m;

int divisores(int n){
	int res = 1;
	for(int i = 2; i*i <=n; i++){
		int d = 0;
		while(n%i == 0){
			n /= i;
			d++;
		}
		res *= (d+1);
	}
	if (n > 1) res *= 2;
	return res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		scanf("%d%d",&n,&m);
		int best = 0;
		int res;
		for(int i = n; i <= m; i++){
			int dv = divisores(i);
			if (dv > best){
				best = dv;
				res = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",n,m,res,best);
	}
	
	return 0;
}
