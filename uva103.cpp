#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define REPN(i,a,N) for(int i = a ; i < N; i++)
#define REP(i,N) REPN(i,0,N)
#define MAX 35
#define All(x) (x).begin(),(x).end()
using namespace std;
int n,m;
struct box{
	int d[20];
	int id;
	box(){}
};

bool operator <(const box &A, const box &B){
	REP(i,m) if (A.d[i] <= B.d[i]) return false;
	return true;
}

box a[MAX];
int dp[MAX], pai[MAX], path[MAX], ptr;

void track(int u){
	if (u == pai[u]) return;
	track(pai[u]);
	path[ptr++] = a[pai[u]].id;
}

int main(){
	while(scanf("%d%d",&n,&m)==2){
		ptr = 0;
		REP(i,n){
			REP(j,m) scanf("%d",&a[i].d[j]);
			sort(a[i].d,a[i].d+m);
			a[i].id = i+1;
		}
		int res = 0, fin = 0;
		REP(i,n-1) REPN(j,i+1,n) if (a[i] < a[j]) swap(a[i],a[j]);
		REP(i,n) pai[i] = i;
		res = dp[0] = 1;
		REPN(i,1,n){
			dp[i] = 1;
			REPN(j,0,i){
				if(a[i] < a[j] && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					pai[i] = j;
				}
			}
			if (res < dp[i]){
				res = dp[i];
				fin = i;
			}
		}
		track(fin);
		path[ptr++] = a[fin].id;
		printf("%d\n",res);
		REP(i,ptr){
			if (i) printf(" %d",path[i]);
			else printf("%d",path[i]);
		}
		putchar(10);
	}	
	return 0;
}
