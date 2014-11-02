#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
#define MOD 1000000007
typedef long long Int;
Int dp[( 1<<10 ) + 5][11][102][2];
int k,n,N;
Int F(int mask, int last, int pos,int S){//S-irve
	if (S) return mask == (1<<k)-1;
    if (pos == n) return 0;
    if (dp[mask][last][pos][S] != -1) return dp[mask][last][pos][S];
    Int res = 0LL, id;
    if (!S) {
		id = last - 1;
		if ( last > 0 ) 
			res = (res + F(mask | (1<<id), id, pos + 1, 0) % MOD) % MOD;
			res = (res + F(mask | (1<<id), id, pos + 1, 1) % MOD) % MOD;
		id = last + 1;
		if (last < k-1) 
			res = (res + F(mask | (1<<id), id, pos + 1, 0) % MOD) % MOD;
			res = (res + F(mask | (1<<id), id, pos + 1, 1) % MOD) % MOD;    	
    }
    return dp[mask][last][pos][S] = res % MOD;
    
}

int main(){
    int r; 
	scanf("%d",&r);
    while(r--){
        scanf("%d %d",&k,&n);
        if ( k > n) {
    	    printf("0\n");
        }else{
		    Int res = 0;
		   	memset(dp,-1,sizeof dp);        
		    for(int j = 1; j <= k-1; j++) res = (res + F(1<<j,j,1,0) % MOD) % MOD;
		    printf("%lld\n",res);
		}
    }
    
    
    return 0;    
}
