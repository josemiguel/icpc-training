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


long long n,k;

long long solve(long long n, long long k){
	long long t = n;
	while(n>=k){
		t+=(n/k);
		n=(n/k) + (n%k);
	}
	return t;
}

int main(){
	while(cin>>n>>k){
		cout<<solve(n,k)<<endl;
	}
	
	return 0;
}
