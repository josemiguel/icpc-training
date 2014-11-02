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

long long largestDivisor(long long n){
	long long best = -1;
	long long c = 0;
	for(long long i = 2; i*i <= n; i++){
		long long a = 0;
		while(n % i == 0){
			n /= i;
			a++;
		}
		if (a) c++,best = max(best,i);
	}
	if (n > 1)	c++,best = max(best,n);
	if (c > 1)
		return best;
	return -1;
}

int main(){
	long long n;

	while(scanf("%lld",&n)!=-1 && n){
		printf("%lld\n",largestDivisor(n<0?-n:n));
	}
	
	return 0;
}

