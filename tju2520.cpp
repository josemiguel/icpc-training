#include<iostream>
#include<cctype>
#include<map>
#include<string>
using namespace std;

int main(){
	string s;
	while(getline(cin,s) && s != "#"){
		int res = 0;
		for(int i = 0, j = 1; i < s.size(); i++, j++){
			if (isspace(s[i])) continue;
			res += j*(s[i]-'A'+1);
		}
		cout<<res<<endl;
	}
	
	return 0;
}
