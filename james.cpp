//incluir las librerias
#include <stdio.h>
//Se crea la estructura a utilizar
typedef struct {
char nombre[25];
char apellido[50];
//agregue el campo edad de tipo entero
}TRegistro;
void InsertarDatos(FILE *fd){
TRegistro alumno;
//se lee el nombre de un alumno y se guarda en el campo correspondiente del
registro
printf("Ingrese el nombre del alumno\n");
scanf("%s",alumno.nombre);
//Agregar la lectura para los otros campos de la estructura
//no ollvide que la edad es un entero y no un arreglo
//debe preocuparse de colocar bien la referencia
fwrite(&alumno,sizeof(TRegistro),1,fd);
}
void Probar(FILE* fd){
//ir al segundo registro
int cant=1;//posicion
TRegistro alumno;
fseek(fd,sizeof(TRegistro)*cant,SEEK_SET);
fread(&alumno,sizeof(TRegistro),1,fd);
printf("\n%s\t%s\t%d\t%li\n",alumno.nombre,alumno.apellido,alumno.edad,ftell(f
d));
rewind(fd);
fread(&alumno,sizeof(TRegistro),1,fd);
printf("\n%s\t%s\t%d\t%li\n",alumno.nombre,alumno.apellido,alumno.edad,ftell(f
d));
}
void VerDatos(FILE *fd){
int i=0;
TRegistro alumno;
fread(&alumno,sizeof(TRegistro),1,fd);
printf("\nPosicion\tNombre\tApellido\tEdad\n");
do{
//completar
printf("\n%d\t%s\n",i,alumno.nombre);
fread(&alumno,sizeof(TRegistro),1,fd);
i++;
}while(!feof(fd));
}
void menu(){
printf("opcion:\n");
printf("\t1: InsertarDatos");
printf("\n\t2: VerDatos");
printf("\n\t3: Salir\n");
}
main(int argc,char* argv[]){
FILE* fd;
int opcion,exit=0;
if (argc==1)
fd=fopen("ArchivoPrueba","a+");
else
fd=fopen(argv[1],"a+");
while(!exit){
menu();
printf("\nOpcion: ");
scanf("%d",&opcion);
switch(opcion){
case 1: InsertarDatos(fd);
break;
case 2: VerDatos(fd);
break;
case 4:Probar(fd);
break;
case 5: exit=1;
break;
default: printf("\nOpcion no valida");
}
}
fclose(fd);
return 1;
}

