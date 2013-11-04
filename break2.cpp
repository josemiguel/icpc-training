#include<iostream>
#include<cstdio>
#include<string>

using namespace std ;

int main(){
	string tmp,s="";

	printf("%c%c%c%c%c%c\n",110,54,88,55,122,100);

// 1 2 3 5 8 13 21 34 55 89

	while ( cin >> tmp) s+=" " + tmp;
	for( int i = 0; i < s.size(); i++){
		s[ i] = s[i]=='p' ? '-' : s[i] == 'e' ? '.': '\t';
	}
	cout << s << endl;

}
