#include<cstdio>
#include<string>
using namespace std;

int main(){
	char c = 0, ant = 2;
	while(1){
		c = getchar();
		if (c == -1) break;
		if (c == ' ') continue;
		if (ant == '\n' && c == '"') continue;
		if (c == '"') continue;
		putchar(c);
		ant = c;
	}
	return 0;
}
