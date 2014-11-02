#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std ;

int main(){

	int T;
	cin >> T;
	vector<string> tmp;
	tmp.push_back( "TTT" );
	tmp.push_back( "TTH" );
	tmp.push_back( "THT" );
	tmp.push_back( "THH" );
	tmp.push_back( "HTT" );
	tmp.push_back( "HTH" );
	tmp.push_back( "HHT" );
	tmp.push_back( "HHH" );
	while( T-- ){
		string s;
		int r;
		cin >> r >> s;
		cout << r;
		for( int i = 0; i < tmp.size(); i++){
			int res = 0;
			vector<bool> usd(s.size(), false);
			for( int j = 0; j < s.size(); j++){
				string it = s.substr( j );
				int pos = it.find( tmp[i] );
				if ( pos == -1 ) continue;
				if ( usd[pos + j ] ) {
					continue;
				}
				usd[pos + j ] = true;
				res++;
			}
			cout<<" "<<res;
		}
		cout << endl;
	}


	return 0 ;
}
