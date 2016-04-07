#ifndef RESERVATION_INC
#define RESERVATION_INC
#include "commandes.h"
#include "Menu.h"
typedef struct _reservation reservation;
typedef reservation* ListeReservation;     


struct _reservation {
       
       	time_t date;
       	int nbPersone;
       	char nom[20];
       	reservation* prec;
       	reservation* suiv;
		MesCommandes* cmd;
		
       };
       
class MesReservation 
{
private:
Menu* menu;
ListeReservation ListeResa;
ListeReservation creerListe(void); 
reservation* nouvelleResa(void);
void effacer_liste(ListeReservation L);
int longeurChaine();

public:

MesReservation(Menu* Mn);
ListeReservation getListeResa();
void ajouterReservation();
void ListeReservation();
void importReservation(time_t date, int nbpers, char* nom);	
void supprimerResa();
void ajouterCommandes();
void listerCommandesAssociees();
void listertouteslesCommandesAssociees();
};

#endif // RESERVATION_INC
