#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Reservation.h"
using namespace std;

ListeResevation  MesReservation::creerListe(void)
{
	return NULL;
}
 
reservation* MesReservation::nouvelleResa(void)
{
	reservation* res = (reservation*) malloc(sizeof(reservation));
	res->suiv = NULL;
	return res;
}

void MesReservation::effacer_liste(ListeResevation L)
{
	while( L != NULL)
	{
		reservation* r = L;
		L = L->suiv;
		free(r); 
	}
}

MesReservation::MesReservation()
 {
 	this->ListeResa = creerListe();
 }
 
void MesReservation::ajouterReservation(){
	    
	    reservation* res = nouvelleResa();
	    printf("Date : (int))");          
       	cin >> res->date;
       	
		printf("heurre : (int)");          
       	cin >> res->heurre;
	    
	    printf("nb de personnes : (int)");          
       	cin >> res->nbPersone;
	    
	    printf("a quel nom ?(text)");          
       	cin >> res->nom;
       	
	    res->suiv = this->ListeResa;
	    this->ListeResa = res;

    }
    
    
void MesReservation::ListeReservation()
    {
    	reservation* r = this->ListeResa;
    	
    	while(  r != NULL)
		{
		printf("%i %i %i %s",r->date,r->heurre,r->nbPersone,r->nom);
		r = r->suiv;
		}

	}
	

