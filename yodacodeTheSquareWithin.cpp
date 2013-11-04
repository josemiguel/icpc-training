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

int n,m;

int main(int nargs, char **args){

	FILE *file = fopen(args[1],"r");
	int n;
	while(fscanf(file,"%d",&n)!=-1){
		printf("%d\n",(n*(n+1)*(2*n+1))/6);
	}
	
	return 0;
}
