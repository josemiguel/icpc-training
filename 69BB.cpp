#include<cstdio>
using namespace std;

int main(){
	int h,m;
	scanf("%d:%d",&h,&m);

	int we = h*30 + m/2;
	we %= 360;
	int err = 0;
	if ( m % 2 ) err = 5;
	printf("%d.%d %d\n", we,err,m*6);
}
