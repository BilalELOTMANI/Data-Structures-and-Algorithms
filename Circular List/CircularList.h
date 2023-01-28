#ifndef LISTECIRCULAIRE_H_INCLUDED
#define LISTECIRCULAIRE_H_INCLUDED

typedef struct Box{
	int data;
	struct Box *next;
} Box;

//** Creation d'un nouveau maillon **//

Box * newBox(int v)
{
	Box *p;
	p = (Box*)malloc(sizeof(Box));
	p->data = v;
	p->next = p;
	return p;
}

//**  L'ajout au debut **//

Box *ajouterAuDebut(Box *fin, int v)
{
	Box *p;
	p = newBox(v);
	if(fin==NULL){
		fin=p;
	}else{
		p->next = fin->next;
		fin->next = p;
	}
	return fin;
}

//**  L'ajout à la fin **//

Box *ajouterALaFin(Box *fin, int v)
{
	Box *p;
	p = newBox(v);
	if(fin!=NULL){
		p->next = fin->next;
		fin->next = p;
	}
	fin=p;
	return fin;
}

//**  L'ajout au milieu **//

Box *ajouterAuMilieu(Box *fin, int v, int elem)
{
	Box *p,*temp;
	if(fin!=NULL){
		temp = fin->next;
		do{
		if(temp->data==elem) break;
		temp = temp->next;
		}
		while(temp!=fin->next);

		if(temp->data==elem){
			p=newBox(v);
			p->next = temp->next;
			temp->next = p;

			if(temp == fin) fin=p;
		}
		else printf("L'element %d non existant.",elem);
	}
	return fin;
}

//**  Suppression du debut **//

Box *supprimerAuDebut(Box *fin)
{
	Box *temp;
	if(fin!=NULL){
		temp = fin->next;
		if(temp==fin) fin=NULL;
		else fin->next = temp->next;
		free(temp);
	}
	return fin;
}

//**  Suppression de la fin **//

Box *supprimerLaFin(Box *fin)
{
	Box *temp;
	if(fin!=NULL){
		temp = fin->next;
		if(temp==fin) fin=NULL;
		else{
			while(temp->next!=fin){
				temp=temp->next;
			}
			temp->next = fin->next;
			free(fin);
			fin = temp;
		}
	}
	return fin;
}

//**  Suppression au milieu **//

Box *supprimerAuMilieu(Box *fin, int v)
{
	Box *temp, *temp1;
	if(fin!=NULL){
		temp = fin->next;
		do{
			if(temp->next->data==v) break;
			temp=temp->next;
		}
		while(temp!=fin->next);
		if(temp->next->data==v){
			temp1 = temp->next;
			if(temp==temp1) fin=NULL;
			else{
				temp->next = temp1->next;
				if(temp1==fin) fin=temp;
			}
			free(temp1);
		}

	}
	return fin;
}





//**  Affichage de la liste **//

void afficherListe(Box *fin)
{
	Box *temp;
	if(fin==NULL) printf("La liste est vide.");
	else{
		temp = fin->next;
		do{
			printf("%d",temp->data);
			temp = temp->next;
		}while(temp!=fin->next);
	}
	printf("\n");
}

#endif // LISTECIRCULAIRE_H_INCLUDED
