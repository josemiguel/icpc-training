#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
typedef long long Int;
Int a[1005],n,k;
bool p(int x){
	for(int i = 0; i < n; i++) if ( x < a[i]) return 0;
	Int ac = a[0];
	int ret = 1;
	for(int i = 1; i < n; i++){
		if ( ac + a[i] <= x ){
			ac += a[i];
		}else{
			ac = a[i];
			ret++;
		}

	}
	return ret <= k;
}

int main(){
	while(scanf("%lld %lld",&n,&k)!=-1){
		Int lo=0,hi=0;
		for(int i = 0; i < n; i++) scanf("%lld",a+i), hi += a[i];
	//	sort(a,a+n);
		while(lo < hi){
			Int mid = (lo+hi)/2;
			if (p(mid)){
				hi = mid  ;
			}else{
				lo = mid + 1;
			}
		}
		printf("%lld\n",lo);
	}
	
	return 0;
}
