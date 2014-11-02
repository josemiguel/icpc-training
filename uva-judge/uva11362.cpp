#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>

using namespace std;
int f[35];
bool kmp(string &t, string &p){
	if ( p.size() > t.size() ) return false;
	for(int i = 0; i < p.size(); i++){
		if (p[i] != t[i] ) return false;
	}
	return true;
	if ( p[0] != t[0] ) return false;
	if ( p.size() > t.size() ) return false;
	int i = 0, j = -1;
	f[i] = j;
	while( i < p.size() ){
		while( j >=0 && p[i] != p[j] ) j = f[j];
		i++;j++;
		f[i] = j;
	}
	i = 0, j = 0;
	while( i < t.size()){
		while( j >= 0 && t[i] != p[j] ) j = f[j];
		i++; j++;
		if ( j == p.size() ) return true;
	}
	return false;
}

int main(){
	int r;
	cin>>r;
	while(r--){
		int n;
		cin>>n;
		cin.ignore();
		vector<string> v;
		string s;
		for(int i = 0; i < n ; i++){
			getline(cin,s);
			v.push_back(s);
		}
		sort( v.begin(), v.end() );
		int i = 0, j = 1;
		bool b = false;
		while ( i < n-1){
			if ( kmp( v[i+1],v[i] ) ) { b = true; break;  }
			i++;
		}

		if (b){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}
