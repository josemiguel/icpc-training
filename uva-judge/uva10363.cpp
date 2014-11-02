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

char g[4][4];

bool validwin(){
	if (g[0][0]==g[0][1] && g[0][0]==g[0][2]) return true;
	if (g[1][0]==g[1][1] && g[1][0]==g[1][2]) return true;
	if (g[2][0]==g[2][1] && g[2][0]==g[2][2]) return true;		
	
	if (g[0][0]==g[1][0] && g[0][0]==g[2][0]) return true;
	if (g[0][1]==g[1][1] && g[0][1]==g[2][1]) return true;
	if (g[0][2]==g[1][2] && g[0][2]==g[2][2]) return true;			
	
	if (g[0][0]==g[1][1] && g[0][0]==g[2][2]) return true;
	if (g[0][2]==g[1][1] && g[0][2]==g[2][0]) return true;
	
	return false;
	
		
}

int main(){
	int r;
	cin>>r;
	cin.ignore();
	while(r--){
		int x,o;
		x=o=0;
		for(int i = 0; i < 3 ; i++){
			for(int j= 0; j < 3 ; j++){
				g[i][j] = getchar();
				x += (g[i][j]=='X');
				o += (g[i][j]=='O');
			}
			getchar();
		}
		getchar();
		int res = x - o;
		
		if (res == 0 || res == 1){
			if (validwin()){
				cout<<"yes\n";
			}
			else{
				cout<<"no\n";
			}
		}
		else{
			cout<<"no\n";
		}
		
	}
}
