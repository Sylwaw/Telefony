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

linijka* WczytajZPliku(linijka* glowa, char *nazwa)
{
    linijka *tmp, *nowy;
    //tmp = glowa;
    char bufor[30];
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
                glowa = nowy;
            }
            else
            {
                tmp = glowa;
                while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = nowy;
            }

        }
        printf("Plik zostal poprawnie wczytany\n");
    }
    fclose(plik);
    //WyswietlListe(glowa);
    return glowa;
}

void WyswietlListe(linijka* glowa)
{
    linijka* tmp;
    tmp = glowa;
    if(tmp == NULL)
    {
        printf("Lista jest pusta");
    }
    while(tmp != NULL)
    {
        printf("Osoba: %s\n", tmp->osoba);
        printf("Telefon: %s\n", tmp->telefon);
        tmp = tmp->next;
    }
}

int main()
{
    linijka* glowa = NULL;
    linijka* glowa2;
    glowa2 = WczytajZPliku(glowa, "Plik.txt");
    WyswietlListe(glowa2);
    return 0;
}



