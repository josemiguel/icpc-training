#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> hash;
int main(){
	int N;
	string s;
	while(cin>>N>>s){
		int maxtmp = 0; string res;
		hash = map<string,int> ();
		for(int i = 0; i < s.size() - N; i++){
			string tmp = s.substr(i,N);
			int rep = ++hash[tmp];
			if (rep > maxtmp){
				maxtmp = rep;
				res = tmp;
			}
		}
		cout<<res<<endl;
	}

	return 0;
}

