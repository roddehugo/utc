#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <iostream>
#include <string>
#include <cstring>
#include "timing.h"

using namespace std;

namespace TIME
{

class Evt1j
{
private:
    Date date;
    std::string sujet;
public:
    Evt1j(const Date& d, const std::string& s):date(d),sujet(s)
    {
        std::cout<<"constructeur Evt1j\n";
    }
    const std::string& getDescription() const
    {
        return sujet;
    }
    const Date& getDate() const
    {
        return date;
    }
    virtual void afficher(std::ostream& f= std::cout) const
    {
        f<<"***** Evt ********"<<"\n"<<"Date="<<date<<" sujet="<<sujet<<"\n";
    }
    virtual ~Evt1j()
    {
        std::cout<<"destructeur Evt1j\n";
    }
};


class Evt1jDur : public Evt1j
{
    Horaire debut;
    Duree duree;
public:
    Evt1jDur(const Date& d, const string& s, const Horaire& h, const Duree& dur): Evt1j(d,s),debut(h),duree(dur)
    {
        std::cout<<"constructeur Evt1jDur\n";
    }
    const Horaire& getDebut() const
    {
        return debut;
    }
    const Duree& getDuree() const
    {
        return duree;
    }
    void afficher(std::ostream& f= std::cout) const
    {
        Evt1j::afficher(f);
        f<<"debut : "<<debut<<" duree :"<<duree<<"\n";
    }
    virtual ~Evt1jDur()
    {
        std::cout<<"destructeur Evt1jDur\n";
    }
};

class Rdv : public Evt1jDur
{
    string lieu;
    string personne;
public:
    Rdv(const Date& d, const string& s, const Horaire& h, const Duree& dur, const string& l, const string& p): Evt1jDur(d,s,h,dur),lieu(l),personne(p)
    {
        std::cout<<"constructeur Rdv\n";
    }
    const string& getLieu() const
    {
        return lieu;
    }
    const string& getPersonne() const
    {
        return personne;
    }
    void afficher(std::ostream& f= std::cout) const
    {
        Evt1jDur::afficher(f);
        f<<"lieu :"<<lieu<<" personne :"<<personne<<"\n";
    }
    ~Rdv()
    {
        std::cout<<"destructeur Rdv\n";
    }
};

class Agenda
{
    Evt1j** evts;
    unsigned int nbEvts;
    unsigned int nbEvtsMax;

    //Interdire la recopie
    Agenda(const Agenda& a);
    Agenda& operator=(Agenda a);
public:
    Agenda();
    Agenda& operator<<(Evt1j& e);
    void afficher (std::ostream& f= std::cout) const;
    ~Agenda();
};
}

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e);

#endif // EVENEMENT_H
