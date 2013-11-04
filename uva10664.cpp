#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(i,n) for(int i = 0; i < n; i++)
using namespace std;
int a[20],dp[205],n;
bool res;

int main(){
	
	int r;
	scanf("%d\n",&r);
	
	while(r--){
		char c;
		memset(dp,-1,sizeof dp);n = 0;
		while(1) { scanf("%d%c",&a[n],&c);n++; if (c == '\n') break; }
		int s=0;
		f(i,n) s+=a[i];
		if (s%2) { cout<<"NO"<<endl; continue;}
		res = false;
		
		for(int i=0; i < s+10; i++) dp[i]=0;
		dp[0] = 1;
		for(int i=0; i < n; i++)
			for(int j=s/2; j >= a[i]; j--)
				dp[j] |= dp[j-a[i]];
		
		
		
		if (dp[s/2]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
