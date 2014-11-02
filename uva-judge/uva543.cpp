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

bool isPrime(int n){
	if (n == 1) return false;
	for(int i = 2; i*i <= n; i++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int nextPrime(int n){
	for(int i = n-1; i >= 3; i--){
		if (isPrime(i)){
			return i;
		}
	}
	return 2;	
}

int main(){
	int n;
	while(scanf("%d",&n)!=-1 && n){
		int a,b;
		b = n;
		do{
			b = nextPrime(b);
			a = n - b;
		}while(!isPrime(a));
		printf("%d = %d + %d\n",n,a,b);
	}
	return 0;
}
