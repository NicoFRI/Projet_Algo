#include <iostream>
#include <fstream>
#include "structures/Reservation.h"
#include "LireEcrireReservation.h"
using namespace std;

 void lireReservation(MesReservation* R) {	
 
	 ifstream fichier("data/reservations.txt", ios::in);
	 
	    if(fichier)
	    {
	        
			string ligne;	
	        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
	      	{
	      		time_t date;
	      		int nbpers;
	      		char nom[20];
	      		
	      		fichier >> date >> nbpers >> nom ;
	      		R->importReservation(date, nbpers, nom);
	    
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
	        	
	        
	        	ListeReservation LR=L;	        	
				
		  	
		    	while(  LR != NULL)
				{
					fichier << LR->date << " " << LR->nbPersone << " " << LR->nom << "\n";	
					LR = LR->suiv;
				}
	                	          
	        } 
			else  // sinon
	        {
				cerr << "Erreur à l'ouverture !" << endl;
			}
			
}
	



