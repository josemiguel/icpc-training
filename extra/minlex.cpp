#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int MinExp(const string &str) {
    string s = str + str;
    int i = 0, j = 1, k = 0;
    while(i < str.size() && j < str.size() && k < str.size()) {
        if(s[i + k] == s[j + k]) {
            ++k;
        } else if(s[i + k] < s[j + k]) {
            j = max(i + 1, j + k + 1);
            k = 0;
        } else {
            i = max(j + 1, i + k + 1);
            k = 0;
            swap(i, j);
        }
#ifdef _DEBUG
        printf("i = %d, j = %d, k = %d/n", i, j, k);
#endif
    }
    return i;
}
int main() {
    int cs;
    scanf("%d", &cs);
    while(cs--) {
        char buf[10240];
        scanf("%s", buf);
        printf("%d/n", MinExp(buf) + 1);
    }
    return 0;
}

