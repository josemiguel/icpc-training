#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>


using namespace std;


int main(){
	int runs;
	scanf("%d",&runs);
	cin.ignore();	
	for(int r = 1 ; r <= runs ; r++){
		string test,real;
		getline(cin,test);
		getline(cin,real);
		printf("Case %d: ",r);
		if (test != real){
			for(int i = 0; i < test.size(); i++) if (isspace(test[i])) test.erase(test.begin()+i),i--;
			for(int i = 0; i < real.size(); i++) if (isspace(real[i])) real.erase(real.begin()+i),i--;
			if (test!=real){
				puts("Wrong Answer");
			}else{
				puts("Output Format Error");
			}
		}else{
			puts("Yes");
		}
	}
	
	return 0;
}
