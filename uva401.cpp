#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;

map<char,char> M;

void init(){
	M['A'] = 'A';	M['E'] = '3';	M['3'] = 'E';	M['H'] = 'H';	M['J'] = 'L';
	M['L'] = 'J';	M['I'] = 'I';	M['M'] = 'M';	M['O'] = 'O';	M['S'] = '2';
	M['2'] = 'S';	M['T'] = 'T';	M['U'] = 'U';	M['V'] = 'V';	M['W'] = 'W';
	M['Y'] = 'Y';	M['Z'] = '5';	M['5'] = 'Z';	M['1'] = '1';	M['8'] = '8';
}

bool rev(char a, char b){
	return (M[a] == b || M[b] == a);
}

void solve(string s, bool &pal, bool &mirr){
	for(int i = 0, j = s.size()-1; i <= j; i++,j--){
		if (!rev(s[i],s[j])) mirr = false;
		if (s[i]!=s[j]){
			pal = false;
		}
		if (!pal && !mirr) return ;
	}
}

int main(){
	string s;
	init();
	while(cin>>s){
		bool a=true,b=true;
		solve(s,a,b);
		if (a&&b){
			cout<<s<<" -- is a mirrored palindrome.\n";
		}else if (!a&&b){
			cout<<s<<" -- is a mirrored string.\n";
		}else if (a&&!b){
			cout<<s<<" -- is a regular palindrome.\n";
		}else if (!a&&!b){
			cout<<s<<" -- is not a palindrome.\n" ;
		}
		cout<<endl;
	}	
	return 0;
}
