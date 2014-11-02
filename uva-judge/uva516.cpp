#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;

ll F(ll x, ll n){
	if (n == 1) return x;
	ll xx = F(x,n/2);
	xx *=xx;
	if (n%2) return xx*x;
	return xx;
}
#define MAX 32800
vector<bool> b(MAX+4,true);
vector<int> p;
void criba(){
	b[0] = b[1] = false;
	for(int i = 2; i <= MAX; i++){
		if (b[i]){
			p.push_back(i);
			for(int j = i*i; j <= MAX; j+=i) b[j] = false;
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	criba();
	while(getline(cin,s) && s[0] != '0'){
		istringstream is(s);
		ll a,b,s = 1;
		while(is>>a>>b) s *= F(a,b);
		s--;
		bool ff = 0;
		set<pair<int,int> > res;
		for(int i = 0; i < p.size() && s != 1; i++){
			bool f = 0;
			int a = 0;
			while (s%p[i] == 0){
				s /= p[i]; f = 1; a++;
			}
			if (a){
				res.insert(make_pair(-p[i],a));
			}
		}
		for(set<pair<int,int> >::iterator it = res.begin(); it != res.end(); it++){
			if (ff) cout<<" ";
			cout<<-it->first<<" "<<it->second;
			ff = 1;			
		}
		cout<<endl;
	}
	return 0;
}
