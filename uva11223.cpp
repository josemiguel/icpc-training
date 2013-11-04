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

map<string,char> mp;

void init(){
	mp[".-"] = 'A';	mp["-..."] = 'B';	mp["-.-."] = 'C';	mp["-.."] = 'D'; 
	mp["."] = 'E'; 	mp["..-."] = 'F';	mp["--."] = 'G';	mp["...."] = 'H';
	mp[".."] = 'I';	mp[".---"] = 'J';	mp["-.-"] = 'K';	mp[".-.."] = 'L';
	mp["--"] = 'M';	mp["-."] = 'N';	mp["---"] = 'O';	mp[".--."] = 'P';
	mp["--.-"] = 'Q';	mp[".-."] = 'R';	mp["..."] = 'S';	mp["-"] = 'T';
	mp["..-"] = 'U';	mp["...-"] = 'V';	mp[".--"] = 'W';	mp["-..-"] = 'X';
	mp["-.--"] = 'Y';	mp["--.."] = 'Z';	mp["-----"] = '0';	mp[".----"] = '1';
	mp["..---"] = '2';	mp["...--"] = '3';	mp["....-"] = '4';	mp["....."] = '5';
	mp["-...."] = '6';	mp["--..."] = '7';	mp["---.."] = '8';	mp["----."] = '9';
	mp[".-.-.-"] = '.';	mp["--..--"] = ',';	mp["..--.."] = '?';	mp[".----."] = '\'';
	mp["-.-.--"] = '!';	mp["-..-."] = '/';	mp["-.--."] = '(';	mp["-.--.-"] = ')';
	mp[".-..."] = '&';	mp["---..."] = ':';	mp["-.-.-."] = ';';	mp["-...-"] = '=';
	mp[".-.-."] = '+';	mp["-....-"] = '-';	mp["..--.-"] = '_';	mp[".-..-."] = '"';	mp[".--.-."] = '@';
}
int main(){
	int n;
	cin>>n;
	cin.ignore();
	init();
	for(int i = 1; i <= n ; i++){
		if (i!=1) cout<<endl;
		string s,ss;
		getline(cin,ss);
		istringstream is(ss);
		printf("Message #%d\n",i);
		while(is>>s){
			cout<<mp[s];
			is.ignore();
			if (is.peek()==' ') cout<<" ";
		}
		cout<<endl;
	}
	return 0;

}
