#include<iostream>
using namespace std ;

int main(){

	int p,q,runs;
	cin >> runs;
	while( runs--){
		cin >> p >> q;
		string s = "";
		int k = 0;
		
		while( p >= 2 && q >= 1 ) s += "101",p-=2,q--;
		// p >= 2 && q == 0
		// p {0,1} && q >= 1
		//cout << p << " " << q <<" "<< s <<  endl;		
		if ( q == 0 ) while( p ) s += "1", p--;
		else while ( p ) s = "01" + s, p--;
		//cout << s << endl;

		long long res = 0LL;
		for( int i = 0; i < s.size(); i++){
			if ( s[ i ] == '1' ){
				res += ( 1LL << (s.size()-i-1));
			}
		}	
		cout << res << endl;	
	}

	return 0;
}
