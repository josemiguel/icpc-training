#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;

int main(){

	int T;
	cin >> T;

	while( T--){
		int r;
		string s;
		cin >> r >> s;
		if (next_permutation(s.begin(),s.end())){
			cout << r << " " << s << endl;
		}else{
			cout << r << " BIGGEST" << endl;
		}
	}

	return 0;
}
