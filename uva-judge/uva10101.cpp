#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int pot[] = {100,1000,100000,10000000};
string name[] = {"","shata","hajar","lakh","kuti"};
typedef long long ll;

ll CEROS(ll n){
	while(n%10 == 0) n /=10;
	return n;
}

int main(){
	ll N;
	ll C = 0;
	ios_base::sync_with_stdio(false);
	while(cin>>N){
		C++;
		vector<pair<string,ll> > res;
		for(int i = 0; N; i = (i + 1)%4){
			res.push_back(make_pair(name[i],N%pot[i]));
			N -= N%pot[i];
			if (i == 3) N /= pot[3];
		}
		cout<<"    "<<C<<". ";
		for(int i = res.size()-1; i >= 0; i--){
			if (i != res.size()-1) cout<<" ";
			cout<<CEROS(res[i].second)<<" "<<res[i].first;
		}
		cout<<endl;
	}	
	return 0;
}
