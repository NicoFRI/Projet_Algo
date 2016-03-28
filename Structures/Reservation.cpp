#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Reservation.h"
#include <string>

using namespace std;

ListeReservation MesReservation::creerListe(void)
	{
		return NULL;
	}
 
reservation* MesReservation::nouvelleResa(void)
	{
		reservation* res = (reservation*) malloc(sizeof(reservation));
		res->suiv = NULL;
		res->prec = NULL;
		return res;
	}

void MesReservation::effacer_liste(reservation* L)
	{
		while( L != NULL)
		{
			reservation* r = L;
			L = L->suiv;
			free(r); 
		}
	}
	

ListeReservation MesReservation::getListeResa()
{
	return this->ListeResa;
}

MesReservation::MesReservation()
	 {
	 	this->ListeResa = creerListe();
	 }
 
void MesReservation::ajouterReservation(){
	    
	    int date;
	    int heure;
	    int nbPersone;
	    char nom[20];
	      		
	    printf("Date : (int))");          
       	cin >> date;
       	
		printf("heure : (int)");          
       	cin >> heure;
	    
	    printf("nb de personnes : (int)");          
       	cin >> nbPersone;
	    
	    printf("a quel nom ?(text)");          
       	cin >> nom;
	    
	    
	    importReservation(date, heure, nbPersone, nom);
 	    


    }
    
    
void MesReservation::ListeReservation()
    {
    	reservation* r = this->ListeResa;
    	
    	printf("#################################################### \n");
    	
    	while(  r != NULL)
		{
		printf("Reservation Pour le : %i - %i H, %i personnes, au nom de : %s \n",r->date,r->heure,r->nbPersone,r->nom);
		r = r->suiv;
		}
		
		printf("#################################################### \n");
	}
	
void MesReservation::importReservation(int date, int heure, int nbpers, char* nom)
	{
	    
	    reservation* res = nouvelleResa();
	    reservation* r = this->ListeResa;
	    
		res->date = date;
		res->heure = heure;
	    res->nbPersone = nbpers;
	    strcpy(res->nom,nom);
	           	
	    if (r == NULL)
       	{
			res->suiv = r;
		    this->ListeResa = res;
		    return;
	    }
	    else
	    {
				    
	     	while((res->date > r->date) && (r->suiv != NULL))
			{
				r = r->suiv;
			}
			
			if (res->date >= r->date)
			{
				
				res->suiv = r->suiv;
				res->prec = r;
				
				if (not(r->suiv == NULL))
				{
					r->suiv->prec = res;
				}
					
				r->suiv = res;
				
			} 
			else
			{
				
				res->suiv = r;
				res->prec = r->prec;
				
				if (r->prec == NULL)
					this->ListeResa = res;
				else
					r->prec->suiv == res;
					
				r->prec = res;
			}
		

			
			return;
		}

    }
    
int MesReservation::longeurChaine()
	{
		reservation* r = this->ListeResa;
		int cpte = 0;
		
		while(  r != NULL)
		{
		cpte++;
		r = r->suiv;
		}
		
		return cpte;
	}

   
void MesReservation::supprimerResa()
	{
		if (longeurChaine() > 0)
		{
			
		    reservation* r = this->ListeResa;
	    	reservation* allResa[longeurChaine()];
	    	int cpt = 0;
	    	int numSuprr = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			allResa[cpt] = r;
			cpt++;
			printf("R : %i | le : %i - %i H, %i personnes, au nom de : %s \n",cpt , r->date,r->heure,r->nbPersone,r->nom);
			r = r->suiv;
			}
			
			printf("#################################################### \n");
			
			
			printf("Sélectioner le N° de la reservation a supprimer (0 pour annuler) :  ");
			cin >> numSuprr;
			
			if (numSuprr == 0)
			{
				printf("Anulation \n");
				
				return;
			}
			else if (numSuprr > cpt)
			{
				printf("pas de reservation a ce numero \n");
				
				return;
			}
			else
			{
				numSuprr--;
				
				if (numSuprr == 0)
				{
					this->ListeResa = allResa[numSuprr]->suiv;
					free(allResa[numSuprr]);
					printf("done !");
					return;
				}
				else
				{
					allResa[numSuprr-1]->suiv = allResa[numSuprr]->suiv;
					free(allResa[numSuprr]);
					printf("Supprimer !");		
					return;
				}
	
			}
		}
		else
		{
			printf("rien a afficher");
		}
	}
    
