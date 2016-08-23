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
    SinEspacios(cadena,' ');//Quita los espacios de la cadena
    Convertir(cadena);//Convierte la cadena a mayusculas
    printf("\n");
    printf("Frase a cifrar: \n\n");
    puts(cadena);
    printf("\n");
    printf("Ingresa el desplazamiento\n");
    scanf("%i",&recorrido);
    fflush(stdin);
    Cifrado(cadena,recorrido);//Cifra la cadena con tantos recorridos
    printf("\n");
    printf("Frase cifrada con un desplazamiento de %i es: \n\n",recorrido);
    puts(cadena);
    printf("\n");
    printf("Frase original es: \n\n");
    Descifrado(cadena,recorrido);//Descifra la cadena
    puts(cadena);
    system("pause");
    return 0;
}

int ValidaCadena(char cadena[])//Funcion que valida si la cadena ingresada es correcta
{                               //Regresa un uno si la cadena es valida y 0 si no.
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

void SinEspacios(char cadena[], char c)//Funcion que elimina los espacios de la cadena
{
	unsigned int i, j;
	for(i = j = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] != c)
            cadena[j++] = cadena[i];
    }
	cadena[j] = '\0';
}

void Convertir(char cadena[])//Convierte la cadena a mayusculas para mayor comodidad
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(cadena[i]>=97 && cadena[i]<=122)
            cadena[i] = cadena[i] - 32;
    }
}

void Cifrado(char cadena[],int recorrido)//Hace el cifrado cesar, los numeros pares se desplazan hacia la derecha 
{                                           //Y los impares hacia la izquierda
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(i%2!=0)//Condicional de los elementos pares/impares de la cadena 
        {
            if((cadena[i]-recorrido)<65)//Con este if se resuelve el problema de desplazamiento 
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

void Descifrado(char cadena[],int recorrido)//descifra la cadena 
{
    int i;
    for(i=0; cadena[i]!='\0'; i++)
    {
        if(i%2!=0)//Igual que la funcion anterior, se necesita conocer los numeros pares/impares para saber como descrifrar
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
