#ifndef MENU_INC
#define MENU_INC

typedef struct _plat plat;
typedef plat* ListeMenu;     


struct _plat {
       
       char Nom_Plat[20];
       char Type_Plat[20];
       float Prix;
       char Ingredient[100];
       plat* prec;
       plat* suiv;
       };
       
class Menu
{
private:

ListeMenu ListeMn;
ListeMenu creerListe(void); 
plat* nouveauMenu(void);
void effacer_liste(ListeMenu L);
int longeurChaine();

public:

Menu();
ListeMenu getListeMn();
int getlongeurChaine();
void ajouterMenu();
void ListeMenu();
void importMenu(char* Nom_Plat, char* Type_Plat,float Prix, char* Ingredient);	
void supprimerMn();

};

#endif // RESERVATION_INC
