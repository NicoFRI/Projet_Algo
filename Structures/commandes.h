#ifndef COMMANDE_INC
#define COMMANDE_INC
#include "Menu.h"
typedef struct _commande commande;
typedef commande* Listecommande;     


struct _commande {
       
       int Quantitee;
       plat* platcmd;
       commande* prec;
       commande* suiv;

       };
       
class MesCommandes
{
private:
// d�claration des variable priv�es
Listecommande ListeDesCommandes;

//d�claration des fct priv�es
Listecommande creerListe(void); 
commande* nouvelleCommande(void);
void effacer_liste(Listecommande L);
int longeurChaine();

public:
//d�claration des fct public
MesCommandes();
Listecommande getListe();
void ajouterPlat(Menu* mn);
void ListerCommandes();
void importPlat(plat* Plat);	
void supprimerPlat();

};

#endif // COMMANDE_INC
