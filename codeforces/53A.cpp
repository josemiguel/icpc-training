#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

	string s;
	cin>> s;
	int n;
	cin >> n;
	string dic[n];
	for(int i = 0; i < n; i++) cin >> dic[i];

	sort(dic,dic + n);

	for(int i = 0; i < n; i++){
		if (dic[i].size() < s.size()) continue;
		if (dic[i].substr(0,s.size())  == s) {
			cout << dic[i] << endl;
			return 0;
		}
	}
	cout << s << endl;
	return 0;
}
