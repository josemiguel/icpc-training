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

typedef long long Int;
Int n;
#define MAX 1000005
map<Int,Int> p;

void criba(){
	p[0] = p[1] = 1;
	for(int i = 4; i < MAX; i+=2) p[i] = 2;
	for(int i = 3; i*i < MAX; i+=2){
		if (p[i]) continue;
		for(int j = i*i; j < MAX; j+=(i<<1)) p[j] = i;
	}
}


int main(){
	Int runs;
	criba();
	scanf("%lld",&runs);
	for(Int r = 1 ; r <= runs ; r++){
		scanf("%lld",&n);
		printf("%lld =",n);
		map<Int,Int> res;
		while(p[n]){
			res[p[n]]++;
			n /= p[n];
		}
		if ( n != 1 ) res[n]++;
		int k = 0;
		for(map<Int,Int>::iterator it = res.begin(); it != res.end(); it++){
			if (k) printf(" *"); k = 1;
			if (it->second > 1){
				printf(" %lld^%lld", it->first, it->second);
			}else{
				printf(" %lld", it->first);
			}
			
		}
		
		putchar(10);
	}

	return 0;
}
