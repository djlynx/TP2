#include <iostream>
using namespace std;

#include <conio.h>	// pour _kbhit() et _getch()
#include <time.h>	// pour time(int)
#include <stdlib.h>	// pour srand(int) et rand()
#include "RockUtiles.h"	// pour la gestion de l'écran

// declaration de variable
const int nbLigne = 30;
const int debutLigne = 0;
const int nbColonne = 70;
const int debutColonne = 0;
int valTouche;
int direction;
int posX=0;
int posY=0;

// Partie I
// --------
void afficherTerrain(int nbLignes, int nbColonnes);
int recupererTouche();
int calculerDirectionTouche(int touche);
void positionAleatoire(int nbLignes, int nbColonnes, int &posX, int &posY);
void deplacerSerpentI(int direction, int &posX, int &posY);

// Partie II
// ---------
int saisirNiveau();
void creerSouris(int nbLignes, int nbColonnes,
	int sourisX[], int sourisY[], int nbSouris);
void afficherSouris(int sourisX[], int sourisY[], int nbSouris);
void deplacerSerpentII(int direction, int serpentX[], int serpentY[],
	int &tailleSerpent,
	int sourisX[], int sourisY[], int &nbSouris);
/*	ou	*/
void deplacerSerpentII(int direction, int serpentX[], int serpentY[],
	int &indiceTete, int &indiceQueue,
	int sourisX[], int sourisY[], int &nbSouris);
bool testerCollision(int x, int y, int sourisX[], int sourisY[], int &nbSouris);


// Partie III (BONUS)
// ------------------
void deplacerSouris(int sourisX[], int sourisY[], int nbSouris);
void placerMurs(int nbLignes, int nbColonnes, int nbMurs);




//  fonction principale
//  -------------------
int main()
{
	resetPalette();
	positionAleatoire(nbLigne,nbColonne,posX,posY);
	afficherTerrain(nbLigne, nbColonne);
	
	valTouche = 0;

	
	do
	{
		valTouche = recupererTouche();
		//cout << valTouche << endl;
		direction = calculerDirectionTouche(valTouche);
		//cout << direction << endl;
		deplacerSerpentI(direction, posX, posY);
		Sleep(500);
	} while (valTouche != 27);
	
	
	
}




// ************
// * PARTIE I *
// ************
void afficherTerrain(int nbLignes, int nbColonnes)
/*
Tâche: afficher le contour du terrain
Paramètres: le nombre de lignes et de colonnes du terrain rectangulaire
*/
{
	setDimensionFenetre(0, 0, nbColonnes+1, nbLignes+1);
	cadre(0, 0, nbColonnes, nbLignes, BACKGROUND_GREEN);
}

int recupererTouche()
/*
Tâche: tester si le joueur a appuyé sur une touche
Retour: retourner le code ASCII de la touche pressée, -1 sinon
*/
{
	// 	utiliser la fonction _kbhit() de conio.h qui retourne une valeur non 
	//	nulle si une touche a été pressée
	//  à compléter
	if (_kbhit!=0)
	{
		return _getch();
	}
	else
	{
		return -1;
	}
		
	
}

int calculerDirectionTouche(int touche)
/*
Tâche: calculer la direction correspondant à une touche ou -1
Paramètre: le code d'une touche (w, a, s ou d ou bien fleche haut, bas , gauche, droite)
Retour: la direction qui correspond à la touche
(0: droite, 1: gauche, 2: haut, 3: bas)
*/
{
	/*int direction =-1;
	// oublie les breaks.
	switch (valTouche)
	{
	case (68):
	case (100):
		direction = 0;
	case (65):
	case (97):
		direction = 1;
	case (87):
	case (119):
		direction = 2;
	case (83):
	case (115):
		direction = 3;

	}*/
	// ajouter toupper (reduire les calculs)

	if (valTouche == 68 || valTouche == 100)
	{
		direction = 0;
	}
	else if (valTouche == 65 || valTouche == 97)
	{
		direction = 1;
	}
	else if (valTouche == 83 || valTouche == 115)
	{
		direction = 2;
	}
	else if (valTouche == 87 || valTouche == 119)
	{
		direction = 3;
	}
	else
	{
		direction = -1;
	}

	return direction;
}

void positionAleatoire(int nbLignes, int nbColonnes, int &posX, int &posY)
/*
Tâche: calculer une position aléatoire sur le terrain
Paramètres: les dimensions du terrain en entrée et les coordonnées de la 				position aléatoire en sortie
*/
{
	srand((unsigned int)time(NULL));
	posX = debutColonne+1 + rand()%(nbColonnes-2);
	posY = debutLigne+1 + rand()%(nbLignes-2) ;

}

void deplacerSerpentI(int direction, int &posX, int &posY)
/*
Tâche: déplacer le serpent d'une seule case dans la direction donnée. Le 			serpent est à l'écran avant l'appel et au retour de la fonction
Paramètres: la direction du serpent en entrée, et la position du serpent en 			entrée / sortie
*/
{
	// tant qu'on appuie sur une nouvelle touche le deplacement s'effectue toujours dans la meme direction
	while(_kbhit == 0 && valTouche!=27)
	{
		switch (direction)
		{
		case(0):
			cout << posX++ << endl;
			break;
		case(1):
			cout << posX-- << endl;
			break;
		case(2):
			cout << posY++ << endl;
			break;
		case(3):
			cout << posY-- << endl;
			break;
		}
		gotoXY(posX, posY);
		cout << char(178);
		Sleep(500);
	}

	
}





// *************
// * PARTIE II *
// *************
int saisirNiveau()
/*
Tâche: lire le niveau de difficulté avec tests de validation d'entrée
Retour: le niveau (= le nombre de souris initialement sur le terrain)
*/
{
	return 0;
}

void creerSouris(int nbLignes, int nbColonnes,
	int sourisX[], int sourisY[], int nbSouris)
	/*
	Tâche: générer les nbSouris aléatoirement sur le terrain
	Paramètres: les dimensions du terrain, les tableaux de coordonnées et le
	nombre de souris
	*/
{
	// à compléter
}

void afficherSouris(int sourisX[], int sourisY[], int nbSouris)
/*
Tâche: afficher les souris
Paramètres: les tableaux de coordonnées et le nombre de souris
*/
{
	// à compléter
}

void deplacerSerpentII(int direction, int serpentX[], int serpentY[],
	int &tailleSerpent,
	int sourisX[], int sourisY[], int &nbSouris)
	/*
	Tâche: déplacer le serpent d'une seule case dans la direction donnée. Le 			serpent est à l'écran avant l'appel et au retour de la fonction
	Paramètres: en entrée : 	la direction du serpent,
	en entrée/sortie :	les tableaux de coordonnées du serpent,
	la taille du serpent,
	les tableaux de coordonnées des souris et
	le nombre de souris
	*/
{
	// à compléter
}

/*	ou	*/

void deplacerSerpentII(int direction, int serpentX[], int serpentY[],
	int &indiceTete, int &indiceQueue,
	int sourisX[], int sourisY[], int &nbSouris)
	/*
	Tâche: déplacer le serpent dans la direction. Le 	serpent est à l'écran avant 		l'appel et au retour de la fonction
	Paramètres: en entrée :	la direction du serpent,
	en entrée/sortie :	les tableaux de coordonnées du serpent, les 				indices de tête et de queue du serpent,
	les tableaux de coordonnées des souris et
	le nombre de souris
	*/
{
	// à compléter
}

bool testerCollision(int posX, int posY,
	int sourisX[], int sourisY[], int &nbSouris)
	/*
	Tâche: tester si (posX, posY) est la position d'une souris. Si oui, retirer
	la souris de la population de souris
	Paramètres: la position de la tête du serpent, les tableaux de coordonnées
	des souris et le nombre de souris
	Retour: true si collision, false sinon
	*/
{
	return 0;
}






// **********************
// * PARTIE III : BONUS *
// **********************

void deplacerSouris(int sourisX[], int sourisY[], int nbSouris)
/*
Tâche: déplacer les souris (aléatoirement ou intelligemment)
Paramètres: les tableaux de coordonnées et le nombre de souris
*/
{
	// à compléter
}

void placerMurs(int nbLignes, int nbColonnes, int nbMurs)
/*
Tâche: placer des murs aléatoirement sur le terrain de jeu
Paramètres: les dimensions du terrain et le nombre de murs à placer
*/
{
	// à compléter
}
