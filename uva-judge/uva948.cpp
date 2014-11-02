#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 500
typedef long long ll;
int b[MAX+5];
ll F[MAX+5];

int search(ll n){
	int pos;
	for(pos = 0; n >= F[pos]; pos++);
	return pos - 1;
}

int main(){
	F[0] = 0;
	F[1] = F[2] = 1;
	for(int i = 3; i <= MAX; i++) F[i] = F[i-1] + F[i-2];
	int r;
	scanf("%d",&r);
	while(r--){
		ll n,N;
		scanf("%lld",&N);
		if (N == 0LL) { puts("0 = 0 (fib)"); continue;}
		n = N;
		memset(b,0,sizeof b);
		int last = 0, f = 0;
		int i = 0;
		while(n){
			int k = search(n);
			n -= F[k];
			b[k] = 1;
			if (!f) last = k, f = 1;
		}
		printf("%lld = ",N);
		for(int i = last; i >= 2; i--) printf("%d",b[i]);
		printf(" (fib)\n");
	}
	return 0;
}
