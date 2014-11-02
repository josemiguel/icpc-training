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

int n;

int main(){
	while(scanf("%d",&n)!=-1 && n){
		int G = 0;
		for(int i = 1; i < n; i++)
			for(int j = i+1; j <= n; j++)
				G+=__gcd(i,j);
		printf("%d\n",G);
	}
	
	return 0;
}
