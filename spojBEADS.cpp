#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
	int r;
	cin>>r;
	cin.ignore();
	while(r--){
		string s;
		getline(cin,s);
		int id = 0;
		for(int j = 1, k; j < s.size(); ){
			for (k = 0; k < s.size() && s[(id + k) % s.size()] == s[(j + k) % s.size()]; k++);     
			if (k == s.size()) break;
			if (s[(id + k) % s.size()] > s[(j + k) % s.size()]) id = j++;
			else j += k + 1;
		}
		cout<<id+1<<endl;
	}
	return 0;
}
