#include<iostream>
using namespace std ;

string a;
bool f(int pos, string b){
	bool res = false;
	if (pos == a.size()) return true;
	if (b.size() == 0) return false;

	if (a[pos] == b[0]) res |= f(pos + 1, b.substr(1));
	else res |= f(pos, b.substr(1));

	return res;
}

int main(){
	a ="hello";string b;
	cin >> b;


	


	if ( f(0,b) ) cout <<"YES"<<endl;
	else cout <<"NO"<<endl;

	return 0;
}
