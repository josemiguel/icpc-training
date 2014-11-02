#include<cstdio>


#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;
#define MAX 10005
int n;int d[MAX];
int sd[MAX];
bool f() {
	if (accumulate(d, d+n, 0) % 2 == 1) return false;
	sort(d, d+n, greater<int>()); copy(d, d+n, sd);
	for(int i = 0; i < n; i++) sd[i+1]+=sd[i];
	for(int i = 0 ; i < n; i++){
		if (d[i] < 0) return false;
		int j = lower_bound(d+i+1, d+n, i+1, greater<int>()) - d;
		if (sd[i] > i*(i+1) + sd[n-1] - sd[j-1] + (j-i-1)*(i+1)) return false;
	}
	return true;
}


int main(){
	while(scanf("%d",&n) && n){

		for(int i = 0; i < n; i++) {	
			scanf("%d",d+i);
		}
		bool res = f();
		puts( res ? "Possible" : "Not possible");
		
	}
	return 0;
}
