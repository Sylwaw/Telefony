#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LINIJKA linijka;
struct LINIJKA
{
    char osoba[30];
    char telefon[20];
    linijka* next;
};

void WczytajZPliku(linijka* glowa, char *nazwa)
{
    linijka *tmp, *nowy;
    //tmp = glowa;
    char bufor[30+1];
    FILE* plik = fopen(nazwa, "r");
    if(plik == NULL)
    {
        printf("Blad odczytu pliku");
    }
    else
    {
        while(fscanf(plik, "%s", bufor) != EOF)
        {
            nowy = (linijka*)malloc(sizeof(linijka));
            nowy->next = NULL;
            strcpy(nowy->osoba, bufor);
            fscanf(plik, "%s", bufor);
			strcpy(nowy->telefon, bufor);

			if (glowa == NULL)
            {
                nowy = glowa;
            }
            else
            {
                tmp = glowa;
                while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = nowy;
            }

        }
        printf("Plik zostal poprawnie wczytany");
    }
    fclose(plik);
}

int main()
{
    linijka* glowa = NULL;
    WczytajZPliku(glowa, "plik.txt");

    return 0;
}



