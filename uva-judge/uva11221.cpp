#include<iostream>
#include<cctype>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	int runs;
	cin>>runs;
	cin.ignore();
	for(int r = 1; r <= runs; r++){
		string s;
		getline(cin,s);
		string tmp = "";
		for(int i = 0; i < s.size(); i++){
			if (isalpha(s[i])) tmp += s[i];
		}
		printf("Case #%d:\n",r);
		bool f = true;
		for(int i = 0, j = tmp.size()-1; i <=j ;i++,j--) if (tmp[i] != tmp[j]) {puts("No magic :(");f=false;break;}
		
		if (!f) continue;
		int x;
		for(x = 1; x*x <= tmp.size(); x++){
			if (x*x == tmp.size()) break;
		}

		if (x*x == tmp.size()) printf("%d\n",x);
		else puts("No magic :(");
	}
}
