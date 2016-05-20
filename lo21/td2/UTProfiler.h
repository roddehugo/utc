//
//  UTProfiler.h
//  UTProfiler
//
//  Created by Samuel F on 27/03/2014.
//  Copyright (c) 2014 Samuel. All rights reserved.
//


#ifndef UT_PROFILER_h
#define UT_PROFILER_h
#include<string>
#include<iostream>
using namespace std;
class UTProfilerException
{
public:
    UTProfilerException(const string& message):info(message) {}
    string getInfo() const
    {
        return info;
    } private:
    string info;
};
enum Categorie {
    /* Connaissances Scientifiques */ CS, /* Techniques et Méthodes */ TM, /* Technologies et Sciences de l’Homme */ TSH, /* Stage et Projet */ SP
};
enum Note {A,B,C,D,E,F,FX,/*encours*/EC };
enum Saison { Automne, Printemps };
enum Niveau {TC, Branche};
class Semestre
{
    Saison saison;
    unsigned int annee;
public:
    Semestre(Saison s, unsigned int a):saison(s),annee(a)
    {
        if (annee<1972) throw UTProfilerException("annee non valide");
    }
    Saison getSaison() const
    {
        return saison;
    }
    unsigned int getAnnee() const
    {
        return annee;
    }
};
inline ostream& operator<<(ostream& f, const Saison& s)
{
    if (s==Automne) f<<"A";
    else f<<"P";
    return f;
}
inline ostream& operator<<(ostream& f, const Semestre& s)
{
    return f<<s.getSaison()<<s.getAnnee()%100;
}

class UV
{
    string code;
    string titre;
    Categorie categorie;
    unsigned int nbCredits;
public:
    UV(const string& c, const string& t,unsigned int n, Categorie cat):
        code(c),titre(t),nbCredits(n), categorie (cat) {}
    const string& getCode() const
    {
        return code;
    }
    const string& getTitre() const
    {
        return titre;
    }
    Categorie getCategorie() const
    {
        return categorie;
    }
    unsigned int getNbCredits() const
    {
        return nbCredits;
    }
    //pas besoin de destructeur ni de recopie car
    // tableau d'objet impossible sans mettre de valeur par défaut ou sans constructeur n eprenant pas d'arguments
    // tableau pointeur possible
    friend class UVManager; // seul UVManager a le droit de créer des UVS
};
class Inscription
{
    const UV* uv;
    Semestre sem;
    Note resultat;
public:
    Inscription(const UV& uv,Semestre s):uv(&uv),sem(s),resultat(EC) {}
    const UV&  getUV() const
    {
        return *uv;
    }
    Semestre  getSemestre()const
    {
        return sem;
    }
    Note getResultat() const
    {
        return resultat;
    }

};
class Formation
{
    Inscription** insc;
public:

    Inscription** const getInscription() const
    {
        return insc;
    }

};
class UVManager
{
private:
    UV** uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    void addItem(UV* uv);
    UV* trouveUV(const string&c) const ;
public:
    UVManager();
    void ajouterUV(const string& c, const string& t, unsigned int nbc, Categorie cat);
    UV& getUV(const string& code);
    const UV& getUV(const string& code) const;
    ~UVManager();
    UVManager(const UVManager& m);
    UVManager& operator=(const UVManager& m);
};
#endif /* defined(__UTProfiler__UTProfiler__) */
