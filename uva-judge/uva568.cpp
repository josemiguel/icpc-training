#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int A[4][5][5] = {
{0,6,2,6,4,2,2,4,2,8,4,4,8,4,6,6,6,2,6,4,8,8,6,8,2},
{0,2,8,8,4,2,4,6,6,8,4,8,2,2,6,6,2,8,8,4,8,6,4,4,2},
{0,4,2,4,4,2,8,4,8,8,4,6,8,6,6,6,4,2,4,4,8,2,6,2,2},
{0,8,8,2,4,2,6,6,4,8,4,2,2,8,6,6,8,8,2,4,8,4,4,6,2}
};

char num[200];
char* dto5(int n)
{
	int j,L,i = 0;
	do{
		j = n % 5;
		num[i++] = (j<10) ? (j+'0'): ('A'+j-10);
	}while((n/=5)!=0);

	num[i] = 0;
	L = strlen(num);
	reverse(num,num+L);
	return num;
}

int solve(int N)
{
    char *num = dto5(N);
    int L = strlen(num),s = 0;
    for (int i = 0; i < L;i++){
        s=A[(L-1-i)%4][s/2][num[i]-'0'];
    }
    return s;
}

int main(){
	int N;

	while (scanf("%d", &N)!=-1){
		int k = 1;
		if (N != 1 && N != 0){
			k = solve(N);
		}
		printf("%5d -> %d\n",N,k);
	}
	return 0;
}
