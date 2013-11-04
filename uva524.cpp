#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;


bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                    0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                    0, 1, 0, 0, 0, 0, 0, 1, 0, 0};

int res[17];
bool seen[17];
int m;
int runs;
void solve(int curr, int n, int r){
	if (r == 0 && prime[res[0]+res[n-1]]){
		printf("%d",res[0]);
		for(int i = 1; i < n ; i++){
			printf(" %d",res[i]);
		}
		putchar(10);
	}else{
		for(int i = 1; i<= n; i++){
			if (curr == i || seen[i] || !prime[curr+i]) continue;
			seen[i] = true;
			res[m++] = i;
			r--;
			solve(i,n,r);
			r++;
			m--;
			seen[i] = false;
		}
	}
}

int main(){
    int n;
    int c=1;
    runs = 1;
    while(scanf("%d",&n)!=-1){
    	if (runs!=1) putchar(10);
    	printf("Case %d:\n",runs++);
		if (n&1) continue;
		memset(seen,0,sizeof(seen));
		m = 1;
		seen[1] = true;
		res[0] = 1;
		solve(1,n,n-1);
    }
}
