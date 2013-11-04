#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;

ll pot[] = {1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,
			100000000LL,1000000000LL,10000000000LL,100000000000LL,
			1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL,
			10000000000000000LL,100000000000000000LL,1000000000000000000LL};
			
int main(){
	int r;
	scanf("%d",&r);
	while(r--){
		ll N,K;	scanf("%lld %lld",&N,&K);
		set<ll> usd;
		while(!usd.count(K)){
			usd.insert(K);
			K *= K;
			int len = 1 + (int)log10(K);
			K = len > N ? K /= pot[len-N] : K;
		}
		printf("%lld\n",*usd.rbegin());
	}
}
