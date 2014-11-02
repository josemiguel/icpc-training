#include<cstdio>
using namespace std;

typedef long long ll;

void M(ll &A,ll &B,ll &C,ll &D,ll a,ll b,ll c,ll d, int m) {
	ll w,x,y,z;
	w = A; x = B ; y = C;z = D;
	A = (a*w + b*y) % m;
	B = (a*x + b*z) % m;
	C = (c*w + d*y) % m;
	D = (c*x + d*z) % m;
}

ll F(ll n, int m) {
	ll a,b,c,d,w,x,y,z;
	a = b = c = w = x = y = 1;
	d = z = 0;
	while(n){
		if (n%2) M(a,b,c,d,w,x,y,z,m);       
		M(w,x,y,z,w,x,y,z,m);
		n >>= 1;
	}
	return b;
}

int main(){
	ll n,m;
	int pot[22];
	pot[0] = 1;
	for(int i = 1; i <= 20; i++) pot[i] = pot[i-1] << 1;
	
	while(scanf("%lld%lld",&n,&m) != -1){
		if (!n || !m) { printf("0\n"); continue; }
        if (n == 1) { printf("1\n"); continue; }	
        printf("%lld\n",F(n-1,pot[m]));
	}
	return 0;
}
