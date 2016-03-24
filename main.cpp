#include <cstdlib>
#include <iostream>
#include <unistd.h>
//#include "Structures\Reservation.h"

using namespace std;
typedef struct _reservation reservation;


struct _reservation {
       
       int date;
       int heurre;
       int nbPersone;
       char nom[];
       reservation* prec;
       reservation* suiv;

       };
       
class MesReservation 
{
private:

reservation* resaUne;
reservation* lastResa;
reservation* printresa;

 

public:

MesReservation()
 {
 	this->resaUne = (reservation*) malloc(sizeof(reservation));
 	this->lastResa = (reservation*) malloc(sizeof(reservation));
 	this->printresa = (reservation*) malloc(sizeof(reservation));
 	this->resaUne->date = NULL;
 }
 
int ajouterReservation(int date,int heurre,int nbPersone,const char* nom){
	    
	    reservation* res = (reservation*) malloc(sizeof(reservation));
	    res->date = date;
	    res->heurre = heurre;
	    res->nbPersone =nbPersone;
	    res->nom;
			
		if (this->resaUne->date == NULL)
	    {
	    	*this->resaUne = *res;
	    	this->resaUne->prec = this->resaUne;
			this->resaUne->suiv = this->lastResa;	
	    	this->lastResa->prec = this->resaUne;
			this->lastResa->suiv = this->resaUne;
	    	
		}
		else
		{
			*this->lastResa->prec->suiv = *res;
			
			res->prec = this->lastResa->prec;
			res->suiv = this->resaUne;
			
			*this->lastResa = *res;
	
		}
	
		
		return 0;
    }
    
    
int ListeReservation()
    {
    	this->printresa = this->resaUne;
    	printf("%i %i %i %c",this->printresa->date,this->printresa->heurre,this->printresa->nbPersone,this->printresa->nom);
    	
		while (this->printresa->suiv != this->resaUne)
    	{
    		this->printresa = this->printresa->suiv;
			printf("%i %i %i %c",this->printresa->date,this->printresa->heurre,this->printresa->nbPersone,this->printresa->nom);
		}
    	return 0;
	}
};       
       
       


int main(int argc, char *argv[])
{
	int choix;
	int a;
	MesReservation* Res = new MesReservation;
  	
   while (1==1)
   {
   	
       printf("\n ********************************************************** \n");
       printf("0....Quitter \n1....Reserver \n2....Voir la liste des reservations \n3....merci \n4....merci bcp \n5....au revoir \n6....mais \n7....vous etes encore là?");
       printf("\n ********************************************************** \n");
       printf("Aller a l'exo Numero :");
    
       
       cin >> choix;
       
       
       switch (choix)
       {
             case 0:
               return 0;
               
             case 1:
             	
          		a = Res->ajouterReservation(1,1,5,"Blabla");
          		a = Res->ListeReservation();
          		
               break;
               
             case 2:
           //    exo2();
               break;
            case 3:
           //    exo3();
               break;
            case 4:
          //     exo4();
               break;
           case 5:
          //     exo5();
               break;
           case 6:
         //      exo6();
               break;    
           case 7:
         //      exo7();
               break;  
			     
		sleep(100);
      }      
    }
}
