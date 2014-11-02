#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;

int main(){

	int runs; string buff,name;
	scanf("%d\n",&runs);
	for( int r = 1; r <= runs ; r++ ){
		printf("Roll-call: %d\n",r);
		int n;
		scanf("%d\n",&n);
		int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
		for(int i = 0; i < n; i++){
			getline( cin , buff );
		//	cout << buff <<endl;
			istringstream is(buff);
			is >> name;
			bool first = false,  no_acc = false , no_wa = true, entro = false;
			int wrongs = 0; string res;
			while( is >> res ){
				entro = true;
				char ans = res[0] ;
				if ( ans == 'y' && wrongs > 0) {
					no_acc = true;
				}
				if ( ans == 'n'){
					wrongs++;
					no_wa = false;
				}
			}
			if ( !entro) y4++;
			else{
				if ( wrongs == 5 ) y3++;
				if ( no_acc ) y2++;
				if ( no_wa ) y1++;
			}
		}
		printf("Present: %d out of %d\n", y1, n);
		printf("Needs to study at home: %d out of %d\n",y2,n);
		printf("Needs remedial work after school: %d out of %d\n",y3,n);
		printf("Absent: %d out of %d\n",y4,n);

	}

	return 0;
}
