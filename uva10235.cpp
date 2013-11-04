#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<string>
#include<cctype>
#include<set>
#include<map>
#include<numeric>

#define ll long long
#define vi vector<int>
#define mp make_pair
#define oo (1<<20)
#define ones(x) __builtin_popcount(x)
#define clr(x) memset((x),0,sizeof(x))
#define rclr(x) memset((x),-1,sizeof(x))
#define All(v) (v).begin(),(v).end()
#define rAll(v) (v).rbegin(),(v).rend()
#define x first
#define y second
#define pb push_back
#define eps (1e-9)


#define REP(i,a,n) for(int i = a; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define dec(i,n) for(int i = n-1; i >= 0; i--)
#define DEC(i,a,n) for(int i = n-1; i >= a; i--)

using namespace std;
#define MAX 1000005
bool p[MAX+2];

void criba(){
	p[0] = p[1] = 1;
	for(int i = 2; i*i <= MAX; i++){
		if (!p[i]){
			for(int j = i+i; j <= MAX; j+=i){
				p[j] = 1;
			}
		}
	}
}

int rev(int n){
	int res = 0; while(n) {res = (n%10) + res*10; n/=10;}

	return res;
} 

int main(){
	criba();
	int n;
	while(cin>>n){
		int m = rev(n);
		if (!p[n] && !p[m] && n!=m) cout<<n<<" is emirp."<<endl;
		else if (!p[n]) cout<<n<<" is prime."<<endl;
		else cout<<n<<" is not prime."<<endl;
	}
	return 0;
}
