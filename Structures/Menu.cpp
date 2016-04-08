#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Menu.h"
#include <string>

using namespace std;

ListeMenu Menu::creerListe(void)
	{
		return NULL;
	}
 
plat* Menu::nouveauMenu(void)
	{
		plat* mn = (plat*) malloc(sizeof(plat));
		mn->suiv = NULL;
		mn->prec = NULL;
		return mn;
	}

void Menu::effacer_liste(plat* L)
	{
		while( L != NULL)
		{
			plat* r = L;
			L = L->suiv;
			free(r); 
		}
	}
	

ListeMenu Menu::getListeMn()
{
	return this->ListeMn;
}

Menu::Menu()
	 {
	 	this->ListeMn = creerListe();
	 }
 
void Menu::ajouterMenu(){
	    
	    char Nom_Plat[20];
       	char Type_Plat[20];
      	float Prix;
       	char Ingredient[100];
	      		
	    printf("Entrer le nom du plat : (text))");          
       	cin >> Nom_Plat;
       	
		printf("Entrer le type du plat: (text)");          
       	cin >> Type_Plat;
	    
	    printf("Entrer le prix du plat : (int)");          
       	cin >> Prix;
	    
	    printf("Entrer les ingredients : (text)");          
       	cin >> Ingredient;
	    
	    
	    importMenu(Nom_Plat, Type_Plat, Prix, Ingredient);
 	    


    }
    
    
void Menu::ListeMenu()
    {
    	plat* r = this->ListeMn;
    	
    	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
    	
    	while(  r != NULL)
		{
		printf("%s : %s, %.2f Euros \n",r->Type_Plat,r->Nom_Plat,r->Prix);
		printf("          %s \n",r->Ingredient);
		r = r->suiv;
		}
		
		printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n");
	}
	
void Menu::importMenu(char* Nom_Plat, char* Type_Plat, float Prix, char* Ingredient)
	{
	    
	    plat* mn = nouveauMenu();
	    plat* r = this->ListeMn;
	    
		strcpy(mn->Nom_Plat,Nom_Plat);
		strcpy(mn->Type_Plat,Type_Plat);
	    mn->Prix = Prix;
	    strcpy(mn->Ingredient,Ingredient);
	           	
		mn->suiv = this->ListeMn; //d�fini la liste comme �l�ment suivant de la comande
		this->ListeMn = mn; //insert la nouvelle commande en tete de liste
		
		return;
		
    }
    
int Menu::longeurChaine()
	{
		plat* r = this->ListeMn;
		int cpte = 0;
		
		while(  r != NULL)
		{
		cpte++;
		r = r->suiv;
		}
		
		return cpte;
	}

   
void Menu::supprimerMn()
	{
		if (longeurChaine() > 0)
		{
			
		    plat* r = this->ListeMn;
	    	plat* allMn[longeurChaine()];
	    	int cpt = 0;
	    	int numSuprr = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			allMn[cpt] = r;
			cpt++;
			printf("[%i] : %s - %s, au prix de %.2f \n",cpt,r->Nom_Plat,r->Type_Plat,r->Prix);

			r = r->suiv;
			}
			
			printf("#################################################### \n");
			
			
			printf("S�lectioner le N� de la commande a supprimer (0 pour annuler) :  ");
			cin >> numSuprr;
			
			if (numSuprr == 0)
			{
				printf("Anulation \n");
				
				return;
			}
			else if (numSuprr > cpt)
			{
				printf("pas de commande a ce numero \n");
				
				return;
			}
			else
			{
				numSuprr--;
				
				if (numSuprr == 0)
				{
					this->ListeMn = allMn[numSuprr]->suiv;
					free(allMn[numSuprr]);
					printf("done !");
					return;
				}
				else
				{
					allMn[numSuprr-1]->suiv = allMn[numSuprr]->suiv;
					free(allMn[numSuprr]);
					printf("Supprimer !");		
					return;
				}
	
			}
		}
		else
		{
			printf("rien a afficher");
		}
	}
    
int Menu::getlongeurChaine()
 {
 	return longeurChaine();
 }
