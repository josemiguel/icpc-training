#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while ( cin >> s){
		int res = 0;
		int p = 0, t = 1, cont = 0;
		if ( s.size() == 1){
			cout << 1 << endl;
			continue;
		}
		while( true ){
			if ( s[p] == s[t]){
				cont++;
				if ( cont == 5 ) {
					cont  = 0;
					res++;
				}
			}else{
				res++;
				cont = 0;

			}
			p++,t++;
			if ( t == s.size()+1) break;
		}
		cout << res << endl;
	}

	return 0;
}
