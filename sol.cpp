#include <iostream>
#include<cctype>
#include <cstdio>
using namespace std;


bool in( char c, char *s){
    for( int i = 0; s[i]; i++) {
        if ( s[i] == c ) return true;
    }
    return false;
}

int lp1Read( char *&cad ){
    int n; char c, tmp[ 300 ];
    while( ( c = getchar() ) && ( c != '\n' && c != EOF)  ) tmp[ n++ ] = c;
    cad = new char[ n + 1 ];
    for( int i = 0; i < n; i++) cad[i] = tmp[i];
    cad[ n ] = 0;
	cout << n << endl;
    return n ? n : -1;
}

int lp1Write( char *cad ){
	puts( cad );
    int n = 0;
    for( int i = 0; cad[i]; i++) cout << cad[i], n++;
    return n;
}

char *lp1Strtok( char *a, char *b){
    static char *ptr ;
    if ( a ) ptr = a;
    if ( *ptr == 0 ) return NULL;
    int sz = 0;
    for( int i = 0; ; i++){
        if ( in( ptr[i], b ) || !ptr[i] ) {
            char *res = new char[ i + 2 ];
            for( int j = 0; j < i; j++, ptr++) res[ j ] = *ptr;
            res[ i ] = 0;
            while( in( *ptr, b ) ) ptr++;
            return res;
        }
    }
}

int lp1Strspn( char *cad1, char *cad2 ){
    int res = 0;
    for( int i = 0; cad1[i] ; i++){
        if ( !in( cad1[i] ,cad2 ) ) return res;
        res++;
    }
    return 0;//cad1 vacia
}

int lp1Strcspn( char *cad1, char *cad2 ){
    int res = 0;
    for( int i = 0; cad1[i] ; i++){
        if ( in( cad1[i] ,cad2 ) ) return res;
        res++;
    }
    return 0;//cad1 vacia
}

char *lp1Strlwr( char *cad ){
    int n = 0;
    for( int i = 0; cad[i] ; i++ ) n++;
    char *res = new char[ n + 1 ];
    for( int i = 0; cad[i] ; i++ ) res[i] = tolower(cad[i]);
    res[ n ] = 0;
    return res;
}
char *lp1Strupr( char *cad ){
    int n = 0;
    for( int i = 0; cad[i] ; i++ ) n++;
    char *res = new char[ n + 1 ];
    for( int i = 0; cad[i] ; i++ ) res[i] = toupper(cad[i]);
    res[ n ] = 0;
    return res;
}

int lp1Strcmp( char *cad1, char *cad2 ){
    int n = 0, m = 0;
    for( int i = 0; cad1[i] ; i++ ) n++;
    for( int i = 0; cad2[i] ; i++ ) m++;

    if ( n < m ) return -1;
    if ( n > m ) return 1;
    
    for( int i = 0; i < n ; i++ ){
        if ( cad1[i] < cad2[i] ) return -1;
        if ( cad1[i] > cad2[i] ) return 1;
    }
    return 0;
}

int lp1Strlen( char *cad ){
    int n = 0;
    for( int i = 0; cad[i] ; i++ ) n++;
    return n;
}

int main(){
    int b;
    while( scanf("%d",&b) != EOF){
		fflush( stdin );
        char *str;
        lp1Read( str );
		int sign[ 50 ];
        sign[ 0 ] = 1;
        int k = 0;
        for( int i = 0; str[i]; i++ ) if ( str[i] == '+' || str[i] == '-' ) sign[ k++ ] = str[i] == '-' ? -1 : 1;
        char *p = lp1Strtok( str, "+-" );
        int res10 = 0, j = 0, val;
        while( p ){
			lp1Write( p );
/*            char *op = lp1Strupr( p );
            int len = lp1Strlen( op ), pot = 1, b10 = 0;
            for( int i = len - 1; i >= 0; i++ ){
				if ( isdigit( op[i] ) ) val = op[i] - '0';
				else val = op[i] -'A'+ 10;
                b10 += val * pot;
               pot *= b;
            }
            res10 *= b10 * sign[ j ] ;*/
            p = lp1Strtok( NULL, "+-" );
        }/*
		while ( res10 ){
			int dig = ( res10 % b );
			if ( dig > 9 ) putchar( 'A' + dig - 10 );
			else putchar( dig + '0' );
			res10 /= b;
		}*/
		putchar(10);
            
    }

    return 0;    
}
