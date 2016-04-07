#include <iostream>
#include <fstream>
#include "structures/Menu.h"
#include "LireEcrireMenu.h"
using namespace std;

 void lireMenu(Menu* M) {	
 
	 ifstream fichierMenu("data/Menu.txt", ios::in);
	 
	    if(fichierMenu)
	    {
	        
			string ligne;	
	        while(getline(fichierMenu, ligne)) //Tant qu'on n'est pas à la fin, on lit
	      	{
	      		char Nom_Plat[20];
       			char Type_Plat[20];
       			float Prix;
       			char Ingredient[100];
	      		
	      		fichierMenu >> Nom_Plat >>Type_Plat >> Prix >> Ingredient;
	      		//printf("Menu : %s - %s,composé de %s, au prix de %2f \n",Nom_Plat,Type_Plat,Ingredient,Prix);
			  
			  	M->importMenu(Nom_Plat, Type_Plat, Prix, Ingredient);
	    
	      	}
	               
	        fichierMenu.close();
	  	}
	    else
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	 
	      
	    /*return 0;*/
  }



void ecrireMenu(plat*L)
{
	
	ofstream fichierMenu("data/Menu.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
	        
	        if(fichierMenu)  // si l'ouverture a réussi
	        {
	               
	        	ListeMenu LR=L;	        	
				
		  	
		    	while(  LR != NULL)
				{
					fichierMenu << LR->Nom_Plat<< " " <<LR->Type_Plat<< " " << LR->Prix<< " " << LR->Ingredient <<" \n";	
					LR = LR->suiv;
				}
	                	          
	        } 
			else  // sinon
	        {
				cerr << "Erreur à l'ouverture !" << endl;
			}
			
}
	



