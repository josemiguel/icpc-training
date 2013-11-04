#include<cstring>
#include<cstdio>
#include<string>
#include<deque>
#include<iostream>
using namespace std ;

bool F(){
	deque<string> res;
	bool home = false;
	string tmp = "";
	char c; int i = 0;
	while((c = getchar()) != '\n' ) {
		if ( c == -1) return false;
		if ( c == '[' ) {
			if ( home ) res.push_front( tmp );
			else res.push_back( tmp );
			tmp = "";
			home = true; 
			continue;
		}
		else if ( c == ']' ) { 
			if ( home ) res.push_front( tmp );
			else res.push_back( tmp );
			tmp = "";
			home = false;
			continue;
		}
		tmp += c;
	}
	if ( home ) {
		
		printf("%s", tmp.c_str());
		while ( !res.empty()) {
			printf("%s", res.front().c_str());
			res.pop_front();
		}
		putchar(10);
	}
	else {
		while ( !res.empty()) {
			printf("%s", res.front().c_str());
			res.pop_front();
		}
		printf("%s\n", tmp.c_str());
	}
	return true;
	
}


int main(){
	while( F( ));

	return 0;
}
