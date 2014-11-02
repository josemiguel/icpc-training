#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std ;
typedef long long Int;


int main(){
	string s;
	cin >> s;
	Int res = 0;
	for( int i = 0; i < s.size()-1;i++){
		int k = i, j, p ;
		bool f = true;
		for(j = s.size()-1; j >= k;j--){
			
			if ( s[j]!= s[k] )  k = i;
			else {
				k++;
				if ( f ) p = j;
				f = false;
			}
			if ( j > k || j == k ) {
				v[i].push_back( p );
			}
		}

	}
	cout << res << endl;
}
