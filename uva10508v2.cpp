#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


struct par{
	string s;
	int d;
	par(){}

};

	bool operator < (const par& A, const par& B){
		return A.d < B.d;
	}

vector<par> v;
int n,m;
int diff(int a, int b){
	int d = 0;
	for(int i = 0; i < m; i++){
		d += (v[a].s[i] != v[b].s[i]);
	}
	return d;
}

int main(){

	while(cin>>n>>m){
		v = vector<par>(n);
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			v[i].s = s;
			v[i].d = 0;
		}
		for(int i = 1; i < n; i++){
			v[i].d = diff(i,0);
		}
		sort(v.begin(),v.end());
		for(int i = 0; i < n; i++){
			cout<<v[i].s<<endl;
		}
	}
	return 0;
}

