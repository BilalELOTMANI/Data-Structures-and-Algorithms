#include <stdio.h>
#include <stdlib.h>
#include "ListeCirculaire.h"

void main()
{
    Box *liste = NULL;
	int nbr,i,v;
	printf("Entrer le nbre des elements: ");
	scanf("%d",&nbr);
	for(i=0; i<nbr; i++){
		scanf("%d",&v);
		liste = ajouterALaFin(liste,v);
	}

	afficherListe(liste);

/*	int a, elem;
	printf("Entrer l'element a ajouter apres: ");
	scanf("%d",&elem);
	printf("Entrer l'element a ajouter: ");
	scanf("%d",&a);
	liste = ajouterAuMilieu(liste,a,elem);  */

	liste = supprimerLaFin(liste);
	afficherListe(liste);

}
