#include<iostream>
#include<string>
using namespace std;
int main(){
 	int R = 0;
	while(1){
		if (R) cout<<endl; R = 1;	
		string T = "",s;
		bool sale = false, F = false;
		while(1){
			if (!getline(cin,s)) {sale = true; break;}
			if (s == "") break;
			if (F) T += "!";
			F = true; T += s;
		}
		int S = 0;
		for(int i = 0; i < T.size(); i++){
			if (isdigit(T[i])) S += T[i] - '0';
			else if ((T[i] >= 'A' && T[i] <= 'Z') || T[i] == '*' || T[i] == 'b' || T[i] == '!')  {
				if (T[i] == '!') { cout<<endl; continue; }
				while(S--)
					if (T[i] == 'b') cout<<" ";
					else cout<<T[i];
				S = 0;
			}
		}
		cout<<endl;
		if (sale) break;
	}
	return 0;
}
