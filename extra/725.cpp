#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std ;
vector< pair<int,int> > res[80];
void F(int N){
	for(int i = 1234; i*N <= 98765; i++){
		int tmp = i, dig = 0;
		int mask = 0;

		while(tmp){
			if (mask & ( 1 << (tmp % 10)  )) goto hell;
			
			mask |= (1 << (tmp % 10));
			tmp /= 10;
			dig++;
		}
		if ( 1 == 0 ) {
			hell: 
			continue;
		}
		if ( dig == 4 ) mask |= 1;
		dig = 0;
		int check = i * N;
		bool cagao = false;
		while(check){
			if ( mask & ( 1 << (check % 10 ) ) ) {
				cagao = true;
				break;
			}else{
				mask |= ( 1 << (check % 10));
			}
			check /= 10;
			dig++;
		}
		if ( dig == 4 ) if (mask & 1 ) cagao = true;
		if ( !cagao && dig <= 5){
			res[N].push_back(make_pair( i * N , i));
		}

	}	
}

int main(){
	for(int i = 2; i <= 79; i++) F(i);
	int N;
	int r = 1;
	while( cin >> N && N){
		if ( r != 1 ) putchar(10);
		r++;
		if (res[N].size()){
			for(int i = 0; i < res[N].size(); i++){
				printf("%05d / %05d = %d\n",res[N][i].first,res[N][i].second,N);
			}
		}else{
			printf("There are no solutions for %d.\n",N);
		}

	}
	return 0;
}
