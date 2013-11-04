#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<sstream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cstdio>
#include<stack>
using namespace std;
#define MAX 1505
typedef long long ll;
struct chin{
	ll x, b;
	chin(ll a = 0, ll b = 0): x(a), b(b){}
	bool operator <(const chin& B) const{
		if(x != B.x) return x < B.x;
		return b < B.b;
	}
};

ll mod = 1000000007, mod2 = 433494437;

ll pot[11], pot2[11];

ll A[MAX], A2[MAX], B[MAX], B2[MAX];
ll len[MAX];
char s[11];
chin join[2500000]; int max_len;

int main(){
	pot[0] = pot2[0] = 1;
	for(int i = 1; i < 11; i++){
		pot[i] = pot[i - 1] * 27 % mod;
		pot2[i] = pot2[i - 1] * 27 % mod2;
	}

	int t; 
	scanf("%d", &t);
	for(int rr = 1; rr <= t; rr++){
		int n, m; 
		scanf("%d %d", &n, &m);gets(s);
		for(int i = 0; i < n; i++){
			gets(s);
			ll x = 0, b = 0;
			for(int j = 0; s[j]; j++){
				x = (x * 27 + (s[j] - 'a' + 1)) % mod;
				b = (b * 27 + (s[j] - 'a' + 1)) % mod2;
			}
	
			A[i] = x; 
			A2[i] = b;
		}
		for(int i = 0; i < m; i++){
			gets(s);
			len[i] = 0;
			ll x = 0, b = 0;
			for(int j = 0; s[j]; j++){
				x = (x * 27 + (s[j] - 'a' + 1)) % mod;
				b = (b * 27 + (s[j] - 'a' + 1)) % mod2;
				len[i]++;
			}
			B[i] = x; B2[i] = b;
		}
		
		max_len = 0;
		
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++){
				ll x = (A[i] * pot[len[j]] % mod + B[j]) % mod;
				ll b = (A2[i] * pot2[len[j]] % mod2 + B2[j]) % mod2;
				join[max_len++] = chin(x,b);
			}
			
		sort(join, join + max_len);
	
		int res = 0;
		for(int i = 0; i < max_len; ){
			int j = i + 1;
			while(j < max_len &&join[i].x == join[j].x && join[i].b == join[j].b) j++;
			res++;
			i = j;
		}
		
		printf("Case %d: %d\n", rr, res);
	}
} 
