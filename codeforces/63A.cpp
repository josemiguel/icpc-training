#include<iostream>
#include<set>
using namespace std ;

int main(){

	int n;

	cin >> n;
	set<pair<int,pair<int,string> > > S;
	for(int i = 0; i < n; i++){
		int p ;
		string a,b;
		cin >> a >> b;
		if ( b == "rat") p = 0;
		else if (b == "woman" || b == "child") p = 1;
		else if (b == "man") p = 2;
		else p = 3;
		S.insert(make_pair(p,make_pair(i,a)));
	}
	for(typeof(S.begin()) it =S.begin(); it != S.end(); it++){
		cout << it->second.second<<endl;
	}
	return 0;
}
