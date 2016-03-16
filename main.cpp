#include <cstdlib>
#include <iostream>
#include "Structures\Reservation.h"

using namespace std;

int main(int argc, char *argv[])
{
   
   int choix;
   
   struct reservation r1={1,1,2,"nom"};
   
   printf("%1d" ,r1.date);
   
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
          //     exo1();
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

      }      
    }
}
