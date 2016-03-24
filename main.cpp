#include <cstdlib>
#include <iostream>
#include <unistd.h>
//#include "Structures\Reservation.h"

using namespace std;
typedef struct _reservation reservation;
typedef reservation* ListeResevation;

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

ListeResevation ListeResa;

ListeResevation creerListe(void)
{
	return NULL;
}
 
reservation* nouvelleResa(void)
{
	reservation* res = (reservation*) malloc(sizeof(reservation));
	res->suiv = NULL;
	return res;
}

void effacer_liste(ListeResevation L)
{
	while( L != NULL)
	{
		reservation* r = L;
		L = L->suiv;
		free(r); 
	}
}

public:

MesReservation()
 {
 	this->ListeResa = creerListe();
 }
 
void ajouterReservation(){
	    
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
    
    
void ListeReservation()
    {
    	reservation* r = this->ListeResa;
    	
    	while(  r != NULL)
		{
		printf("%i %i %i %s",r->date,r->heurre,r->nbPersone,r->nom);
		r = r->suiv;
		}

	}
	
};       
       
       


int main(int argc, char *argv[])
{
	int choix;
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
             	
          		Res->ajouterReservation();
               	break;
               
             case 2:
           		Res->ListeReservation();
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
