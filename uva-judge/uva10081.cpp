#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long Int;
int ___abs(int x, int y){
	int dif = x-y;
	return dif < 0 ? -dif : dif;
}
int k,n;
double dp[10][105];
double F(int last, int pos){
	
	if (pos == n) return 1.0/(k+1);
	if (dp[last][pos] > 0.0) return dp[last][pos];
	double res = 0;
	for(int id = 0; id <= k ; id++){
		if (___abs(id,last) > 1) continue;
		res += F(id,pos+1);
	}
	return dp[last][pos] = res/(k+1);
}

int main(){
	while(scanf("%d %d",&k,&n)!=-1){
		memset(dp,-1,sizeof dp);
		double res = 0.0;	
		for(int i = 0; i <= k; i++) res += F(i,1);	
		printf("%.5lf\n",res*100);

	}

}
