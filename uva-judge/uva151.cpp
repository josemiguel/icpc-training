#include<cstdio>

using namespace std;

#define MAX 155

int Q[MAX];
int front,back,ELEM;

void push(int i){
	ELEM++; back++;
	if(back >= MAX) back = 1;
	Q[back] = i;
}
int pop(){
	ELEM--;int i = Q[front];
	front++; if(front >= MAX) front=1; return i;
}

int josephus(int N,int diff){
	int i;
	ELEM = N;
	for(i = 1;i <= N ; i++) Q[i]=i;

	i = 0;
	front = 1;
	back = N;

	if(N > 1) pop();
	
	while(ELEM != 1){
		if(i != diff){
			i++;
			push(pop());
		}
		else{
			pop();
			i = 0;
		}
	}
	return Q[front];
}

int main(){
	int n;
	while(scanf("%d",&n) && n){
		if (n == 13)	printf("1\n");
		else{
			int m = 1;
		    while(josephus(n,m++)!=13);
		    printf("%d\n",m);
		}
	}

	return 0;
}
