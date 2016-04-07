// include std
#include <cstdlib>
#include <iostream>

//include des autres class
#include "Reservation.h"
#include "commandes.h"
#include "menu.h"

using namespace std;

// Constructeur de class - lance l'initialisation de la chaine.
MesCommandes::MesCommandes()
	{
		this->ListeDesCommandes = creerListe();
	}

// initialisation de la liste ( a NULL )	
Listecommande MesCommandes::creerListe(void)
	{
		return NULL;
	}

// alocation mémoire pour une nouvelle commande
commande* MesCommandes::nouvelleCommande(void)
	{
		commande* cmd = (commande*) malloc(sizeof(commande));
		cmd->suiv = NULL;
		cmd->prec = NULL;
		cmd->platcmd = NULL;
		cmd->Quantitee =0;
		return cmd;
	}

// renvois la liste des commandes.	
Listecommande MesCommandes::getListe()
	{
		return this->ListeDesCommandes;
	}

// calcul et renvois la longeur de la chaine	
int MesCommandes::longeurChaine()
	{
		Listecommande c = this->ListeDesCommandes; // recupere la liste des commandes
		int cpte = 0; // int du compteur
		
		while(  c != NULL) //tant que on est pas a la fin de la chaine
		{
			cpte++; // incrémente le compteur
			c = c->suiv; //passe a la commande suivante
		}
		
		return cpte; // renvois la longueur de la chaine.
	}
	
//liste les commandes
void MesCommandes::ListerCommandes()
    {

		Listecommande c = this->ListeDesCommandes; // recupere la liste des commandes
    	
    	printf("-------------------------------------------------------- \n"); //séparateur visuel
    	
    	while(  c != NULL) //tant que il y as des commande dans la liste
		{
			//affiche le nom du plat, la qté, le prix Unitaire et le total.
			printf("| %s  x%i  Prix /U %f  Total : %f€ \n",c->platcmd->Nom_Plat,c->Quantitee,c->platcmd->Prix,c->Quantitee*c->platcmd->Prix); 
			c = c->suiv; // passe a la commande suivante
		}
		
		printf("--------------------------------------------------------- \n");
	}	


void MesCommandes::importPlat(plat* Plat)
	{
		
		Listecommande c = this->ListeDesCommandes; // recupere la liste des commandes
		bool ajouter = false;	// par dégaut le plat n'est pas ajouté.
				
		while(  c != NULL) //tant que on est pas a la fin de la chaine
		{
			if (Plat->Nom_Plat == c->platcmd->Nom_Plat) // si le plat a déja été commandé
				{
					c->Quantitee = c->Quantitee +1; // augmente la qté associé
					ajouter = true; // indique que le plat a été ajouter
					break; // termine la boucle
				}
			c = c->suiv; //passe a la commande suivante
		}
		
		if (ajouter == false) //si la plat n'a pas été ajouté
		{
			commande* cmd = nouvelleCommande(); //demande un nouvelle commande
			cmd->platcmd = Plat; //défini la plat de la commande
			cmd->Quantitee = 1; // passe la qté a 1
			cmd->suiv = this->ListeDesCommandes; //défini la liste comme élément suivant de la comande
			this->ListeDesCommandes = cmd; //insert la nouvelle commande en tete de liste
			if (cmd->suiv != NULL) cmd->suiv->prec = cmd; //si l'élement suivant n'est pas la fin de liste, place la nouvelle commande en précédent.
		}

	}
	
void MesCommandes::ajouterPlat(Menu* mn) //ajouter un plat issue du menu a la commande
	{
		if (mn->getlongeurChaine() > 0) //si y'a des plat dans le menu
		{
			
		    plat* p = mn->getListeMn(); //initialise la liste des plat
	    	plat* allMn[mn->getlongeurChaine()]; //pour chaque menu
	    	int cpt = 0; //init du compteur
	    	int select = 0; // init du selecteurs
	   	
	   	
	    	printf("---------------------------------------------------- \n");
	    	
	    	while(  p != NULL) //tant qu'il y as des plats
			{
			allMn[cpt] = p; // met un index que chaque plat.
			cpt++; //incrémente la plat
			printf("[%i] : %s \n",cpt,p->Nom_Plat); //affiche le N° de l'index et le nom du plat

			p = p->suiv; //plat suivant
			}
			
			printf("---------------------------------------------------- \n");
			
			
			printf("Sélectioner le N° du plat (0 pour annuler) :  "); //demande de selection
			cin >> select;
			
			if (select==0) return; // si on annule : sorti de la fct.
			
			select--; // elece 1 au selecteur pour coller a l'index tableau affiché
			importPlat(allMn[select]); //import le plat.
		}
	}

	
