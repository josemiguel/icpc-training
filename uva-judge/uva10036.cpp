#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int a[10005],t[] = {1,-1};
int _abs(int n) { return n > 0 ? n: -n;}
int n,k;

map<int,int> dp[10005];

bool F(int u, int sum){
	if (u == n){
		if (sum % k == 0) return true;
		return false;
	}
	if (dp[u].count(_abs(sum))) return dp[u][_abs(sum)];

	bool res = false;
	for(int i = 0; i < 2; i++){
		if (res = F(u+1,(sum+t[i]*a[u])%k)) return true;
	}
	return dp[u][_abs(sum)] = res;
}

int main(){
	int runs;
	cin>>runs;
	while(runs--){
		cin>>n>>k;
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i < 10005;i++) dp[i].clear();
		if (F(1,a[0])){
			cout<<"Divisible"<<endl;
		}else{
			cout<<"Not divisible"<<endl;
		}
	}

	return 0;
}
