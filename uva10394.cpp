#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define MAX 20000002
#define mp make_pair
int d[1000005][2];

bool p[MAX];

void pre(){
	for(int i = 2; i*i < MAX; i++){
		if (!p[i]) for(int j = i+i ; j < MAX ; j+=i)
			p[j] = true;		
	}
	int N = 0;
	for(int i = 3; i < MAX ; i+=2)
		if (!p[i] && !p[i+2]) d[N][0] = i, d[N][1] = i+2, N++;
}

int main(){
	int pos;
	pre();
	while(scanf("%d",&pos)!=-1){
		pos--;
		printf("(%d, %d)\n",d[pos][0],d[pos][1]);
	}	
	
	return 0;
	
}
