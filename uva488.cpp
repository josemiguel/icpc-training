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
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define INF 1<<30


int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		int amp,freq;
		scanf("%d%d",&amp,&freq);
		if (r!=1) putchar(10);
		for(int i = 0 ; i < freq ; i++){
			for(int j = 1; j <= amp; j++){
				for(int k = 0; k < j ; k++){
					printf("%d",j);
				}
				putchar(10);
			}
			
			for(int j = amp-1; j >= 1; j--){
				for(int k = 0; k < j ; k++){
					printf("%d",j);
				}
				putchar(10);				
			}
			if (i != freq-1) putchar(10);
		}
	}
	
	return 0;
}
