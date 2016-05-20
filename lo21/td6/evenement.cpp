#include "evenement.h"

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e){
    e.afficher();
    return f;
}

TIME::Agenda::Agenda(){}

TIME::Agenda& TIME::Agenda::operator<<(Evt1j& e){
    if(nbEvts==nbEvtsMax){
        Evt1j** newevts = new Evt1j*[nbEvtsMax+10];
        memcpy(newevts, evts, sizeof(Evt1j*)*nbEvts);
        Evt1j** old=evts;
        nbEvtsMax+=10;
        evts=newevts;
        delete[] old;
    }
    evts[nbEvts++]=&e;
    return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const {
    for(unsigned int i=0; i<nbEvts; i++) { f<<*evts[i]; }
}

TIME::Agenda::~Agenda(){ delete[] evts; }
