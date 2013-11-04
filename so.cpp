#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std ;

void arr_to_pipe( int a[], int n, int fd ){
	char buff[ 20 ];
	sprintf( buff, "%d", n);
	write( fd, buff, sizeof buff );
	for( int i = 0; i < n; i++ ){
		sprintf( buff, "%d", a[i]);
		write( fd, buff, sizeof buff);
	}
}

void hijo( int fd ){
	int N , p ;
	char buff[ 20 ];
	while( read( fd, buff, sizeof buff ) > 0){
		N = atoi( buff );
		read( fd, buff, sizeof buff );
		p = atoi( buff );
		cout << p << endl;
		break;
	}
	int fd2[2];
	pipe( fd2 );
	int criba[ N ], k = 0;
	for( int i = 0; i < N - 1 ; i++){
		read( fd, buff, sizeof buff );
		int tmp = atoi( buff );
		if ( tmp % p ){
			criba[ k++ ] = tmp ;
		}
	}
	close( fd );
	arr_to_pipe( criba , k, fd2[1] );
	int id = fork();
	if ( id == 0 && k ) {
		hijo( fd2[0] );
	}
}

int main(int narg , char *arr[]){
	int n = atoi( arr[1] );
	char buff[ 20 ];
	int fd[2];
	pipe( fd );
	int id = fork();
	if ( id ){
		int criba[ n ];
		for( int i = 2; i <= n; i++) criba[ i - 2 ] = i ;
		arr_to_pipe( criba , n - 1, fd[1] );
	}else{
		hijo( fd[0] );	
	}


	return 0;
}
