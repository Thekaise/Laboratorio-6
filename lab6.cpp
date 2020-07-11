//Programa en C de una tabla de simbolos utilizando hashing
//En el cual mi tabla de simbolos lo representare por medio de un arreglo, que comprendera valores de hash, atributos, y su identifacion o clave
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11

char l[10];

struct symb
{
int add;
char atributo[10];
}sy[11];

void search();

int main()
{
int a[MAX],num,key,i,ch; //variables
char ans;
int create(int);            //funcion crear
void lprob(int [],int,int); //funcion de colocar
void mostrar_tabla(int []); //funcion de mostrar
system("cls");
for(i=0;i<MAX;i++)          //Recorrido de la tabla de simbolos en el arreglo
a[i]=0;
do
{
printf("\nMENU de la tabla de simbolos:\n 1.crear una tabla de simbolos\n 2.Buscar en la tabla de simbolos\n");
printf("Ingrese su opcion: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
do
{
printf("\nIngrese el identificador:");
scanf("%d",&num);
key=create(num);
printf("Ingrese el atributo:");
scanf("%s",l);
lprob(a,key,num);
printf("\nDesea continuar(s/n)?");
ans=getche();
}
while(ans=='s');
mostrar_tabla(a);//mostrar los valores hash, atributos y claves
break;
case 2:
search();//llama de la funcion busqueda de la clave que diferencia los atributos agregados
break;
}
}while(ch<=2);
return 0;
}
 
int create(int num) 
{
int key;
key=num%11;
return key;
}
 
void lprob(int a[MAX],int key,int num)//Funcion que permite hacer el llenado de los valores hash, atributos y clavrs
{
int flag,i,count=0;
void mostrar_tabla(int a[]); //llama a la funcion de mostrar tabla y se verifica que este vacía la tabla. Si lo esta se procede el llenado.
flag=0;
if(a[key]==0)//Condición para verificar que este vacía la tabla
{
a[key]=num;
sy[key].add=num;
strcpy(sy[key].atributo,l);//copia los elementos agregados a el arreglo
}
else
{
i=0;
while(i<MAX)//mientra los elementos agregados no sobrepasen el tope, continua agregando
{
if(a[i]!=0)
count++;
i++;
}
if(count==MAX)//Si se llega al tope, tabla llena
{
printf("\nLa Tabla está llena ");
mostrar_tabla(a);
getch();
exit(1);
}
for(i=key+1;i<MAX;i++)
if(a[i]==0)
{
a[i]=num;
flag=1;
sy[key].add=num;
strcpy(sy[key].atributo,l);
break;
}
for(i=0;i<key && flag==0;i++)
if(a[i]==0)
{
a[i]=num;
flag=1;
sy[key].add=num;
strcpy(sy[key].atributo,l);
break;
}
}
}

void mostrar_tabla(int a[MAX])// Funcion que permite mostrar la tabla de los elementos agregados
{
FILE *fp;
int i;
fp=fopen("symbol.txt","w");
printf("\nLa tabla de simbolo es: ");
printf("\nValores de la tabla         claves          atributos\n");
for(i=0;i<MAX;i++)
{
printf("\n%d\t                      %d\t        %s",i,sy[i].add,sy[i].atributo);
fprintf(fp,"\n%d %d %s",i,sy[i].add,sy[i].atributo); //Para un algoritmo
}
fclose(fp);
}/*Existen lineas de codigos que no tienen relevancia, ya que esta intentando leer un archivo txt que contenia lineas de codigo
   para posteriormente identificar su clave, .. etc.Pero tuve unos problemas para poder hacerlo. Es por eso que puede ver funciones 
   de leer archivo y recorrido del archivo*/
 
void search()// Funcion que permite encontrar un atributo, segun su clave unica
{
FILE *fp1;
char la[10];
int set=0,s;
int j,i;
printf("Ingrese el atributo que quiera encontrar: ");
scanf("%s",la);
fp1=fopen("symbol.txt","r");
for(i=0;i<MAX;i++)
{
fscanf(fp1,"%d%d",&j,&sy[i].add);
if(sy[i].add!=0)
fscanf(fp1,"%s",sy[i].atributo);
}
for(i=0;i<MAX;i++)//Recorriendo el arreglo de la tabla de simbolo
{
if(sy[i].add!=0)
{
if(strcmp(sy[i].atributo,la)==0)
{
set=1;
s=sy[i].add;
}
}
}
if(set==1)
printf("\nEl atributo o conjunto de simbolo --%s-- esta presente en la tabla de simbolo con la clave:%d\n",la,s);
else
printf("\nEl atributo o conjunto de simbolo no esta presente en la tabla de simbolo\n");
}

//Dentro de esta funcion tambien estan presentes algunas lineas de codigo que no son relevante para la funcion del programa

/*Este programa lo realice tomando en consideracion la explicacion que hizo en la clase que hablaba sobre las tablas hash
  lo que hice fue guiarme del concepto de una estructura de datos que comprender la tabla de simbolos. Es por eso que solo se
  ingresan como claves datos numericos y como atributos cadenas de caracteres. Esto programa realiza las funciones básicas, agregar a la tabla,
  mostrar tabla, buscar elementos segun el atributo, mostrar la clave del atributo, y decir si la tabla esta llena.
  
  Datos a tomar en cuenta en la compilacion del programa:
  1. Al momento de agregar los elementos a la tabla de simbolos(representada como un arreglo de una capacidade 10 celdas). En la clave
     o identificador tiene que ingresar solo datos numericos, y en el atributo si puede ser cualquier tipo de caddena de caracteres.
  2. Solo puede ingresar 11 elementos, que comprenden los identificadores y atributos. Si se sobrepasa el tope, el compilador le mostrara
     que la cadena esta llena.
  3. ALGO MUY A TOMAR EN CUENTA, que cuando vaya agregando datos a la tabla de simbolos, especificamente cuando aniada elementos de 
     identificadores. los numeros deben ser ingresados de manera contable.
     Por ejemplo:
     ingrese identificador: 1000
     ingrese atributo: abbbasbsa
     desea continuar (s/n)?:s
     ingrese identificador: 1003
     ingrese atributo: amcdanksm12
     desea continuar (s/n)?:s
     ingrese identificador: 1007
     ingrese atributo: ajdnkandjs122
     .
     .
     .
     .
     .
    Si coloca un numero menor(identificador) que el anterior, no aparecerá dentro de la tabla!!!*/
    //Seguire trabajando para poder leer el archivo fuente txt, y utilizar este programa para distribuir cada elemento como corresponde
    
    //KAISER OBALDÍA 8-898-703
    
 
