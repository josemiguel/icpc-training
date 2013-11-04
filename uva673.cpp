#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){

	int n;
	cin >> n;
	string s;
	cin.ignore();
	for(int r = 0; r < n && getline(cin,s); r++ ) {
		stack<char> par, cor;
		int pp = 0, cc = 0;
		for(int i = 0; i < s.size(); i++){
			if ( s[i] == '('){
				par.push(s[i]);
			}else if (s[i] == ')'){
				if (!par.empty()) par.pop();
				else{
					pp++;
					par.push('(');
				}
			}
			
			if ( s[i] == '['){
				cor.push(s[i]);
			}else if (s[i] == ']'){
				if (!cor.empty()) cor.pop();
				else{
					cc++;
					cor.push('[');
				}
			}			
		}

		pp += par.size();
		cc += cor.size(); 
		if ( pp == 0 && cc == 0){
			bool sale = false;
			for (int i = 0; i < s.size() && !sale; i++){
				if ( s[i] == '(' || s[i] == '['){
					par.push(s[i]);
				}else{
					if (!par.empty()){
						if (par.top() == '['){
							if (s[i] == ')') { sale = true; break; }
						}
						if (par.top() == '('){
							if (s[i] == ']') { sale = true; break; }
						}
						par.pop();
					}else sale = true;
				}
			}
			if (sale) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;

			
		}else{
			cout<<"No"<<endl;
		}
		
	}

	return 0;
}
