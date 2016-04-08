#include <iostream>
#include <fstream>
#include "structures/Reservation.h"
#include "LireEcrireReservation.h"
using namespace std;

 void lireReservation(MesReservation* R) {	
 
	 ifstream fichier("data/reservations.txt", ios::in);
	 
	    if(fichier)
	    {		time_t date =0;
	      		int nbpers;
	      		char nom[20];
	        
			string ligne;	
	        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
	      	{
	      	 
	      		
				  
	      		fichier >> date >> nbpers >> nom ;
	      	 if(date!=0)  R->importReservation(date, nbpers, nom); 
	      	}
	               
	        fichier.close();
	  	}
	    else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	 
	      
	    /*return 0;*/
  }



void ecrireReservation(reservation*L)
{
	
	ofstream fichier("data/reservations.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
	        
	        if(fichier)  // si l'ouverture a réussi
	        {
	        	fichier<<"date"<<" "<<"nb"<<" "<<"nom";
	        
	        	ListeReservation LR=L;	        	
				
		  	
		    	while(  LR != NULL)
				{
					fichier<< "\n"<< LR->date << " " << LR->nbPersone << " " << LR->nom ;	
					LR = LR->suiv;
				}
	                	          
	        } 
			else  // sinon
	        {
				cerr << "Erreur à l'ouverture !" << endl;
			}
			
}
	



