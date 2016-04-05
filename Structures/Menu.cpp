#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "Menu.h"
#include <string>

using namespace std;

ListeMenu MesMenu::creerListe(void)
	{
		return NULL;
	}
 
menu* MesMenu::nouveauMenu(void)
	{
		menu* mn = (menu*) malloc(sizeof(menu));
		mn->suiv = NULL;
		mn->prec = NULL;
		return mn;
	}

void MesMenu::effacer_liste(menu* L)
	{
		while( L != NULL)
		{
			menu* r = L;
			L = L->suiv;
			free(r); 
		}
	}
	

ListeMenu MesMenu::getListeMn()
{
	return this->ListeMn;
}

MesMenu::MesMenu()
	 {
	 	this->ListeMn = creerListe();
	 }
 
void MesMenu::ajouterMenu(){
	    
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
    
    
void MesMenu::ListeMenu()
    {
    	menu* r = this->ListeMn;
    	
    	printf("#################################################### \n");
    	
    	while(  r != NULL)
		{
		printf("Menu : %s - %s,composé de %s, au prix de %2f \n",r->Nom_Plat,r->Type_Plat,r->Ingredient,r->Prix);
		r = r->suiv;
		}
		
		printf("#################################################### \n");
	}
	
void MesMenu::importMenu(char* Nom_Plat, char* Type_Plat, float Prix, char* Ingredient)
	{
	    
	    menu* mn = nouveauMenu();
	    menu* r = this->ListeMn;
	    
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
    
int MesMenu::longeurChaine()
	{
		menu* r = this->ListeMn;
		int cpte = 0;
		
		while(  r != NULL)
		{
		cpte++;
		r = r->suiv;
		}
		
		return cpte;
	}

   
void MesMenu::supprimerMn()
	{
		if (longeurChaine() > 0)
		{
			
		    menu* r = this->ListeMn;
	    	menu* allMn[longeurChaine()];
	    	int cpt = 0;
	    	int numSuprr = 0;
	   	
	   	
	    	printf("#################################################### \n");
	    	
	    	while(  r != NULL)
			{
			allMn[cpt] = r;
			cpt++;
			printf("C: %i : Menu : %s - %s,composé de %s, au prix de %2f \n",cpt,r->Nom_Plat,r->Type_Plat,r->Ingredient,r->Prix);

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
    
