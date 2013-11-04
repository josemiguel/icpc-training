#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<iostream>

using namespace std;
char *mydup(char cad[]){
	int len = strlen(cad) + 1;
	char *res = new char[len]; strcpy(res,cad);
	return res;
}

char *mytok(char *linea, char formato, char *&token){
	int pos = 0;
	if ( formato != 'S'){
		while( !isspace(linea[pos]) && linea[pos] != 0 ) pos++;
		linea[pos] = 0;
		token = linea;
		while( isspace(linea[++pos]) );
		linea = &linea[pos];
	}else{
		int slash = 0;
		while( slash != 2 ) if (linea[pos++] == '/') slash++;
		linea[pos-1] = 0;
		linea++;
		token = linea;
		while( isspace(linea[++pos]) );
		linea = &linea[pos];
	}
	return linea;
}

bool esta(int dig, int N){
	while(N){
		if (N % 10 == dig ) return true;
		N /=10;
	}
	return false;
}

void clean( char ***&datos,int N ){
	datos = new char **[N+1];
	for(int i = 0; i < N; i++){
		datos[i] = new char *[1];
		datos[i][0] = NULL;
	}
	datos[N] = NULL;
}

void clean( double **&datos,int N ){
	datos = new double *[N+1];
	for(int i = 0; i < N; i++){
		datos[i] = new double [1];
		datos[i][0] = -100;
	}
	datos[N] = NULL;
}

void clean( int **&datos,int N ){
	datos = new int *[N+1];
	for(int i = 0; i < N; i++){
		datos[i] = new int [1];
		datos[i][0] = -100;
	}
	datos[N] = NULL;
}

void init(char *formato, char ***&datosTexto, char ***&datosFecha, int **&datosEnteros, double **&datosReales){

	if (datosTexto != NULL) return; 
	
	int F = 0, R = 0, S = 0, E = 0;
	int len = strlen(formato);
	for(int i = 0; i < len; i++){
		if (formato[i] == 'F') F++;
		else if (formato[i] == 'R') R++;
		else if (formato[i] == 'S') S++;				
		else if (formato[i] == 'E') E++;
	}

	clean(datosTexto,S);
	clean(datosFecha,F);	
	clean(datosEnteros,E);
	clean(datosReales,R);
}

void inserta(char **&datos, char *valor){
	int last = 0;
	while(datos[last] != NULL) last++;
	
	char **copia_datos = new char*[ last + 2 ];
	for(int i = 0; i < last ; i++)	copia_datos[i] = mydup(datos[i]);
	copia_datos[last] =  valor;
	copia_datos[last + 1] =  NULL;
	for(int i = 0; i < last ; i++) delete [] datos[i];
	datos = copia_datos;
}

void inserta(double *&datos, double valor){
	int last = 0;
	while(datos[last] >= 0) last++;
	double *copia_datos = new double[ last + 2 ];
	for(int i = 0; i < last ; i++) copia_datos[i] = datos[i];
	copia_datos[last] =  valor;
	copia_datos[last + 1] =  -105;	
	for(int i = 0; i < last ; i++) delete [] datos;	
	datos = copia_datos;
}

void inserta(int *&datos, int valor){
	int last = 0;
	while(datos[last] >= 0) last++;
	int *copia_datos = new int[ last + 2 ];
	for(int i = 0; i < last ; i++) copia_datos[i] = datos[i];
	copia_datos[last] =  valor;
	copia_datos[last + 1] =  -100;	
	for(int i = 0; i < last ; i++) delete [] datos;
	datos = copia_datos;
}

void borra(char ***&datos){
	for(int i = 0; datos[i]; i++)
		for(int j = 0; datos[i][j]; j++)
			delete [] datos[i][j];
}

void borra(double **&datos){
	for(int i = 0; datos[i]; i++) delete [] datos[i];
}

void borra(int **&datos){
	for(int i = 0; datos[i]; i++) delete [] datos[i];
}

void asigna(int offset, char *formato, char *token, char ***&datosTexto, char ***&datosFecha, int **&datosEnteros, double **&datosReales){
	int entero; char *texto, *fecha;double real;
	if (formato[offset] == 'F') fecha = token; //token ya es dinamico
	else if (formato[offset] == 'R') real = atof(token);
	else if (formato[offset] == 'S') texto = token;
	else if (formato[offset] == 'E') entero = atoi(token);

	int pos = -1; 
	for(int i = 0; i <= offset; i++) if (formato[i] == formato[offset]) pos++;
	if (formato[offset] == 'F') inserta(datosFecha[pos],fecha);
	else if (formato[offset] == 'R') inserta(datosReales[pos],real);
	else if (formato[offset] == 'S') inserta(datosTexto[pos],texto);
	else if (formato[offset] == 'E') inserta(datosEnteros[pos],entero);
}

int datecmp(char *a, char *b){
	int ad,bd,am,bm,ay,by;
	sscanf(a,"%d/%d/%d",&ad,&am,&ay);
	sscanf(b,"%d/%d/%d",&bd,&bm,&by);
	if (ay == by){
		if (am == bm){
			return bd - ad;
		}
		return bm-am;
	}
	return by-ay;
}

bool cumple(char tipo, char condicion, char *datoCondicional, char ***&datosTexto, char ***&datosFecha, int **&datosEnteros, double **&datosReales, int x, int y){
	char *texto = datosFecha[x] != NULL ? datosFecha[x][y] : NULL;
	if (tipo == 'S') if (datosTexto[x] != NULL)  texto = datosTexto[x][y];
	
	int entero = datosEnteros[x] != NULL ? datosEnteros[x][y] : -100; 
	double real = datosReales[x] != NULL ? datosReales[x][y] : -100;
	
	if (tipo == 'S' && texto != NULL){
		if (condicion == '=')	return strcmp(datoCondicional,texto) == 0;
		else if (condicion == '<')	return strcmp(datoCondicional,texto) < 0;
		else if (condicion == '>')	return strcmp(datoCondicional,texto) > 0;
	}else if (tipo == 'F' && texto != NULL){
		if (condicion == '=')	return datecmp(datoCondicional,texto) == 0;
		else if (condicion == '<')	return datecmp(datoCondicional,texto) < 0;
		else if (condicion == '>')	return datecmp(datoCondicional,texto) > 0;
	}
	else if (tipo == 'E' && entero >= 0){
		if (condicion == '=') return entero == atoi(datoCondicional);
		else if (condicion == '<') return entero <= atoi(datoCondicional);
		else if (condicion == '>') return entero > atoi(datoCondicional);
	}else if (tipo == 'R' && real >= 0){
		if (condicion == '=') return real == atof(datoCondicional);
		else if (condicion == '<') return real < atof(datoCondicional);
		else if (condicion == '>') return real > atof(datoCondicional);
	}
	
	return false;
}

void leeDatosInic(char * &formatoEntrada, char &condicion, char * &datoCondicional, int &columnasSalida){
	char aux_formatoEntrada[100],aux_datoCondicional[100];
	scanf("%s\n",aux_formatoEntrada);
	scanf("%c %s\n",&condicion,aux_datoCondicional);
	scanf("%d\n",&columnasSalida);
	formatoEntrada = mydup(aux_formatoEntrada);
	datoCondicional = mydup(aux_datoCondicional);
}
char *leeLinea(char * &linea){
	char aux[100];
	if (!gets(aux)) return NULL;
	return linea = mydup(aux);
}

void separaDatos(char *formatoEntrada, char *linea, char ***&datosTexto, char ***&datosFecha, int **&datosEnteros, double **&datosReales){
	init(formatoEntrada,datosTexto,datosFecha,datosEnteros,datosReales);
	int n = strlen(formatoEntrada);
	for(int i = 0; i < n; i++){
		char *token = NULL;
		linea = mytok(linea,formatoEntrada[i],token);
		asigna(i,formatoEntrada,token,datosTexto,datosFecha,datosEnteros,datosReales);
	}
}



void eliminaCondicion(char *formatoEntrada, char condicion, char *datoCondicional, char ***&datosTexto, char ***&datosFecha, int **&datosEnteros, double **&datosReales){
	char ***copia_datosTexto = NULL ;char ***copia_datosFecha = NULL ; int **copia_datosEnteros = NULL ; double **copia_datosReales = NULL ;
	init(formatoEntrada,copia_datosTexto,copia_datosFecha,copia_datosEnteros,copia_datosReales);
	
	int res = 0;
	char tipo = formatoEntrada[0];
	for(int i = 0; datosFecha[0][i]; i++){
		int F = 0, S = 0, R = 0, E = 0;
		if (cumple(tipo,condicion,datoCondicional,datosTexto,datosFecha,datosEnteros,datosReales,0,i)){
			for(int j = 0; j < strlen(formatoEntrada); j++){
				if (formatoEntrada[j] == 'F') inserta(copia_datosFecha[F],datosFecha[F][i]), F++;
				else if (formatoEntrada[j] == 'E') inserta(copia_datosEnteros[E],datosEnteros[E][i]), E++;
				else if (formatoEntrada[j] == 'R') inserta(copia_datosReales[R],datosReales[R][i]), R++;
				else if (formatoEntrada[j] == 'S') inserta(copia_datosTexto[S],datosTexto[S][i]), S++;
			}
		}
	}
	borra(datosTexto);
	borra(datosFecha);
	borra(datosEnteros);
	borra(datosReales);	
	datosTexto = copia_datosTexto;
	datosFecha = copia_datosFecha;
	datosEnteros = copia_datosEnteros;
	datosReales = copia_datosReales;			
}


void imprimeReporte(char *formatoEntrada,  int columnasSalida, char *datoCondicional,char ***datosTexto, char ***datosFecha, int **datosEnteros, double **datosReales){

	for(int i = 0; datosFecha[0][i]; i++){
		int F = 0, S = 0, R = 0, E = 0;
		for(int j = 0; j < strlen(formatoEntrada); j++){
			if (!esta(j+1, columnasSalida)) continue;
			if (formatoEntrada[j] == 'F') printf("%s\t",datosFecha[F++][i]);
			else if (formatoEntrada[j] == 'E') printf("%d\t",datosEnteros[E++][i]);
			else if (formatoEntrada[j] == 'R') printf("%.3lf\t",datosReales[R++][i]);
			else if (formatoEntrada[j] == 'S') printf("%s\t",datosTexto[S++][i]);
		}
		putchar(10);
	}
}

int main(){
	char *formatoEntrada, condicion, *datoCondicional;
	int columnasSalida;
	char ***datosTexto = NULL, ***datosFecha = NULL;
	int **datosEnteros = NULL;
	double **datosReales = NULL;
	
	leeDatosInic(formatoEntrada,condicion,datoCondicional,columnasSalida);
	
	char *linea = NULL;
	while(leeLinea(linea) != NULL){
		separaDatos(formatoEntrada, linea, datosTexto, datosFecha, datosEnteros, datosReales);
	}
	
	eliminaCondicion(formatoEntrada, condicion, datoCondicional, datosTexto, datosFecha, datosEnteros, datosReales);
	imprimeReporte(formatoEntrada, columnasSalida, datoCondicional, datosTexto, datosFecha, datosEnteros, datosReales);
}
