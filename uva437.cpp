#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[31][3];

int dp[31][3];
int n ;
int F(int pos, int cara){
	
	int &res = dp[pos][cara];
	if (res != -1) return res;
	res = 0;
	
	int last = a[pos][cara];

	int bx = a[pos][(cara + 1) % 3];
	int by = a[pos][(cara + 2) % 3];

	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			if (bx > a[i][j] && by > a[i][(j+1)%3]){
				res = max( res, F(i,(j+2)%3) + a[i][(j+2)%3]);		
			}
			
			if (by > a[i][j] && bx > a[i][(j+1)%3]){
				res = max( res, F(i,(j+2)%3) + a[i][(j+2)%3]);		
			}
		}
		

	}
	return res;

}



int main(){
	int r = 1;
	while ( scanf("%d", &n) && n ){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset( dp, -1, sizeof dp );
		int res = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				res = max(res, a[i][j] + F(i,j));	
			}
		}
		printf("Case %d: maximum height = %d\n",r++,res);
		
	}

	return 0;
}
