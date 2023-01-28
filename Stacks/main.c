#include <stdio.h>
#include <stdlib.h>

typedef struct Pile{
    int sommet;
    int taille;
    int pile[50];
} Pile;

int estVide(Pile P)
{
    return P.sommet == 0;
}

int estPleine(Pile P)
{
    return P.sommet == P.taille ;
}

void empiler(Pile *P, int v)
{
    P->pile[P->sommet] = v;
    P->sommet++;
}

int depiler(Pile *P)
{
    return P->pile[--P->sommet];
}


int main()
{
    Pile P1;
    int n;
    P1.sommet = 0;

    printf("Donner la taille de la pile 1: ");
	scanf("%d",&P1.taille);

    while(!estPleine(P1))
    {
        printf("Entrer une valeur a empiler: ");
        scanf("%d",&n);
        empiler(&P1,n);
    }
    while(!estVide(P1))
    {
        printf("%d\n",depiler(&P1));
    }
}
