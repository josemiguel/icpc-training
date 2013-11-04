#include<iostream>
#include<string>
#include<cstring>
using namespace std ;
int car[ 30 ];
int pos[ 28 ][200001];
int t[ 2001 ][ 100 ];
int main(){
	int k,n;
	string s;
	cin >> k >> s >> n;
	
	for( int i = 0; i < s.size(); i++){
		pos[ s[i]-'a'][ ++car[ s[i] - 'a'] ] = i;
	}
	
	for( int i = 0; i < n; i++){
		int p; char c;
		cin >> p >> c;
		int g = (p / car[c-'a']) ;
		if ( p % car[c-'a'] != 0) g++;
		int r = p / g;
	 	int &ret = t[ g ][pos[ c - 'a' ][ r ]];
		if ( ret ){
			while( t[ g ][pos[c-'a'][ r ]] ){
				r++;
				if ( r == car[c-'a']+1) r=1,g++;
			}
			t[g][pos[c-'a'][r]] = true;
		}else{
			ret =  true;
		}
		
	}
	for( int j = 1; j <= k; j++){
		for( int i = 0; i < s.size();i++){
			if (t[j][i]) continue;
			cout << s[i];
		}
	}
	cout << endl;


	return 0;
}
