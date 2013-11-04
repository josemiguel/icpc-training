#include<string>
#include<sstream>
#include<map>
#include<iostream>

using namespace std;
map<string,string> m;
int main(){

	string s;
	while(getline(cin,s) && s != ""){
		string a,b;
		istringstream is(s);
		is>>a>>b;

		m[b] = a;
	}
	
	while(cin>>s) {
		
		if (!m.count(s)) cout<<"eh"<<endl;
		else cout<<m[s]<<endl;
	}
}
