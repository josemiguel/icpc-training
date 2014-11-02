#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ;

#define all(x) x.begin(),x.end()

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<pair<int,int> > v;
	vector<int> a;
	for( int i = 0; i < n; i++) {
		int t ;
		cin >> t;
		a.push_back(t);
		v.push_back(make_pair(t, i+1));
	}
	sort( all(v) );

	vector<int> res;

	for( int i = n-1; i >= 0 && k ; i--,k-- ){
		res.push_back( v[i].second );
	}
	cout << a[res[res.size()-1]-1] << endl;
	for( int i = 0; i < res.size(); i++){
		if ( i ) cout << " ";
		cout << res[i] ;
	}
	cout << endl;
		

	return 0;
}
