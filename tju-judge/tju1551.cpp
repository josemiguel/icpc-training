#include<iostream>
#include<sstream>
#include<vector>
using namespace std;


int main(){
	string s;
	while(cin>>s && s[0] != '0'){
		while(s.size() != 1){
			int res = 0;
			for(int i = 0; i < s.size(); i++){
				res += s[i] -'0';
			}
			ostringstream os;
			os<<res;
			s = os.str();
		}
		cout<<s<<endl;
		
	}
	return 0;
}
