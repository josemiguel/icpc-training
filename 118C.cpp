#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
	string s;
	vector<pair<int,int> > v;
	int n,k;
	cin>>n>>k;
	cin>>s;
	
	int best = 0,dif;
	int res = 0;
	int a = 10;
	int usd[10] = {0};
	for(int i = 0; i < s.size(); i++){
		int a = s[i]-'0';
		usd[a]++;
	}
	int dig = 0;
	for (int i = 0; i < 10; i++){
		if (usd[i] > best){
			best = usd[i];
			dig = i;
		}
	}
	if ( best >= k ){
		cout<<0<<endl<<s<<endl;
		return 0;
	}
	for(int i = 0; i < s.size(); i++){
		int dif = s[i] - '0';
		dif -= dig;
		dif = dif < 0 ? -dif : dif;
		if ( dif == 0 ) continue;
		v.push_back(make_pair(dif,i));
	}
	sort(v.begin(),v.end());
	int it = k - best,i=0;
	while(it--){
		int pos = v[i].second;
		res += v[i].first;
		s[pos] = dig + '0';
		i++;
	}
	cout<<res<<endl<<s<<endl;

	return 0;
}
