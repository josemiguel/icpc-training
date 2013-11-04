#include<iostream>
#include<vector>
#include<string>
using namespace std ;

int main(){

	string s;

	cin >> s;
	bool m = s[0] == '-';
	if ( s[0] == '-') s = s.substr(1);
	int pos = s.size();
	for( int i = 0; i < s.size(); i++){
		if ( s[i] == '.' ) {pos = i;break;}
	}
	if ( m == true) cout << "(";
	cout <<"$";
	string b,tmp="";
	vector<string> res;	
	for(int i = pos-1,j = 1; i >=0; i--, j++){
		tmp = s[i] + tmp ;
		if ( j % 3 == 0){
			res.push_back( tmp );
			tmp = "";
		}
		if ( i == 0 && tmp != ""){
			res.push_back( tmp );
		}
	}
	for(int i = res.size()-1; i >= 0; i--){
		if ( i != res.size()-1) cout <<",";
		cout << res[i];
	}
	if ( pos == s.size() ) cout << ".00";
	else{
		int j = 0;
		for( int i = pos; j < 3 && i <s.size(); j++, i++) cout <<s[i];
		if ( j != 3) cout << 0;
	
	}
	if ( m == true ) cout << ")";
	cout << endl;


	return 0;
}
