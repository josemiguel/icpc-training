#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std ;
int dp[2005][2],a[2004];
int n,runs;
void F(bool k){
	for(int i = 0; i <n ; i++){
		int res = 0;
		for(int j = 0 ; j < i; j++){
			if ( a[j] > a[i] == k){
				if ( dp[j][k] > res){
					res = dp[j][k];
				}

			}


		}
		dp[i][k] = res + 1;
	}
}

int main(){

	cin >> runs;
	while(runs--){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		reverse(a,a+n);
		F(0);
		F(1);
		int res = 0;
		for(int i = 0; i < n; i++){
			res = max(res, dp[i][0]+dp[i][1]-1);

		}
		cout << res <<endl;

	}
}
