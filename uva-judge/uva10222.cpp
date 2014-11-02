#include<iostream>
#include<cctype>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

string ENCODE = "234567890-=\\ertyuiop[]dfghjkl;'cvbnm,./";
string DECODE = "`1234567890-qwertyuiopasdfghjklzxcvbnm,";

int main(){
	string s;
	while(getline(cin,s)){
		for(int i = 0; i < s.size();i++){
			for(int j = 0; j < ENCODE.size(); j++){
				if (tolower(s[i]) == ENCODE[j]) { cout<<DECODE[j]; goto sale; }
			}
			cout<<s[i];			
			sale: ;
		}
		cout<<endl;
	}
	return 0;
}
