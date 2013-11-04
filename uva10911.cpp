#include<stdio.h>
#include<math.h>
#define MAX 16
#define min(x,y) (x)<(y)?(x):(y)
struct pii{
	int x, y;
	pii(){}
	pii(int x, int y): x(x), y(y){}
};

pii p[MAX];
double dp[1<<MAX];
int n,r;

double d(int i, int j){
	return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
}

double F(int mask){
	double &res = dp[mask];
	
	if ((1<<n)-1 == mask) return 0;
	if (res != 1e10) return res;
	
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if (mask>>i & 1 || mask>>j & 1) continue;
			res = min(res,d(i,j) + F(mask | (1<<i) | (1<<j)));
		} 
	} 
	return res;
}

int main(){
	while(scanf("%d",&n) && n){
		int x,y;
		n <<= 1;
		for(int i = 0; i < (1<<n); i++) dp[i] = 1e10;
		for(int i = 0; i < n; i++){
			scanf("%*s %d %d",&x,&y);
			p[i] = pii(x,y);
		}
		printf("Case %d: %.2lf\n",++r,F(0));
	}
	return 0;
}
