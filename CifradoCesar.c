#include<stdio.h>
#include<stdlib.h>

int ValidaCadena(char cadena[]);
void SinEspacios(char cadena[], char c);
void Convertir(char cadena[]);
void Cifrado(char cadena[],int recorrido);
void Descifrado(char cadena[],int recorrido);

int main()
{
    char cadena[200];
    int recorrido;

    printf("\tCifrado cesar\n\n");
    do
    {
        printf("Ingresa un enunciado\n");
        gets(cadena);

    }while(ValidaCadena(cadena)==0);
    SinEspacios(cadena,' ');
    Convertir(cadena);
    printf("\n");
    printf("Frase a cifrar: \n\n");
    puts(cadena);
    printf("\n");
    printf("Ingresa el recorrido\n");
    scanf("%i",&recorrido);
    fflush(stdin);
    Cifrado(cadena,recorrido);
    printf("\n");
    printf("Frase cifrada con un desplazamiento de %i es: \n\n",recorrido);
    puts(cadena);
    printf("\n");
    printf("Frase original es: \n\n");
    Descifrado(cadena,recorrido);
    puts(cadena);
    return 0;
}

int ValidaCadena(char cadena[])
{
    int i,a=0,b=0;
    for(i=0; cadena[i]!='\0'; i++)
        if(cadena[i]>=0 && cadena[i]<= 127)
            a = a +1;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>=65 && cadena[i]<=90 || cadena[i] == ' ' || cadena[i]>=97 && cadena[i]<=122)
            b = b + 1;
    }
    if(a==b)
        return 1;
    else
        return 0;
}

void SinEspacios(char cadena[], char c)
{
	unsigned int i, j;
	for(i = j = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] != c)
            cadena[j++] = cadena[i];
    }
	cadena[j] = '\0';
}

void Convertir(char cadena[])
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>=97 && cadena[i]<=122)
            cadena[i] = cadena[i] - 32;
    }
}

void Cifrado(char cadena[],int recorrido)
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(i%2!=0)
        {
            if((cadena[i]-recorrido)<65)
                cadena[i] = cadena[i] - recorrido + 26;
            else
                cadena[i] = cadena[i] - recorrido;
        }
        else
        {
            if((cadena[i]+recorrido)>90)
                cadena[i] = cadena[i] + recorrido - 26;
            else
                cadena[i] = cadena[i] + recorrido;
        }
    }
}

void Descifrado(char cadena[],int recorrido)
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(i%2!=0)
        {
            if((cadena[i]+recorrido)>90)
                cadena[i] = cadena[i] + recorrido - 26;
            else
                cadena[i] = cadena[i] + recorrido;
        }
        else
        {
            if((cadena[i]-recorrido)<65)
                cadena[i] = cadena[i] - recorrido + 26;
            else
                cadena[i] = cadena[i] - recorrido;
        }
    }
}
