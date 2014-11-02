#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){

	long long s, n;
	cin >> s >> n;
	vector<pair<long long, long long> > v( n );
	for( int i = 0; i < n; i++ ){
		cin >> v[i].first >> v[i].second;
	}
	sort( v.begin(), v.end() );

	for( int i = 0; i < v.size(); i++){
		if ( s > v[i].first ) s += v[i].second;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}
