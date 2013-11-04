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
	long long l,u,best,pos,s,n;
	while(scanf("%lld %lld",&l,&u) && l+u){
		best = 1,pos = l;
		if (l > u) swap(l,u);
		for(long long i = l; i <= u; i++){
			s = 0;
			n = i;
			do{
				s++;
				if (n%2) n = 3*n+1,s++;
				n /=2;
				if (s > best){
					best = s;
					pos = i;
				}
			}while(n!=1);

		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,u,pos,best);
	}
	return 0;
}
