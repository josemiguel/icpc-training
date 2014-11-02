#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool vow(char c){
	c = toupper(c);
	return c=='A' || c=='E'||c=='I'||c=='O'||c=='U';
}
int main(){

	string s;
	while (cin >> s ){
		int v[s.size()],c[s.size()];
		v[0] = vow(s[0]);
		c[0] = !vow(s[0]);
		int pos[s.size()];
		int t = 0;
		if ( c[0] ){
			pos[t++] = 0;
		}
		bool cagao = false;
		for(int i = 1; i < s.size(); i++){
			if (vow(s[i])){
				v[i] = v[i-1] + 1;
				c[i] = c[i-1];
			}else{
				cagao = true;
				c[i] = c[i-1] + 1;
				v[i] = v[i-1];
				pos[t++] = i;
			}
		}
		if ( !cagao ){
			cout << "No solution" << endl;
			continue;
		}


		int res = 0;
		int difant = 0;
		int tot = 0;
		for(int i = 0; i < t -1 ; i++){
			int dif = pos[i+1] - pos[i] ;
			if ( difant <= 4){
				tot += dif;
			}
			difant = dif;
		}
		cout << tot + 2 << endl;

	}
	

	return 0;
}

