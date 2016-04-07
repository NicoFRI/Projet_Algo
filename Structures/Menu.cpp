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
	      		
	    printf("Nom : (text))");          
       	cin >> Nom_Plat;
       	
		printf("Type : (text)");          
       	cin >> Type_Plat;
	    
	    printf("Prix : (int)");          
       	cin >> Prix;
	    
	    printf("Ingredient (text)");          
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
	           	
	    if (r == NULL)
       	{
			mn->suiv = r;
		    this->ListeMn = mn;
		    return;
	    }
	    else
	    {
				    
	     	while((mn->Prix > r->Prix) && (r->suiv != NULL))
			{
				r = r->suiv;
			}
			
			if (mn->Prix >= r->Prix)
			{
				
				mn->suiv = r->suiv;
				mn->prec = r;
				
				if (not(r->suiv == NULL))
				{
					r->suiv->prec = mn;
				}
					
				r->suiv = mn;
				
			} 
			else
			{
				
				mn->suiv = r;
				mn->prec = r->prec;
				
				if (r->prec == NULL)
					this->ListeMn = mn;
				else
					r->prec->suiv == mn;
					
				r->prec = mn;
			}
		

			
			return;
		}

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
			
			
			printf("Sélectioner le N° de la commande a supprimer (0 pour annuler) :  ");
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
