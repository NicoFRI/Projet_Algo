#ifndef RESERVATION_INC
#define RESERVATION_INC

typedef struct _reservation reservation;
typedef reservation* ListeResevation;     


struct _reservation {
       
       int date;
       int heure;
       int nbPersone;
       char nom[];
       reservation* prec;
       reservation* suiv;

       };
       
class MesReservation 
{
private:

ListeResevation ListeResa;
ListeResevation creerListe(void); 
reservation* nouvelleResa(void);
void effacer_liste(ListeResevation L);
int longeurChaine();

public:

MesReservation();
ListeResevation getListeResa();
void ajouterReservation();
void ListeReservation();
void importReservation(int date, int heure, int nbpers, char* nom);	
void supprimerResa();

};

#endif // RESERVATION_INC
