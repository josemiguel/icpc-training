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

int id[100010];

int Find(int n)
{
    if (id[n] < 0) return n;
    return id[n] = Find(id[n]);
}

int Union(int x, int y){
    if (x == y){
        return -id[x];
	}
    if (id[x] < id[y]) {
        id[x] += id[y];
        id[y] = x;
        return -id[x];
    }
    else{
        id[y] += id[x];
        id[x] = y;
	return -id[y];
    }
}
int main(){
    int r;
    scanf("%d", &r);
    while (r--) {
        int m;
        scanf("%d", &m);
        memset (id,-1,sizeof(id));
        int n = 1;
        map <string, int> mp;
		string u,v;
        for ( int i = 0; i < m; i++ ) {
            cin>>u>>v;
            if (!mp[u]) mp[u] = n++;
            if (!mp[v]) mp[v] = n++;
			printf("%d\n",Union(Find(mp[u]),Find(mp[v])));
        }
    }

    return 0;
}
