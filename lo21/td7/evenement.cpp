#include "evenement.h"

std::ostream& operator<<(std::ostream& f, const TIME::Evt& e){
    e.afficher();
    return f;
}

TIME::Agenda::Agenda(){}
void TIME::Agenda::agrandir(){
    Evt** newevts = new Evt*[nbEvtsMax+10];
    memcpy(newevts, evts, sizeof(Evt*)*nbEvts);
    Evt** old=evts;
    nbEvtsMax+=10;
    evts=newevts;
    delete[] old;


}

TIME::Agenda& TIME::Agenda::operator<<(Evt& e){
    if(nbEvts==nbEvtsMax){
        agrandir();
    }
    evts[nbEvts++]=e.clone();/*dupliquer l'objet pointé par e et stocker l'adresse de cette duplication Agend sera responsable de cet objet*/
    //&e;
    return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const {
    for(unsigned int i=0; i<nbEvts; i++) { f<<*evts[i]; }
}

TIME::Agenda::~Agenda(){
    for (unsigned int i=0; i<nbEvts; i++) delete evts[i];
            delete[] evts; }
