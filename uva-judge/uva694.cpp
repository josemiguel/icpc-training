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

int main(){
	long long n,l;
	for(int r = 1; scanf("%lld %lld",&n,&l) && n>0 && l > 0;r++){
		int s = 1;
		long long nn = n;
		do{
			if (n%2) {
				n = 3*n+1;
				if (n > l) break;
			}
			else n /=2;
			s++;

		}while(n!=1);

		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",r,nn,l,s);
	}
	return 0;
}
