#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX 1000003

int F(int n){
	int res = 0;
	while(n){
		res += n%10;
		n/=10;
	}
	return res;
}
vector<bool> b(MAX,true);
int dp[MAX];

void criba(){
	b[0] = b[1] = false;
	for(int i = 2; i*i <= MAX; i++){
		if (b[i]){
			for(int j = i*i; j <= MAX; j+=i) b[j] = false;
		}
	}
	//memset(dp,0,sizeof dp);
	for(int i = 2; i <= MAX; i++) dp[i] = dp[i-1] + (b[F(i)] && b[i]);
	
}


int main(){
	ios_base::sync_with_stdio(false);
	int r;
	criba();
	cin>>r;
	while(r--){
		int der,izq;
		cin>>izq>>der;
		cout<<dp[der] - dp[izq-1]<<endl;
	}
	return 0;
}

