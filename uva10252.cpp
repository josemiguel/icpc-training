#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string a,b;
	while(getline(cin,a) && getline(cin,b)){
		int m[30] = {0};
		for(int i = 0; i < a.size(); i++) m[a[i]-'a']++;
		string x;
		for(int i = 0; i < b.size(); i++) {
			if (m[b[i]-'a']){
				x += b[i];
				m[b[i]-'a']--;
			}
		}
		sort(x.begin(),x.end());
		cout<<x<<endl;
	}
	return 0;
}

