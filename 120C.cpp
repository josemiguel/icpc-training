#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
pair<int,int> a[105];
int b[105];
bool cagao[105];
bool f(int &n,int &k){
	for(int i = 0; i < n; i++){
		if (a[i].first) return true;
	}
	return false;
}

int main(){

	#ifdef DEBUG
	freopen("std.in", "r", stdin);
	freopen("std.out", "w", stdout);
	#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;
	for(int i = 0; i < n; i++) cin>>a[i].first, a[i].second = i+1;
	int res = 0;
	while(f(n,k)){
		sort(a,a+n);
		if (b[a[n-1].second] == 3 || a[n-1].first < k) {
			res += a[n-1].first;
			a[n-1].first = 0;
		}else{
			a[n-1].first -= k;
			b[a[n-1].second]++;
		}
	}
	cout<<res<<endl;	

	return 0;

}
