#include<iostream>
#include<bitset>
#include<map>
using namespace std ;



int main(){
	map<char, string> H;
	H['>'] = "1000";
	H['<'] = "1001";
	H['+'] = "1010";
	H['-'] = "1011";
	H['.'] = "1100";
	H[','] = "1101";
	H['['] = "1110";
	H[']'] = "1111";
	string s;
	const int MOD = 1000003;
	int pot[404] ;
	pot[ 0 ] = 1;
	for (int i = 1; i < 404; i++ ) pot[ i ]  = (pot[ i - 1 ] * 2) % MOD;
	while(cin >> s){
		string bit = "";
		for(int i = 0; i < s.size(); i++){
			bit += H[s[i]];
		}
		int res = 0;
		int N = bit.size();
		int todo = 0;
		for(int i = 0; i < bit.size(); i++){
			--N;
			if ( bit[ i ] == '0' ) continue;
			res = (res % MOD + pot[N] % MOD) % MOD ;
		}
		cout << res % MOD<< endl;
	}
	
	return 0;
}
