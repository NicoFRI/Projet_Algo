#ifndef RESERVATION_INC
#define RESERVATION_INC

typedef struct _reservation reservation;
typedef reservation* ListeResevation;     


struct _reservation {
       
       int date;
       int heurre;
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

public:

MesReservation();
void ajouterReservation();
void ListeReservation();
	
};

#endif // RESERVATION_INC
