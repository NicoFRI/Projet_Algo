#ifndef MENU_INC
#define MENU_INC

typedef struct _menu menu;
typedef menu* ListeMenu;     


struct _menu {
       
       char Nom_Plat[20];
       char Type_Plat[20];
       float Prix;
       char Ingredient[100];
       menu* prec;
       menu* suiv;
       };
       
class MesMenu
{
private:

ListeMenu ListeMn;
ListeMenu creerListe(void); 
menu* nouveauMenu(void);
void effacer_liste(ListeMenu L);
int longeurChaine();

public:

MesMenu();
ListeMenu getListeMn();
void ajouterMenu();
void ListeMenu();
void importMenu(char* Nom_Plat, char* Type_Plat,float Prix, char* Ingredient);	
void supprimerMn();

};

#endif // RESERVATION_INC
