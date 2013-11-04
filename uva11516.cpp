#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAX 100010
int a[MAX];
int n,m,r;

bool p(double mid){
	int usd = 1;
	double fin = mid + a[0];
	for(int i = 1; i < m; i++){
		double dist = fabs(fin - a[i]);
		if (dist > mid){
			fin = a[i] + mid;
			usd++;
		}
	}
	return usd <= n;
}

int main(){
	scanf("%d",&r);
	while(r--){
		scanf("%d%d",&n,&m);
		if( !m || n == m ) { puts("0.0"); continue;	}
		for(int i = 0; i < m; i++) scanf("%d",&a[i]);
		int i = 0;
		sort(a,a+m);
		double hi = a[m-1] + 50, lo = 0;
		while(i++ < 25){
			double mid = (lo+hi)/2.0;
			if (p(mid)) hi = mid;
			else lo = mid;
		}
		printf("%.1lf\n",hi);
	}
	return 0;
}
