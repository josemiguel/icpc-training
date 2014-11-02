#include<iostream>
using namespace std ;

int main(){

	string s;
	string a="1111111",b="0000000";

	cin >> s ;
	if ( s.find(a) != -1 || s.find(b) != -1) cout << "YES" <<endl;
	else cout <<"NO"<<endl;

	return 0;
}
