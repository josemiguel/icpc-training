#include<iostream>
#include<string>
using namespace std;

int f(string a){
	int res=0;
	for(int i=0;i<a.size();i++) res+=(a[i]=='a' || a[i]=='e' || a[i]=='i' ||a[i]=='o'||a[i]=='u');
	return res;
}

int main(){
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);

	if ( f(a) == 5 && f(b) == 7 && f(c) == 5) cout << "YES" << endl;
	else cout << "NO" <<endl;

	return 0;
}
