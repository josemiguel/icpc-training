#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void f(string &a){
	for(int i = 0; i< a.size();i++) a[i] = tolower(a[i]);
}

int main(){
	string s,t;
	cin>>s>>t;
	f(s),f(t);
	if (s > t){
		cout<<1<<endl;
	}else if (s == t){
		cout<<0<<endl;
	}else cout<<-1<<endl;

	return 0;
}
