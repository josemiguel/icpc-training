#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;

struct T{
	char izq,der,equ,pre;
	double val;
	T(){}
	T(char _izq, char _der, char _pre, char _equ, double _val) {
		izq = _izq;
		der = _der;
		equ = _equ;
		pre = _pre;
		if (pre == 'm'){
			_val *= 0.001;
		}else if (pre == 'M'){
			_val *= 1000000;
		}else if (pre == 'k'){
			_val *= 1000;
		}
		val = _val;		
	} 
	
};

int main(){
	int runs;
	cin>>runs;
	cin.ignore();
	for(int r = 1; r <= runs; r++){
		string s;
		getline(cin,s);
		istringstream is(s);
		char izq,equ,der;
		double val;
		vector<T> res;
		string tok;
		while(is>>tok){
			if (tok.size() <= 2) continue;
			izq = tok[0];
			equ = tok[1];
			if (equ != '=') continue;
			val = -1.0;
			string tmp = "";
			for(int i = 2; i < tok.size(); i++) tmp += tok[i];
			istringstream iss(tmp);
			string str;
			if (!(iss>>val>>str)) continue;
			der = str[0];
			char pre = '\n';
			if (str.size() == 2 && isalpha(str[1])) der = str[1],pre = str[0];
			if (der == 'V' || der == 'A' || der == 'W')
			res.push_back(T(izq,der,pre,equ,val));
		}

		// P = U*I
		double ans = -1;
		if (res[0].izq == 'I' && res[1].izq == 'U'){
			ans = res[1].val*res[0].val;
			izq = 'P';
			der = 'W';
		}else if (res[0].izq == 'U' && res[1].izq == 'I'){
			ans = res[1].val*res[0].val;
			izq = 'P';			
			der = 'W';			
		}else if (res[0].izq == 'P' && res[1].izq == 'U'){
			if ( res[1].val == 0) res[1].val = 1;					
			ans = res[0].val/res[1].val;
			izq = 'I';						
			der = 'A';
		}else if (res[0].izq == 'U' && res[1].izq == 'P'){
			if ( res[0].val == 0) res[0].val = 1;		
			ans = res[1].val/res[0].val;
			izq = 'I';			
			der = 'A';
		}else if (res[0].izq == 'P' && res[1].izq == 'I'){
			if ( res[1].val == 0) res[1].val = 1;		
			ans = res[0].val/res[1].val;
			izq = 'U';
			der = 'V';
		}else if (res[0].izq == 'I' && res[1].izq == 'P'){
			if ( res[0].val == 0) res[0].val = 1;
			ans = res[1].val/res[0].val;
			izq = 'U';			
			der = 'V';
		}
		printf("Problem #%d\n%c=%.2lf%c\n\n",r,izq,ans,der);
	}
	return 0;
}
