#include <iostream>
#include "Structures\Reservation.h"
#include "LireEcrireReservation.h"
#include "Structures\Menu.h"
#include "LireEcrireMenu.h"
#include "Structures\commandes.h"
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
 
 cout<< "Bienvenue chez Teauteau"<< endl;
  	cout << format << endl;
	
	int choix;
	
	Menu* Mn = new Menu;
	MesReservation* Res = new MesReservation(Mn);
	
	lireReservation(Res);
	lireMenu(Mn);	
 	
   while (1==1)
   {
   	
       printf("\n ********************************************************** \n");
       printf("0....Quitter \n1....Reserver \n2....Voir la liste des reservations \n3....supprimer une reservation \n4....ajouter un plat \n5....voir la liste des plats \n6....Ajouter une commande \n7....Voir les commandes associees a une reservation \n8....Lister toutes les commandes");
       printf("\n ********************************************************** \n");
       printf("Entrer le numero correspondant a ce que vous souhaitiez faire :");
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
         		Res->ajouterCommandes();
         		
               break;    
           case 7:
               Res->listerCommandesAssociees();
               break; 
            case 8:
               Res->listertouteslesCommandesAssociees();
               break;  
               case 9:
               Mn->supprimerMn();
               break;  
			     
		sleep(100);
      }      
    }
    
    return 0;
}
