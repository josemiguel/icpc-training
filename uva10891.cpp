#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 105
#define INF 1<<27
typedef long long ll;
ll dp[MAX][MAX];
ll a[MAX],n;

ll sum(int _a, int _b){
	ll res = 0;
	for(int i = _a; i <= _b; i++) res += a[i];
	return res;
}

ll F(int i, int j){
	if (j <= i) return 0;
	ll &res = dp[i][j];	
	if (res != -INF) return res;
	for(int k = 0; k <= j-i; k++){
		ll izq = sum(i,i+k) - F(i+k,j);
		ll der = sum(j-k,j) - F(i,j-k);
		res = max(res,max(izq, der));
	}
	return res;
}

int main(){

	while(cin>>n && n){
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) dp[i][j] = -INF;

		cout<<F(0,n-1)<<endl;
	}	
}

