#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Reservation.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

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
	    
	    //initialisation des variables
	    char DateTxT[11];
	    char HeureTxT[6];
		time_t date;
	    
	    int jj;
	    int mm;
	    int aaaa;
	    int hh;
	    int min;
	    
	    int nbPersone;
	    char nom[20];
	    
	    
	    int test=0;
	    
	while(test==0)	  		  	
    {
	    
	   	
	    printf("Entrer la date : (jj/mm/aaaa))");          
       	cin >> DateTxT;
       	
		printf("Entrer l'heure (11h30-13h30 19h-21h) : (hh:mm)");          
       	cin >> HeureTxT;
       	
       	
       	struct tm DateEtHeure;
		
		sscanf (DateTxT,"%d/%d/%d",&jj,&mm,&aaaa);
		sscanf (HeureTxT,"%d:%d",&hh,&min);
  		
	    DateEtHeure.tm_mday = jj;
		DateEtHeure.tm_mon = mm-1;
		DateEtHeure.tm_year = aaaa-1900;
		DateEtHeure.tm_hour = hh;
		DateEtHeure.tm_min = min;	
		DateEtHeure.tm_sec = 0;
       	
       date = mktime(&DateEtHeure);
       	
       	
       	//variable concernant la date du jour (initialise après la saisie pour que les tests ne soit pas faussés)
     	struct tm Today;
		time_t maintenant;
	
		time(&maintenant);
		Today = *localtime(&maintenant);
	
	

	
		int DateValide=0;
   
	    
		//verification de la validité de la date
       	if(mm>0 && mm<12 && aaaa>=Today.tm_year + 1900 && aaaa<=Today.tm_year + 1901){
       			
       		//si le jour est plus petit ou egal au nombre de jour dans le mois  (ici test pour mois à 31 jours) 
			if((mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12 )&& jj<=31) {
				DateValide=1;				
			} 
			
			//sinon test pour mois à 30 jours)
			else if ((mm==4 || mm==6 || mm==9 || mm==11 )&& jj<=30) {
				DateValide=1;
			}
				 
			//pour le mois de février test si l'année est bisssextile ou non
			else if(mm==2) {
			
				//si  bisssextile testpour fevrier à 29 jours
				if(((aaaa % 4 == 0 && aaaa % 100 != 0) || aaaa % 400 == 0)&& jj<=29){
					DateValide=1;
				}
				
				//sinon test pour fevrier à 28 jours
				 else if(jj==28){
	           		DateValide=1;
	        	}
            }
		}
		
		int DateFutur=0;
		
		//si la date est valide
		if (DateValide==1) {
			
			//verifie si la date du jours n'est pas dépassé
			//si année supérieur à l'année en cours c'est bon
			if(aaaa>Today.tm_year + 1900){
				DateFutur=1;
			} 
			
			//sinon si l'année == année en cours
			else if(aaaa==Today.tm_year +1900){
				
				//si la date n'est pas superieur de plus d'un mois de la date du jour, c'est bon
				//(Today.tm_mon+1 == le mois actuel,Today.tm_mon+2==mois suivant)
				if (mm==Today.tm_mon+2 && jj<=Today.tm_mday ) {	
						DateFutur=1;	
				}
				
				//pareil
				else if(mm==Today.tm_mon+1) {	
					if(jj>Today.tm_mday || hh>Today.tm_hour || hh==Today.tm_hour && min>=Today.tm_min){
						DateFutur=1;		
					}
			
				}
			}
		}
		
		//si date est dans le futur (donc valide est pas dépassé)
		if(DateFutur==1){
			//verifie si l'heure conrespond au horaire ou le client peut arriver (11h30-13h30 19h-21h)
			//test pour les horaires du matin (11h30-13h30)  
			if (hh>11 && hh<13 || hh==11 && min>=30 || hh==13 && min <30 )	{
				test =1;	
			}
			//test pour les horaires du matin (19h-21h) 
			else if( hh>=19 && hh<21 ||hh==21 && min==0 ){
				test=1;
			}
									
		}		
    }    
	
       	
	    
	    printf("nb de personnes : (int)");          
       	cin >> nbPersone;
	    
	    printf("a quel nom ?(text)");          
       	cin >> nom;
	    
	
		
	    //printf ("%d/%d/%d %d:%d",DateEtHeure->tm_mday,DateEtHeure->tm_mon,DateEtHeure->tm_year,DateEtHeure->tm_hour,DateEtHeure->tm_min);
	    
	    
	    
		importReservation(date, nbPersone, nom);
 	    
    }
    
    
void MesReservation::ListeReservation()
    {
    	char  format[32];
    	struct tm DateEtHeure;
    	time_t t;
		reservation* r = this->ListeResa;
    	
    	printf("#################################################### \n");
    	
    	while(  r != NULL)
		{
			DateEtHeure = *localtime(&r->date);
			strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
			printf("Reserv. le : %s, pour %i personnes, au nom de : %s \n",format,r->nbPersone,r->nom);
			r = r->suiv;
		}
		
		printf("#################################################### \n");
	}
	
void MesReservation::importReservation(time_t date, int nbpers, char* nom)
	{
	    
	    reservation* res = nouvelleResa();
	    reservation* r = this->ListeResa;
	    
		res->date = date;
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
		char  format[32];
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
			printf("R : %i | le : %i , %i personnes, au nom de : %s \n",cpt ,r->date,r->nbPersone,r->nom);
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
				else if (numSuprr == cpt-1)
				{
					allResa[numSuprr-1]->suiv = allResa[numSuprr]->suiv;
					free(allResa[numSuprr]);
					printf("Supprimer !");		
					return;
				}
				else
				{
					allResa[numSuprr+1]->prec = allResa[numSuprr]->prec;
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
    
