#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main(){

	int runs;
	cin>>runs;
	cin.ignore();
	for(int r = 1; r <= runs; r++){
		string t,s;
		getline(cin,t);
		getline(cin,s);

		for(int i = 0; i < t.size(); i++){
			if (t[i] == 32) continue;
			t[i] = s[t[i]-'A'];
		}				
	
		cout<<r<<" "<<t<<endl;
	}
	return 0;
}
