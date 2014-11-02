#include<cstdio>

using namespace std;

#define MAX 5000002

bool prime[MAX];
int dp[MAX];

int main(){
	int a,b;
    for(int i = 2; i*i < MAX; i++)
        if(!prime[i]) for(int j = i+i; j < MAX; j+=i) prime[j] = 1;
    
	for(int i = 2; i < MAX; i++){
        if(!prime[i]) for(int j = i; j < MAX; j+=i) dp[j] += i;
        if (!prime[dp[i]]) dp[i] = dp[i-1] + 1;
		else dp[i] = dp[i-1];
    }

	while(scanf("%d %d",&a,&b) && a){
		printf("%d\n",dp[b]-dp[a-1]);
	}
	return 0;
}
