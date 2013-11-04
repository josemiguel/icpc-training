#include<iostream>
#include<sstream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 100005
#define N 10007
map<string,int> buck[N];
string dic[MAX];

int hash(string s){
	int res = 0, pot = 1;
	for(int i = 0; i < s.size(); i++){
		res = res + ((s[i]-'a')*pot) % N;
		pot = pot * 27 % N;
	}
	return res % N;
}

void add(string s, int id){
	buck[hash(s)][s] = id;
}

int get(string s){
	int res = buck[hash(s)][s];
	if (res) return res;
	return -1;
}

int main(){
	string s,a,b;
	int n = 1;
	while(getline(cin,s) && s!=""){
		istringstream is(s);
		is>>a>>b;
		dic[n] = a;
		add(b,n);
		n++;
	}
	while(cin>>s){
		int res = get(s);
		if (res == -1) cout<<"eh"<<endl;
		else cout<<dic[res]<<endl;
	}
	
	return 0;
}
