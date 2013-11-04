#include<iostream>
#include<cctype>
#include<cstdio>

using namespace std;

int main(){

	char linea[300];
	
	while(gets(linea)){
		if (isdigit(linea[0])){
			char *ptr = linea;
			int x,y;
			int n;
			while(sscanf(ptr,"%d %d%n",&x,&y,&n) != -1){
				printf("%d %d\n",x,y);
				ptr += n;
			}
		}else{
			puts(linea);		
		}
	}

	return 0;
}
