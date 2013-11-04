#include <iostream>
#include <string>
using namespace std ;

int main(){
	int runs;
	cin >> runs;
	while( runs-- ){
		int r , len ;
		string s;
		cin >> r >> len >> s;

		cout << r << " ";
		for( int i = 0;  i < s.size(); i++){
			for( int j = 0; j < len; j++){
				cout << s[i];
			}
		}
		cout << endl;
	}

	return 0;
}
