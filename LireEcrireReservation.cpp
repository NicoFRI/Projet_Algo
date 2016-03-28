#include <iostream>
#include <fstream>
#include "structures/Reservation.h"
#include "LireEcrireReservation.h"
using namespace std;

 void lireReservation(MesReservation* R) {	
 
	 ifstream fichier("test.txt", ios::in);
	 
	    if(fichier)
	    {
	        
			string ligne;	
	        while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
	      	{
	      		int date;
	      		int heure;
	      		int nbpers;
	      		char* nom;
	      		
	      		fichier >> date >>heure >>nbpers >> nom ;
	      		R->importReservation(date, heure, nbpers, nom);
	    
	      	}
	               
	        fichier.close();
	  	}
	    else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	 
	      
	    /*return 0;*/
  }



void ecireReservation(reservation*L)
{
	
	ofstream fichier("test.txt", ios::out | ios::app);  //déclaration du flux et ouverture du fichier
	        
	        if(fichier)  // si l'ouverture a réussi
	        {
	        	
	        
	        	ListeResevation LR=L;	        	
				
		  	
		    	while(  LR != NULL)
				{
					fichier << LR->date <<LR->heure << LR->nbPersone <<LR->nom;	
					LR = LR->suiv;
				}
	                	          
	        } 
			else  // sinon
	        {
				cerr << "Erreur à l'ouverture !" << endl;
			}
			
}
	



