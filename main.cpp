#include <iostream>
#include "Structures\Reservation.h"
#include "LireEcrireReservation.h"
#include <unistd.h>
#include <cstdlib>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int choix;
	MesReservation* Res = new MesReservation;
	Res->importReservation(10,1,15,"dsgsdfgdfg");
	Res->importReservation(11,2,15,"dsgsdfgdfg");
	Res->importReservation(12,3,15,"dsgsdfgdfg");
	Res->importReservation(13,4,15,"dsgsdfgdfg");
	Res->importReservation(14,5,15,"dsgsdfgdfg");
	Res->importReservation(15,6,15,"dsgsdfgdfg");
	Res->importReservation(9,7,15,"dsgsdfgdfg");
	Res->importReservation(17,8,15,"dsgsdfgdfg");
	Res->importReservation(2,9,15,"dsgsdfgdfg");
	Res->importReservation(10,10,15,"dsgsdfgdfg");
	Res->importReservation(11,11,15,"dsgsdfgdfg");
	Res->importReservation(12,12,15,"dsgsdfgdfg");
	Res->importReservation(13,13,15,"dsgsdfgdfg");
	Res->importReservation(14,14,15,"dsgsdfgdfg");
	Res->importReservation(15,15,15,"dsgsdfgdfg");
	Res->importReservation(9,16,15,"dsgsdfgdfg");
	Res->importReservation(17,17,15,"dsgsdfgdfg");
	Res->importReservation(2,18,15,"dsgsdfgdfg");
	
	
	lireReservation(Res);

  	
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
             	ecrireReservation(Res->getListeResa());
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
    
    return 0;
}
