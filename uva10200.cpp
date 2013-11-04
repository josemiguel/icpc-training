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
#define MAX2 100010041
#define MAX 1000


vector<bool> prime(MAX,true);
vector<char> prime2(MAX2,-1);

void sieve(){
	prime[0] = false;
   	prime[1] = false;
   	for(int i = 2; i*i <= MAX; i++)
   		if(prime[i])
        	for(int j = i*i; j <= MAX; j += i)
            	prime[j] = false;
}

int isPrime(int n){
	if (n == 1) return false;
	for(int i = 2; i*i <= n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n,m;
	sieve();
	while(scanf("%d%d",&n,&m)!=-1){
		int d = m-n+1, s = 0;
		for(int i = n; i <= m; i++){
			int fu = i*i + i + 41;
			if (fu > MAX){
				if (prime2[fu] == -1)
					prime2[fu] = isPrime(fu);
				s += prime2[fu];
			}else{
				s += prime[fu];
			}
		}
		double t = (s*100*100) / (double)d;
		printf("%.2lf\n",round(t)/100.00);
	}
	
	return 0;
}

