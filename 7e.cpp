#include<iostream>
using namespace std ;

#define MAX 1000005
int p[MAX];
int pr[MAX];
int main(){
	p[0] = p[1] = 1;
	for( int i = 2; i*i < MAX; i++){
		if ( !p[i] ){
			for( int j = i + i ; j < MAX; j+=i){
				p[j] = 1;
			}
		}
	}
	int n = 1;
	for( int i = 0; i < MAX; i++){
		if (!p[i]){
			pr[n++] = i;
		}
	}
	cout << pr[1] << endl;
	cout << pr[10001] << endl;
	return 0;
}
