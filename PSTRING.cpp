#include<iostream>
#include<vector>
#include<string>
using namespace std ;
int b[ 1005 ];
void kmp_pre( string s ){
	int i = 0, j = -1;
	b[0] = -1;
	while( i < s.size() ){
		while( j >= 0 && s[i] != s[j] ) j = b[j];
		i++, j++;
		b[i] = j;
	}
}

bool kmp( string t, string s ){
	pre( s );
	int i = 0,  j = 0;
	while( i < t.size() ){
		while( j >=0 && t[i] != s[j] ) j = b[j];
		i++, j++;
		if ( j == s.size() ){
			return true;
		}
	}
	return false;
}

int main(){
	string a, b;
	while( cin >> a >> b ){
		for( int i = 0; i < a.size(); i++){
			string k = "";
			for( int j = 0; j < a.size();j++){
				if ( i == j );
				k += a[i];
			}
			kmp( k , b );
		}
	}

	return 0;
}
