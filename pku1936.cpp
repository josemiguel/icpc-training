#include<iostream>
#include<string>
using namespace std;

int main(){
	string a,b;
	while(cin>>a>>b){
		int N = 0;
		for(int j = 0; N < a.size() && j < b.size(); j++) 
			if (a[N] == b[j]) N++;
			
		if (N == a.size()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
