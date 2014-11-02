#include<iostream>
#include<string>

using namespace std;
struct par{
	string irr, plu;
};

bool VOCAL(char c){
	return c == 'a' || c == 'e' || c == 'i' || c =='o' || c=='u';
}
int ESTA(par pals[], string b, int len){
	for(int i = 0; i < len; i++) if (pals[i].irr == b) return i;
	return -1;
}

int main(){

	int n,m;
	cin>>n>>m;
	par pals[n];
	for(int i = 0; i < n; i++){
		cin>>pals[i].irr>>pals[i].plu;
	}
	for(int i = 0; i < m; i++){
		string tmp;
		cin>>tmp;
		int pos,fin;
		char ult,pen;
		
		pos = ESTA(pals,tmp,n);
		
		fin = tmp.size()-1;
		ult = tmp[fin];
		pen = tmp[fin-1];
		
		
		if (pos == -1){
			if (!VOCAL(pen) && ult == 'y') { tmp[fin] = 'i';  tmp += "es"; }
			else if (ult == 'o' || ult == 's' || (pen == 'c' && ult == 'h') || (pen == 's' && ult == 'h') || ult =='x') tmp += "es";
			else tmp += "s";
			cout<<tmp<<endl;
		}else{
			cout<<pals[pos].plu<<endl;
		}
	}
	
	return 0;
}
