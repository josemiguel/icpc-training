#include<iostream>
#include<string>
#include<cstdio>
#include<string>
using namespace std ;

char f( char a, char b){
	int aa = 0, bb = 0;
	if ( a >= 'a' && a <= 'z') aa = (a - 'a' + 10)*16;
	else aa = (a-'0')*16;
	if ( b >= 'a' && b <= 'z') bb = (b - 'a' + 10);
	else bb = b-'0';

	return aa+bb;
	
}

int main(){
	string s = "536f6d6520666c6f6f72732061726520656d7074792c20676f20737472616967687420746f2074686520313874682e204f682c206c657473206c6561766520746865207374617469632070616765732c206c65742773206d6f766520746f2064796e616d69632c207368616c6c2077653f";

	for( int i = 0; i < s.size(); i+=2){
		char a = s[i], b = s[i+1];
	 	cout << f( a, b) ;
	}
}
