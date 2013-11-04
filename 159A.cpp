#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std ;
int r[1205][1205];
bool usd[1205][1205];
int main(){

	int n , d;
	cin >> n >> d;
	int k = 1;
	vector<string> v;
	map<string,int> mp;
	
	for( int i = 0; i < n; i++){
		string a, b;
		int t ;
		cin >> a >> b >> t;
		t++;
		if ( !mp.count(a) ) mp[a] = k++;
		if ( !mp.count(b) ) mp[b] = k++;
		r[mp[a]][mp[b]] = t;
		int tt = r[mp[b]][mp[a]];
		if ( tt ){
			if ( t - tt <= d && t - tt > 0) {
				if ( !usd[mp[a]][mp[b]] ) {
					usd[mp[a]][mp[b]] = true;
					usd[mp[b]][mp[a]] = true;
					v.push_back( a + " " + b );
				}
			}
		}
	}
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	
	}

	return 0;
}
