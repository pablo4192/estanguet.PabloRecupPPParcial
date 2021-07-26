#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 8

typedef struct{
int id;
char procesador[20];
char marca[20];
float precio;
}eNotebook;

float calcularIva(float precioBruto);

int ordenarNotebooks(eNotebook lista[], int tam);

int reemplazarCaracter(char cadena[], char caracterARemplazar, char nuevoCaracter);

int main()
{

    //Funcion 1:
    float precio=100;
    float porcentajeDeIva;

    porcentajeDeIva=calcularIva(precio);
    printf("El IVA que tiene que pagar de los $%.2f es: $%.2f\n", precio, porcentajeDeIva);
    printf("\n");

    //Funcion 2:
    char cadena[20]="palabra";
    int cantidadVecesRemplazo;


    cantidadVecesRemplazo=reemplazarCaracter(cadena, 'a', 'z');
    printf("%s\n", cadena);
    printf("La cantidad de veces que se remplazo el caracter es: %d\n", cantidadVecesRemplazo);
    printf("\n");

    //Funcion 3:
    eNotebook notebooks[TAM]={
    {123, "intel", "pentium", 20000},
    {156, "pepe", "compaq", 15000},
    {122, "celeron", "astra", 50000},
    {121, "juju", "larret", 30000},
    {120, "dede", "larret", 10000},
    {126, "sason", "astra", 8000},
    {129, "qioy", "astra", 40000},
    {124, "geur", "larret", 90000}
    };

    printf("id   procesador     marca   precio\n");
    for(int i=0; i<TAM; i++)
    {
        printf("%d  %10s  %10s  %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }
    printf("\n\n");

    ordenarNotebooks(notebooks, TAM);
    printf("id   procesador     marca   precio\n");
    for(int i=0; i<TAM; i++)
    {
        printf("%d  %10s  %10s  %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }

    return 0;
}

/*
1. Crear una función llamada calcularIVA que reciba como parámetro el precio bruto de un producto y
devuelva el valor del impuesto (el IVA es 21%). Realizar la llamada desde main. *
*/

float calcularIva(float precioBruto)
{
    return precioBruto*0.21;
}

/*
2. Crear una función que se llame reemplazarCaracter que reciba una cadena de caracteres como primer parámetro,
como segundo parámetro el carácter a reemplazar y como tercero el nuevo carácter y devuelva la cantidad
de veces que se reemplazo el carácter. int reemplazarCaracter(char [], char, char);
*/

int reemplazarCaracter(char cadena[], char caracterARemplazar, char nuevoCaracter)
{
    int contadorRemplazos=0;
    int tam=strlen(cadena);

    if(cadena!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(cadena[i]==caracterARemplazar)
            {
                cadena[i]=nuevoCaracter;
                contadorRemplazos++;
            }
        }
    }
    return contadorRemplazos;
}

/*
3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
de dicha estructura por marca.
Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
*/

int ordenarNotebooks(eNotebook lista[], int tam)
{
    int retorno=0;
    eNotebook aux;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca)>0 || (strcmp(lista[i].marca, lista[j].marca)==0 && lista[i].precio>lista[j].precio))
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}
