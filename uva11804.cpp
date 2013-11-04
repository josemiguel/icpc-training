#include<algorithm>
#include<set>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

struct p{
	string name;
	int atk, def;
	p(){}
	p(string name, int atk, int def): name(name), atk(atk), def(def){}
};

bool operator < (const p &a, const p &b) {
	if (a.atk == b.atk){
		if (a.def == b.def){
			return a.name < b.name;
		}
		return a.def < b.def;
	}
	return a.atk > b.atk;
}

void print(set<string> atk){
	bool f = 0;
	cout<<"(";
	for(set<string>::iterator it = atk.begin(); it != atk.end() ; it++){
		if (f == 0)	cout<<*it, f = 1;
		else cout<<", "<<*it;
	}
	cout<<")"<<endl;
}

int main(){
	int runs;
	cin>>runs;
	for(int r = 1; r <= runs; r++){
		string s; int a, d;
		p jug[10];
		for(int i = 0; i < 10; i++){
			cin>>s>>a>>d;
			jug[i] = p(s,a,d);
		}
		sort(jug,jug+10);
		set<string> atk,def;
		for(int i = 0; i < 5; i++){
			atk.insert(jug[i].name);
		}
		for(int i = 5; i < 10; i++){
			def.insert(jug[i].name);
		}		
		printf("Case %d:\n",r);
		print(atk);
		print(def);

	}
	return 0;
}
