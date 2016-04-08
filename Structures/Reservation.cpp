#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Reservation.h"
#include "commandes.h"
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Menu.h"

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
		res->cmd = NULL;
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

MesReservation::MesReservation(Menu* Mn)
	 {
	 	this->ListeResa = creerListe();
	 	this->menu = Mn;
	 }
 
void MesReservation::ajouterReservation(){
	    
    //initialisation des variables
    int nbDeCouvertMAX = 26;
    
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
    
    
    //variable pour verifier capacité du resto
    char  format[32];
	
	char  jour[3];
	int jourListe;
	
	char  mois[3];
	int moisListe;
	
	char  annee[5];
	int anneeListe;
	
	char  heure[3];
	int heureListe;
	
	char  minute[3];
	int minuteListe;
	
	long convertir;
	
	struct tm DateEtHeure;
	time_t t;
    
     int personnePresente; 
    int test=0;
	    
	while(test==0)	  		  	
    { 	
	    printf("Entrer la date : (jj/mm/aaaa))");          
       	cin >> DateTxT;
       	
		printf("Entrer l'heure (11h30-13h30 19h-21h) : (hh:mm)");          
       	cin >> HeureTxT;
       	
       	
       	struct tm DateEtHeureSaisie;
		
		sscanf (DateTxT,"%d/%d/%d",&jj,&mm,&aaaa);
		sscanf (HeureTxT,"%d:%d",&hh,&min);
  		
	    DateEtHeureSaisie.tm_mday = jj;
		DateEtHeureSaisie.tm_mon = mm-1;
		DateEtHeureSaisie.tm_year = aaaa-1900;
		DateEtHeureSaisie.tm_hour = hh;
		DateEtHeureSaisie.tm_min = min;	
		DateEtHeureSaisie.tm_sec = 0;
       	
        date = mktime(&DateEtHeureSaisie);
       	
       	personnePresente=0;
       	
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
		
	//compare si la capacité du resto n'est pas dépasé
    //on recupere la liste de reservation
	reservation* r = this->ListeResa;
    	
    printf("---------------------------------------------------- \n");
		
   	while(  r != NULL)
	{
		//on recupere la date 
		DateEtHeure = *localtime(&r->date);
			
		//on passe le jour, le mois.... dans des chars
		strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
		strftime(jour, 3, "%d", &DateEtHeure);
		strftime(mois, 3, "%m", &DateEtHeure);
		strftime( annee,5, "%Y", &DateEtHeure);
		strftime( heure,3, "%H", &DateEtHeure);
		strftime( minute,3, "%M", &DateEtHeure);
					
			
		//on met les valeurs des chars dans des int 
  		convertir = strtol(jour, NULL, 10);
  		//mais avant on verifie que la valuer ne sort pas de la taille de la variable
  		if (convertir >= INT_MIN && convertir <= INT_MAX)	{
    		jourListe = (int) convertir;
   		}
   			
   			
   		//Idem pour toutes les variables (mois)
  		convertir = strtol(mois, NULL, 10);
  		if (convertir >= INT_MIN && convertir <= INT_MAX)	{
     		moisListe = (int) convertir;
   		}
   			
   		//annee
  		convertir = strtol(annee, NULL, 10);
  		if (convertir >= INT_MIN && convertir <= INT_MAX)	{
     		anneeListe = (int) convertir;
   		}
   			
   		//heure
  		convertir = strtol(heure, NULL, 10);
  		if (convertir >= INT_MIN && convertir <= INT_MAX)	{
     		heureListe = (int) convertir;
   		}
   			
   		//minute
  		convertir = strtol(minute, NULL, 10);
  		if (convertir >= INT_MIN && convertir <= INT_MAX)	{
     		minuteListe = (int) convertir;
   		}
   			
   	
   		if(aaaa==anneeListe && mm==moisListe && jj==jourListe)	{
				
			//si les deux plages horaires se chevauche incrementer nombre de personnes
			if((hh<heureListe && heureListe < hh+2) || (heureListe<hh && hh<heureListe+2)){
				personnePresente=personnePresente+r->nbPersone;
			} 
			else if (hh==heureListe && mm==minuteListe){
				personnePresente=personnePresente+r->nbPersone;
			}
			else if (hh==heureListe && (mm<=minuteListe || mm>=minuteListe)){
				personnePresente=personnePresente+r->nbPersone;
			}				
		}
			
		//printf("Reserv. le : %s, %i/%i/%i %ih %i \n",format,jourListe, moisListe, anneeListe, heureListe, minuteListe);
		r = r->suiv;			
	}
		
		
		
		
	//demande de saisir le nombre de personne
	printf("Entrer le nonbre de personnes : (int)");          
	cin >> nbPersone;
	
		
	//si le nombre de personne presente est plus petit que la capacité du resto
	if(personnePresente+nbPersone <=nbDeCouvertMAX ){
		//demande le nom est enregistre la reservation dans la liste
		printf("a quel nom ?(text)");          
		cin >> nom;
			
		importReservation(date, nbPersone, nom);
		
		printf("Votre reservation est enregistree pour le %i/%i/%i a %ih%i pour %i personnes au nom de %s ",jj,mm,aaaa,hh,min,nbPersone, nom);			
	} 
	else {
		printf("Nous ne pouvons traiter votre demande car la capacite du restaurant est atteinte \n Merci de votre comprehension");
	}
	
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
				    
	     	//tant que la date de la nouvelle reservation est supp a la date de reservation et que on est pas en fin de liste
			while((res->date > r->date) && (r->suiv != NULL)) 	
			{
				r = r->suiv; //passe a la ressuivante
			}
			
			if (res->date >= r->date) //si la date st supp ou égale a la date de la liste.
			{
				
				res->suiv = r->suiv; //met le suivant de r en suivant de res
				res->prec = r; // défini r comme précédent res
				
				if (not(r->suiv == NULL))
				{
					r->suiv->prec = res; //si r n'est pas le dernier de la liste, place res en précedent du suivant de r.
				}
					
				r->suiv = res; //place res apres r.
				
			} 
			else
			{
				
				res->suiv = r; //met r en suivant de res
				res->prec = r->prec; //recup le precedent de r et le pace dans res
				
				if (r->prec == NULL) //si le precedent de r est le début de liste
					this->ListeResa = res; // res deviens le premier de la liste
				else
					r->prec->suiv = res; //sinon res deviens le suivant du précedent de r
					
				r->prec = res; // res deviens le precedent de r
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
		struct tm DateEtHeure;
		if (longeurChaine() > 0)
		{
			
		    reservation* r = this->ListeResa;
	    	reservation* allResa[longeurChaine()];
	    	int cpt = 0;
	    	int numSuprr = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			DateEtHeure = *localtime(&r->date);
			strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
			allResa[cpt] = r;
			cpt++;
			printf("R : %i | le : %s , %i personnes, au nom de : %s \n",cpt ,format,r->nbPersone,r->nom);
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
    
void MesReservation::ajouterCommandes()
	{
		char  format[32];
		struct tm DateEtHeure;
		if (longeurChaine() > 0)
		{
			
		    reservation* r = this->ListeResa;
	    	reservation* allResa[longeurChaine()];
	    	int cpt = 0;
	    	int selecteur = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			DateEtHeure = *localtime(&r->date);
			strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
			allResa[cpt] = r;
			cpt++;
			printf("R : %i | le : %s , %i personnes, au nom de : %s \n",cpt ,format,r->nbPersone,r->nom);
			r = r->suiv;
			}
			
			printf("#################################################### \n");
			
			
			printf("Sélectioner le N° de la reservation (0 pour annuler) :  ");
			cin >> selecteur;
			
			if (selecteur == 0)
			{
				printf("Anulation \n");
				
				return;
			}
			else if (selecteur > cpt)
			{
				printf("pas de reservation a ce numero \n");
				
				return;
			}
			else
			{
				selecteur--;
				
				if (allResa[selecteur]->cmd == NULL)
					{
						allResa[selecteur]->cmd = new MesCommandes();
						allResa[selecteur]->cmd->ajouterPlat(this->menu);
					}
				else
					{
						allResa[selecteur]->cmd->ajouterPlat(this->menu);
					}
				
				
			}
		}
	}
	
	
void MesReservation::listerCommandesAssociees()
	{
		char  format[32];
		struct tm DateEtHeure;
		if (longeurChaine() > 0)
		{
			
		    reservation* r = this->ListeResa;
	    	reservation* allResa[longeurChaine()];
	    	int cpt = 0;
	    	int selecteur = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			DateEtHeure = *localtime(&r->date);
			strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
			allResa[cpt] = r;
			cpt++;
			printf("R : %i | le : %s , %i personnes, au nom de : %s \n",cpt ,format,r->nbPersone,r->nom);
			r = r->suiv;
			}
			
			printf("#################################################### \n");
			
			
			printf("Sélectioner le N° de la reservation (0 pour annuler) :  ");
			cin >> selecteur;
			
			if (selecteur == 0)
			{
				printf("Anulation \n");
				
				return;
			}
			else if (selecteur > cpt)
			{
				printf("Pas de reservation a ce numero \n");
				
				return;
			}
			else
			{
				selecteur--;
				
				if (allResa[selecteur]->cmd == NULL)
					{
							printf("Pas de commandes sur cette reservation \n");
					}
				else
					{
						allResa[selecteur]->cmd->ListerCommandes();
					}
				
				
			}
		}
	}
	
	
void MesReservation::listertouteslesCommandesAssociees()
	{
		char  format[32];
		struct tm DateEtHeure;
		if (longeurChaine() > 0)
		{
			
		    reservation* r = this->ListeResa;
	    	reservation* allResa[longeurChaine()];
	    	int cpt = 0;
	    	int selecteur = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
				
			DateEtHeure = *localtime(&r->date);
			
			strftime(format, 32, "%d/%m/%Y %Hh%M", &DateEtHeure);
			
			allResa[cpt] = r;
			
			printf("R : %i | le : %s , %i personnes, au nom de : %s \n",cpt+1 ,format,r->nbPersone,r->nom);
			
			if (allResa[cpt]->cmd == NULL)
					{
							printf("pas de commandes sur cette reservation \n");
					}
				else
					{
						allResa[cpt]->cmd->ListerCommandes();
					}
			cpt++;
			
			r = r->suiv;
			

			printf("#################################################### \n");

			}
		}
	}	
