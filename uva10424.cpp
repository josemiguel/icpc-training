#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std ;
int dig(int n){
	int res = 0;
	while(n) {
		
		n /= 10;
		res++;
	}
	return res;
}
int f(string a){
	int sum = 0;
	for(int i = 0; i < a.size(); i++){
		if (isalpha(a[i])){
			if (islower(a[i])){
				sum+=a[i]-'a'+1;
			}else if (isupper(a[i])){
				sum+=a[i]-'A'+1;
			}
		}
	}
	while( dig( sum ) != 1){
		int n = 0;
		while( sum ){
			n +=( sum % 10 );
			sum /= 10;
		}
		sum = n;
	}
	return sum;
}

int main(){
	string a,b;

	while(getline(cin,a) && getline(cin,b)){
		int fa = f(a);
		int fb = f(b);
		double res;
		if (fa > fb) {
			res = (100.00*fb) / fa;
		}else{
			res = (100.00*fa) / fb;
			}
		printf("%.2lf " ,res);
		puts("%");
	}
}
