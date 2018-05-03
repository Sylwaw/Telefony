#include <stdio.h>
#include <stdlib.h>

typedef struct
{

}

int main()
{
    printf("Hello world!\n");
    return 0;
}

int wczytaniePliku(char nazwa)
{
    FILE *plik;
    if((plik = fopen(nazwa, "r")) == NULL)
    {
        printf("Blad odczytu pliku");
    }

    else
    {
        fscansf()
    }
}
