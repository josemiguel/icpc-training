#include<cstdio>
#include<cstring>
#define REP(i, a, b) for (i=a ; i<b ; i++)

char *ns = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
char *nsr = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
char *s = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char *sr = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
 
char s[256];
int main() {
 
    int I, LEN1 = strlen(sr), LEN2 = strlen(nsr);
    char ch;
 
    REP(I, 0, LEN1) {
        s[s[I]] = sr[I];
    }
    REP(I, 0, LEN2) {
        s[ns[I]] = nsr[I];
    }
 
    while (scanf("%c",&ch)==1) {
 
        if (ch=='\n') putchar('\n');
        else if (ch==' ') putchar(' ');
        else {
            putchar(s[ch]);
        }
 
    }
 
    return 0;
}
