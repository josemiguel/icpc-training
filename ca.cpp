#include <string.h>
#include<stdio.h>
#include <stdlib.h>
void devuelve_valores(char *linea,char *&desc_t,int &stock_t,double &pu_t,char *&desc)
{
    char *str,*str1;

    strcpy(linea,linea+7);
    //saltamos los 7 caracteres que ya fueron leidos
    str1=linea;
    while (*str1==' ') str1++;
    //linea=str;
    //eliminamos los espacios en blanco iniciales
    str=&linea[strlen(linea)-1];
    while (*str==' ') {*str=0;str--;}
    //ya eliminamos los espacios en blanco finales
    while (*str!=' ') str--;
    *str=0;
    str++;
    //str esta en el inicio del numero;
    pu_t=atof(str);
    str-=2; //antes del 0 puesto anteriormente
    while (*str==' ') {*str=0;str--;}
    while (*str!=' ') str--;
    *str=0;
    str++;
    stock_t=atoi(str);
    while (*str==' ') {*str=0;str--;}
    //linea ya contiene unicamente la descripcion
    desc=new char [strlen(str1+1)];
    strcpy(desc,str1);
}
int busca(char **codigo,char *cod)
{
    int cont=0;
    while (codigo[cont]!=NULL) if (strcmp(codigo[cont],cod)==0) return cont; else cont++;
    return -1;//en caso de error

}
void crea_estructuras(char **&codigo,char**&descripcion,int *&stock,double *&pu,double **&montos)
{
    char *cod_t[200],*desc_t[200],cod[8],*desc,linea[300];
    int stock_t[200],cont=0;
    double pu_t[200];

    while (1)
    {
       gets(linea);
       if (strcmp(linea,"******")==0) break;
       else
       {
           strncpy(cod,linea,7);
           cod[7]=0;
           cod_t[cont]=new char [7];
           strcpy(cod_t[cont],cod);
           //cod_t[cont][8]=0;
           devuelve_valores(linea,desc_t[cont],stock_t[cont],pu_t[cont],desc_t[cont]);
           cont++;
       }
    }
    //terminos de cargar todo como estructura estatica
    codigo=new char*[cont+1];
    for (int i=0;i<cont;i++) codigo[i]=cod_t[i];
    codigo[cont]=NULL;
    descripcion=new char*[cont+1];
    for (int i=0;i<cont;i++) descripcion[i]=desc_t[i];
    descripcion[cont]=NULL;
    stock=new int[cont+1];
    for (int i=0;i<cont;i++) stock[i]=stock_t[i];
    stock[cont]=-1;
    pu=new double[cont+1];
    for (int i=0;i<cont;i++) pu[i]=pu_t[i];
    pu[cont]=-1;
    //solo faltaria cargar montos
   int fin=1;
   double monto_t;
   montos=new double *[cont+1];
   for (int i=0;i<cont+1;i++) montos[i]=NULL;
   //inicializamos la estructura y le colocamos el null al final
   while (fin!=EOF)
   {
       int posi;
       scanf("%s",cod);
       posi=busca(codigo,cod);
       if (montos[posi]==NULL)
       {
           montos[posi]=new double[10];
           montos[posi][0]=10;
           montos[posi][1]=0;
       }

       while ((fin=scanf("%lf",&monto_t))>0)
       {
          if ((int)montos[posi][1]<(int)montos[posi][0])
          {
              //insertamos el monto
              montos[posi][(int)montos[posi][1]+2]=monto_t;
              montos[posi][1]=montos[posi][1]+1;
          }
          else
          {

              double *temp,*q;
              
              temp=new double[(int)montos[posi][0] + 10];
              q=montos[posi];
              for (int i=0;i< (int) montos[posi][1] + 2 ; i++) temp[i]=montos[posi][i];
          	  puts("antes");              
			  delete [] q;
			  puts("despues");
              montos[posi]=temp;
              montos[posi][0]+=10;
              montos[posi][(int)montos[posi][1]+2]=monto_t;
              montos[posi][1]=montos[posi][1]+1;i
          }
       }

   }
}
void actualiza_stock(char **codigo,char **descripcion,int *stock,double *pu,double**montos)
{
    int i=0,j=0,cant;
    double suma;
    while (montos[i]!=NULL)
    {
        suma=0;
        cant=(int)montos[i][1];
        for (j=2;j<cant+2;j++) suma+=montos[i][j];
        stock[i]-=(int)(suma/pu[i]);
        printf("%s %s %d %lf\n",codigo[i],descripcion[i],stock[i],pu[i]);
        i++;
    }

}

int main(void) {
    char **codigo,**descripcion;
    int *stock;
    double **montos,*pu;
    crea_estructuras(codigo,descripcion,stock,pu,montos);
    actualiza_stock(codigo,descripcion,stock,pu,montos);
    putchar('\n');

    return 0;
}

