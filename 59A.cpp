#include<iostream>
#include<cctype>
using namespace std ;

int main(){
	string s;
	cin >> s;
	int u = 0;
	for(int i = 0 ;i < s.size(); i++){
		if (isupper(s[i]) ) u++;
	}
	if (u == s.size() - u ){
		for(int i = 0; i < s.size(); i++) cout<<(char)tolower(s[i]);
	}else if (2*u > s.size()){
	
		for(int i = 0; i < s.size(); i++) cout<<(char)toupper(s[i]);
	}else{
	
		for(int i = 0; i < s.size(); i++) cout<<(char)tolower(s[i]);
	}
	

	return 0;
}
