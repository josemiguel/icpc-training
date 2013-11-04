#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 12;

int main(){
	int runs;
	scanf("%d\n",&runs);
	for(int r = 0; r < runs; r++){
		char s[15];
		gets(s);
		int u = 0;
		for(int i = 0; i < N; i++) 
			if ( s[i] == 'o') u |= (1<<i);
		for(int i = 0; i < (1<<N); i++) dp[i] = 1<<30; 
		dp[0] = u;
		for(int mask = 0; mask < (1<<N); mask++){
			for(int i = 0; i < N-2; i++){
			}
		}
		cout<<dp[(1<<N)-1]<<endl;
	}
}
