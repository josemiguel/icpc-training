#include<cstdio>
#include<cstring>
#define CLR(x) memset((x),0,sizeof (x))
#define pb push_back
#define MAX 25050
#define max(x,y) (x) > (y) ? (x) : (y);
using namespace std;
char dic[MAX][30] = {0};
int N;

void step(char *a, char *b,char C, int pos, int op){

	if (op == 1){
		int i; for(i = 0; i < pos ;i++) b[i] = a[i];
		for(b[pos] = C; a[i] ; i++) b[i+1] = a[i]; b[i+1] = 0;
	}else if (op == 2){
		int i; for(i = 0; i < pos ;i++) b[i] = a[i];
		for(i = i + 1; a[i]; i++) b[i-1] = a[i]; b[i-1] = 0;
	}else{
		int i; for(i = 0; a[i]; i++) b[i] = a[i];
		b[pos] = C; b[i] = 0;
	}
}

int next(char *s){
	int lo = 0, hi = N;
	while(lo <= hi){
		int mid = (lo+hi)/2;
		int cmp = strcmp(dic[mid],s);
		if (!cmp) return mid;
		if (cmp < 0) lo = mid + 1;
		else hi = mid - 1;
	}
	return -1;
}

int dp[MAX];
int main(){
	N = 0;
	while(scanf("%s",dic[N]) != -1) N++;
	int res = 1; char b[30] = {0};
	for(int u = 0; u < N; u++){
		dp[u] = 1;
		for(int op = 1; op <= 3; op++){
			for(int pos = 0; dic[u][pos]; pos++) for(char C = 'a'; C <= 'z'; C++){
				step(dic[u],b,C,pos,op); if (strcmp(dic[u],b) <= 0) break;
				int v = next(b); 
				if (v != -1) dp[u] = max(dp[u], dp[v] + 1);
			}
		}
		res = max(dp[u],res);
	}
	printf("%d\n",res);
	return 0;
}
