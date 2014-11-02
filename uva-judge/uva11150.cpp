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

int solve(int m, int n, int k, int b){
	if (n>=k) return (n/k) + solve(m,n/k + n%k,k,b);
	if (n < b) return -1;
	return m;
}
int main(){
	int n;
	while(scanf("%d",&n)!=-1){
		int best = 0;
		for(int i = 0; i <= 2 ; i++){
			best = max(best,solve(n,n+i,3,i));
		}
		printf("%d\n",best);
	}
	
	return 0;
}
