#include<iostream>
#include<string>
using namespace std ;

bool f( char c){
	c = toupper(c);
	return c == 'A' || c == 'E' || c == 'I' || c == 'O'|| c == 'U' || c == 'Y';
}

int main(){
	string s;
	getline( cin , s );

	for(int i = s.size()-1;i >=0; i--){
		if (isalpha(s[i])){
			if ( f(s[i]) ){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
			return 0;
		}
	}

	return 0;
}
