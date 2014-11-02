#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

int diff(char c, char tar){
	int d = 0;
	
	for(d = 0; d < 26; d++){
		char C = c;
		for(int j = 0; j < d; j++){
			C++;
			if (C == 'z'+1) C = 'a';							
		}
		if (C == tar)  break; 
	}
	return d;
}

int main(){
	int runs;
	cin>>runs;
	cin.ignore();
	while(runs--){
		string s,t;
		getline(cin,s);
		getline(cin,t);
		istringstream is(s);
		string tok;
		string res = "";
		while(is>>tok){
			if (tok.size() == t.size()){
				int d = diff(t[0],tok[0]);
				int f = 1;			
				for(int i = 0; i < tok.size(); i++)	if (diff(t[i],tok[i]) != d) { f = 0; break;}
				if (f) res += (char)('a'+d);
			}
		}
		sort(res.begin(),res.end());
		cout<<res<<endl;
	}
	return 0;
}
