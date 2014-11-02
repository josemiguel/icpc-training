#include<iostream>
#include<cctype>
#include<map>
#include<string>
using namespace std;

int main(){
	int runs;
	cin>>runs;
	cin.ignore();
	for(int r = 1; r <= runs; r++){
		string s,t;
		getline(cin,s);
		getline(cin,t);
		map<char,char> M;
		for(int i = 1; i <= 26; i++){
			M['A' + i - 1] = t[i-1];
		}
		for(int i = 0; i < s.size(); i++) if (!isspace(s[i])) s[i] = M[s[i]];
		cout<<r<<" "<<s<<endl;
	}
	return 0;
}
