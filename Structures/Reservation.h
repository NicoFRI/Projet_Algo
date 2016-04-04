#ifndef RESERVATION_INC
#define RESERVATION_INC

typedef struct _reservation reservation;
typedef reservation* ListeReservation;     


struct _reservation {
       
       time_t date;
       int nbPersone;
       char nom[20];
       reservation* prec;
       reservation* suiv;

       };
       
class MesReservation 
{
private:

ListeReservation ListeResa;
ListeReservation creerListe(void); 
reservation* nouvelleResa(void);
void effacer_liste(ListeReservation L);
int longeurChaine();

public:

MesReservation();
ListeReservation getListeResa();
void ajouterReservation();
void ListeReservation();
void importReservation(time_t date, int nbpers, char* nom);	
void supprimerResa();

};

#endif // RESERVATION_INC
