#include <stdio.h>
#include <stdlib.h>

//** Créer la structure du noeud de la ABR **//

typedef struct BstNode{
	int data;
	struct BstNode *right;
	struct BstNode *left;
} BstNode;

//** Créer nouveau noeud dans le heap **//

BstNode *newNode(int a)
{
	BstNode *newNode;
	newNode = (BstNode*)malloc(sizeof(BstNode));
	newNode->data = a;
	newNode->right = newNode->left = NULL;
	return newNode;
}

//** Insertion de donnée dans la ABR (With Recursion) **//


BstNode *insert(BstNode *root, int a)
{
	if(root == NULL){     // empty tree
		root = newNode(a);
	}
	else if(a <= root->data){
		root->left = insert(root->left,a);
	}
	else{
		root->right = insert(root->right,a);
	}
	return root;
}

//** Recherche d'un element (With Recursion) **//

int search(BstNode *root,int a)
{
	if(root == NULL){
		return 0;
	}
	else if(root->data == a){
		return 1;
	}
	else if(a <= root->data){
		return search(root->left,a);
	}
	else{
		return search(root->right,a);
	}
}

//** Recherche d'un element (With Iteration) **//

int searchIte(BstNode *root, int a)
{
	int trouve = 0;
	while(root != NULL && !trouve){
		if(root->data == a) trouve = 1;
		else if(root->data < a) root = root->right;
		else root = root->left;
	}
	return trouve;
}


//** Recherche du Min (Iterative) **//

int MinIte(BstNode *root)
{
	if(root == NULL){
		printf("L'arbre est vide !!!");
		return -1;
	}
	BstNode *temp;
	temp = root;
	while(root->left != NULL){
		temp = root->left;
	}
	return temp->data;
}

//** Recherche du Min (Recursive) **//

int MinRec(BstNode *root)
{
	if(root == NULL){
		printf("L'arbre est vide !!!\n");
		return -1;
	}
	else{
		return root->data;
	}
	return MinRec(root->left); // search in left subtree
}

//** Recherche du Max (Iterative) **//

int MaxIte(BstNode *root)
{
	if(root == NULL){
		printf("L'arbre est vide !!!");
		return -1;
	}
	BstNode *temp;
	temp = root;
	while(root->right != NULL){
		temp = root->right;
	}
	return temp->data;
}

//** Recherche du Max (Recursive) **//

int MaxRec(BstNode *root)
{
	if(root == NULL){
		printf("L'arbre est vide !!!\n");
		return -1;
	}
	else{
		return root->data;
	}
	return MinRec(root->right);
}

//** Max de 2 nombres **//

int max(int a,int b)
{
    if(a <= b) return b;
    else return a;
}

//** La hauteur d'un arbre **//

int Height(BstNode *root)
{
	if(root == NULL){
		return -1;
	}
	return max(Height(root->left),Height(root->right))+1;
}


//** Parcours d'un arbre -Preordre- **//

void Preorder(BstNode *root)
{
	if(root == NULL) return;

	printf("%d\t",root->data);
	Preorder(root->left);   // Visit left subtree
	Preorder(root->right);  // Visit right subtree
}


//** Parcours d'un arbre -Inordre- **//

void Inorder(BstNode *root)
{
	if(root == NULL) return;

	Inorder(root->left);
	printf("%d\t",root->data);
	Inorder(root->right);
}

//** Parcours d'un arbre -Postordre- **//

void Postorder(BstNode *root)
{
	if(root == NULL) return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%d\t",root->data);
}

//** Check if a binary tree is a BST **//

int isBstUtil(BstNode *root, int minVal, int maxVal)
{
	if(root == NULL) return 1;

	if(root->data < minVal && root->data > maxVal
	 && isBstUtil(root->left,minVal,root->data)
	 && isBstUtil(root->right,root->data,maxVal)){
	 	return 1;
	 }

	 else return 0;
}

int isBst(BstNode *root)
{
	return isBstUtil(root,INT_MIN,INT_MAX);
}


//** Supprimer un noeud d'un arbre binaire de recherche **//

// Creation d'une fonction Min qui retourne un pointeur vers un noeud, MinIte() retourne la valeur donc pas utile ici

BstNode *Min(BstNode *root)
{
    BstNode *temp = root;
    while(root->left != NULL){
        temp = root->left;
    }
    return temp;
}


BstNode *Delete(BstNode *root, int a)
{
	if(root == NULL) return root;
	else if(a < root->data){
		root->left = Delete(root->left,a);
	}
	else if(a > root->data){
		root->right = Delete(root->right,a);
	}
	else{
		// Case 1 : No child
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		// Case 2 : One child
		else if(root->left == NULL){
			BstNode *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL){
			BstNode *temp = root;
			root = root->left;
			free(temp);
		}
		// Case 3 : 2 children
		else{
			BstNode *temp;
			temp = Min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

//** Nbre des noeuds d'un arbre **//

int nbrNodes(BstNode *root)
{
	if(root == NULL) return 0;
	else{
		return 1 + nbrNodes(root->left) + nbrNodes(root->right);
	}
}

/*

// ** Nbre des noeuds d'un arbre iterative ** //

int nbNodesIter(BstNode *root)
{
	int t =0;
	initpilevide();
	while(root || !estVide(P)){
		while(root){
			t++;
			empiler(root);
			root = root->left;}
			depiler(P);
			root = root->right;
		}

	return t;
}

*/

//** Nbre des feuilles d'un arbre **//

int nbrLeaf(BstNode *root)
{
	if(root == NULL) return 0;
	else if(root->left == NULL && root->right == NULL) return 1;
	else{
		return nbrLeaf(root->left) + nbrLeaf(root->right);
	}
}



int main()
{
	BstNode *root = NULL; // Création d'un arbre vide

	/*On va creer l'arbre binaire de recherche suivante
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */

	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4);
	root = insert(root,1); root = insert(root,11);



	printf("Preordre: ");
	Preorder(root);
	printf("\n");



	root = Delete(root,3);

	printf("Inordre: ");
	Inorder(root);
	printf("\n\n");

	int a = searchIte(root,20);
	printf("%d",a);





}













