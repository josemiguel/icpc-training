#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;

int b[300];

bool prime(int n){
	if (n == 0) return false;
	if (n == 2) return true;
	if (n%2 == 0) return false;
	for(int i = 3; i*i <= n; i+=2){
		if (n%i == 0) return false;
	}
	return true;
}
int main(){
	char s[300];
	for(char i = 'a', j = 1 ; i <= 'z' ; i++, j++) b[i] = j;
	for(char i = 'A', j = 27 ; i <= 'Z' ; i++, j++)	b[i] = j;	
	while(gets(s)){
		int n = 0;
		for(int i = 0; s[i]; i++) if(isalpha(s[i])) n += b[s[i]];
		if (prime(n)) puts("It is a prime word.");
		else puts("It is not a prime word.");
	}
	return 0;
}
