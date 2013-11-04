#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b,s;
int pos;
void pre(){
	for(int i = 0, j = 0; i < a.size() && j <b.size(); i++, j++){ 
		if (a[i] == b[j]) {s += a[i] ; continue; }
		if (a[i] == 'f') { s += 'f'; if (b[j] == 'p') j+=4; continue; }
		if (b[j] == 'f') { s += 'f'; if (a[i] == 'p') i+=4; continue; }
		if (a[i] == 'e'){
			for(int k = 0; k <= 4; k++) s += b[j+k]; j+=4;
		}else if (b[j] == 'e'){
			for(int k = 0; k <= 4; k++) s += a[i+k]; i+=4;
		}
	}
}

int F(int lvl){
	if (pos == s.length() || s[pos] == 'e') return 0;
	if (s[pos] == 'f')  return lvl;
	int res = 0;
	if (s[pos] == 'p') 
	for(int i = 1; i <= 4; i++)	pos++, res += F(lvl/4);
	return res;
}

int main(){
	int r;
	ios_base::sync_with_stdio(false);
	cin>>r;
	cin.ignore();
	while(r--){
		getline(cin,a);	getline(cin,b);
		s = "";
		pre();	pos = 0;
		cout<<"There are "<<F(1024)<<" black pixels."<<endl;
	}
	return 0;
}
