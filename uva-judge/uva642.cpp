#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main(){
	map<string,set<string> > dic;
	string s;
	while(cin>>s && s!= "XXXXXX"){
		string tmp = s;
		sort(tmp.begin(),tmp.end());
		dic[tmp].insert(s);
	}
	while(cin>>s && s!= "XXXXXX"){
		sort(s.begin(),s.end());
		set<string> res = dic[s];
		if (res.size()){
			for(set<string>::iterator it = res.begin(); it != res.end(); it++){
				cout<<*it<<endl;
			}
		}else{
			cout<<"NOT A VALID WORD"<<endl;
		}
		cout<<"******"<<endl;
	}
	return 0;
}
