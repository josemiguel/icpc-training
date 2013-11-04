#include<stdio.h>
#include<math.h>
#include<ctype.h>

int main(){

	float sumfloat = 0;
	int sumint = 0, cantfloat = 0, cantint = 0;
	char c = 0, c_ant = ' ';
	
	while(c != EOF){
		c = getchar();
		if (c != EOF ) putchar(c);
		if ( isdigit(c) && isspace(c_ant) ) {
		
			int parteEntera = c-'0';
			int parteDecimal = 0;
			int cantDecimales = 0;
			
			bool real = false, cagao = false;
			

			while((c=getchar()) && !isspace(c) && c != EOF){
				putchar(c);
				if (c == '.' && !real) {
					real = true; 
					continue; 
				}
				else if ( !isdigit(c) ) cagao = true;
				
				if (real) {	
					parteDecimal = parteDecimal*10 +  c - '0';
					cantDecimales++;
				}
				else {	
					parteEntera = parteEntera*10 + c - '0';
				}
			}
			if ( c != EOF )	putchar(c);

			if ( !cagao ){
				if ( real )  {
					
					sumfloat += parteEntera + parteDecimal/pow(10.0,cantDecimales);
					cantfloat++;
					
				}else{
					sumint += parteEntera;
					cantint ++; 
				}
			}
		}
		c_ant = c;
	}
	
	printf("\nEl archivo tiene %d números enteros y %d de punto flotante, los enteros suman %d y los de punto flotante %f.\n",cantint,cantfloat,sumint,sumfloat);

	return 0;
}
