#include <iostream>
#include "Structures\Reservation.h"
#include "LireEcrireReservation.h"
#include "Structures\Menu.h"
#include "LireEcrireMenu.h"
#include <unistd.h>
#include <cstdlib>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int nbDeCouvertMAX = 26;
	
	time_t temps;
  	struct tm datetime;
  	char  format[32];
 
  	time(&temps);
  	datetime = *localtime(&temps);
 
  	strftime(format, 32, "%Y/%m/%d %H:%M", &datetime);
 
	cout << temps << endl;
  	cout << format << endl;
	
	int choix;
	MesReservation* Res = new MesReservation;
		MesMenu*Mn = new MesMenu;
		
		
		/*Mn->importMenu("pizza","plat",9.1,"dsgsdfgdfg");
	
	/*Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");
	Res->importReservation(1459800023,15,"dsgsdfgdfg");*/
	
	
	lireReservation(Res);
	lireMenu(Mn);	
 	
   while (1==1)
   {
   	
       printf("\n ********************************************************** \n");
       printf("0....Quitter \n1....Reserver \n2....Voir la liste des reservations \n3....supprimer une reservation \n4....ajouter un plat \n5....voir la liste des plats \n6....mais \n7....vous etes encore là?");
       printf("\n ********************************************************** \n");
       printf("Aller a l'exo Numero :");
    
       
       cin >> choix;
       
       
       switch (choix)
       {
             case 0:
             	ecrireMenu(Mn->getListeMn());
             	ecrireReservation(Res->getListeResa());
               return 0;
               
             case 1:
          			Res->ajouterReservation();
               	break;
               
             case 2:
           		Res->ListeReservation();
               	break;
               	
            case 3:
           		Res->supprimerResa();
               break;
               
            case 4:
         		Mn->ajouterMenu();   
               break;
               
           case 5:
          		Mn->ListeMenu();
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
