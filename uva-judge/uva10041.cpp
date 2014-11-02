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
		scanf("%d",&n);
		int a[550];
		for(int i = 0; i < n ; i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int mid = a[n/2 - !(n%2)];
		int s = 0;
		for(int i = 0; i < n; i++){
			s += abs(mid - a[i]);
		}
		
		printf("%d\n",s);
	}
	
	return 0;
}
