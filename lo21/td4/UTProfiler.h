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
    }
private:
    string info;
};

enum Categorie {
    /* Connaissances Scientifiques */ CS,  /* Techniques et Méthodes */ TM,
    /* Technologies et Sciences de l'Homme */ TSH, /* Stage et Projet */ SP
};
ostream& operator<<(ostream& f, const Categorie& s);
istream& operator>>(istream& f, Categorie& cat);

enum Note { A, B, C, D, E, F, FX, RES, ABS, /* en cours */ EC  };

enum Saison { Automne, Printemps };
inline ostream& operator<<(ostream& f, const Saison& s)
{
    if (s==Automne) f<<"A";
    else f<<"P";
    return f;
}

class Semestre
{
    Saison saison;
    unsigned int annee;
public:
    Semestre(Saison s, unsigned int a):saison(s),annee(a)
    {
        if (annee<1972||annee>2099) throw UTProfilerException("annee non valide");
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

inline ostream& operator<<(ostream& f, const Semestre& s)
{
    return f<<s.getSaison()<<s.getAnnee()%100;
}

class UV
{
    string code;
    string titre;
    unsigned int nbCredits;
    Categorie categorie;
    UV(const string& c, const string& t, unsigned int nbc, Categorie cat):
        code(c),titre(t),nbCredits(nbc),categorie(cat) {}
    friend class UVManager;
public:
    string getCode() const
    {
        return code;
    }
    string getTitre() const
    {
        return titre;
    }
    unsigned int getNbCredits() const
    {
        return nbCredits;
    }
    Categorie getCategorie() const
    {
        return categorie;
    }
};

ostream& operator<<(ostream& f, const UV& uv);

class UVManager
{
private:
    UV** uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    void addItem(UV* uv);
    string file;
    bool modification;
    UV* trouverUV(const string& c) const;

    UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);

    struct Handler {
        UVManager* instanceUnique;
        Handler():instanceUnique(0) {};
        ~Handler()
        {
            delete instanceUnique;
        }
    };

    static Handler handler;
    //static UVManager* instanceUnique; //dŽclaration
public:
    class Iterator
    {
        UV** uvs; //adresse du premier ŽlŽment du tableau
        unsigned int nbUV;
        unsigned int courant;
        friend class UVManager;

    private:
        Iterator(UV** u, int n):nbUV(n), uvs(u), courant(0) {}

    public:
        void next()
        {
            if(isDone()) throw UTProfilerException("erreur iterator");
            courant ++;
        }
        UV& current() const   //on met const car on ne modifie pas les attributs
        {
            if(isDone()) throw UTProfilerException("erreur iterator");
            return *uvs[courant];
        }
        bool isDone() const
        {
            return courant==nbUV;
        }
        Iterator():nbUV(0), uvs(0), courant(0) {}
    };
    Iterator getIterator()
    {
        return Iterator(uvs, nbUV);    // method de la classe UVManager
    }

    UVManager(const string& f="");
    void ajouterUV(const string& c, const string& t, unsigned int nbc, Categorie cat);
    const UV& getUV(const string& code) const;
    UV& getUV(const string& code);
    ~UVManager();
    static UVManager& getInstance()
    {
        //if(instanceUnique==0) instanceUnique = new UVManager;
        //return *instanceUnique;
        //static UVManager m; // une seule installe dŽfinie localement, dont la durŽe de vie est celle du prorgramme
        //return m;
        if(handler.instanceUnique==0) handler.instanceUnique = new UVManager;
        return *handler.instanceUnique;
    };
    /*static void libererManager(){
        delete instanceUnique;
        instanceUnique=0;
    }*/
    void save(const string& f);
    void load(const string& f);
};


class Inscription
{
    const UV* uv;
    Semestre semestre;
    Note resultat;
public:
    Inscription(const UV& u, const Semestre& s, Note res=EC):uv(&u),semestre(s),resultat(res) {}
    const UV& getUV() const
    {
        return *uv;
    }
    Semestre getSemestre() const
    {
        return semestre;
    }
    Note getResultat() const
    {
        return resultat;
    }
    void setResultat(Note newres)
    {
        resultat=newres;
    }
};

class Dossier
{
};

class Formation
{
};

#endif

#include "UTProfiler.h"
#include <fstream>
#include <sstream>

//UVManager* UVManager::instanceUnique = 0; //

UVManager::Handler UVManager::handler=Handler();

ostream& operator<<(ostream& f, const UV& uv)
{
    return f<<uv.getCode()<<", "<<uv.getCategorie()<<", "<<uv.getNbCredits()<<" credits, "<<uv.getTitre();
}

istream& operator>>(istream& f, Categorie& cat)
{
    string str;
    f>>str;
    if (str=="CS") cat=CS;
    else if (str=="TM") cat=TM;
    else if (str=="SP") cat=SP;
    else if (str=="TSH") cat=TSH;
    else {
        ostringstream e;
        e<<"erreur, lecture categorie : "<<str<<" n'est pas une categorie traitee";
        throw UTProfilerException(e.str());
    }
    return f;
}

ostream& operator<<(ostream& f, const Categorie& cat)
{
    switch(cat) {
    case CS:
        f<<"CS";
        break;
    case TM:
        f<<"TM";
        break;
    case SP:
        f<<"SP";
        break;
    case TSH:
        f<<"TSH";
        break;
    default:
        throw UTProfilerException("erreur, categorie non traitee");
    }
    return f;
}

UVManager::UVManager(const string& f):uvs(0),nbUV(0),nbMaxUV(0),file(f),modification(false)
{
}

void UVManager::load(const string& f)
{
    if (f!="") this->~UVManager();
    file=f;
    ifstream fin(file.c_str()); // open file
    if (!fin) throw UTProfilerException("erreur, lors de l'ouverture du fichier d'UV");
    char tmp[256];
    while (!fin.eof()&&fin.good()) {
        fin.getline(tmp,256); // get code
        if (fin.bad()) throw UTProfilerException("erreur, fichier d'UV, lecture code UV");
        string code=tmp;
        fin.getline(tmp,256); // get titre
        string titre=tmp;
        if (fin.bad()) throw UTProfilerException("erreur, fichier d'UV, lecture titre UV");
        fin.getline(tmp,256); // get nbCredits
        if (fin.bad()) throw UTProfilerException("erreur, fichier d'UV, lecture nb credits UV");
        unsigned int nbCredits;
        istringstream isn(tmp);
        isn>>nbCredits;
        if (isn.bad()) throw UTProfilerException("erreur, fichier d'UV, lecture nb credits UV");
        fin.getline(tmp,256); // get categorie
        istringstream is(tmp);
        Categorie cat;
        is>>cat;
        if (is.bad()) throw UTProfilerException("erreur, fichier d'UV, lecture categorie UV");
        ajouterUV(code,titre,nbCredits,cat);
        if (fin.peek()=='\r') fin.ignore();
        if (fin.peek()=='\n') fin.ignore();
    }
    fin.close(); // close file
    modification=false;
}

void UVManager::addItem(UV* uv)
{
    if (nbUV==nbMaxUV) {
        UV** newtab=new UV*[nbMaxUV+10];
        for(unsigned int i=0; i<nbUV; i++) newtab[i]=uvs[i];
        nbMaxUV+=10;
        UV** old=uvs;
        uvs=newtab;
        delete[] old;
    }
    uvs[nbUV++]=uv;
}

void UVManager::ajouterUV(const string& c, const string& t, unsigned int nbc, Categorie cat)
{
    if (trouverUV(c)) {
        ostringstream str;
        str<<"erreur, UVManager, UV "<<c<<" deja existante";
        throw UTProfilerException(str.str());
    } else {
        UV* newuv=new UV(c,t,nbc,cat);
        addItem(newuv);
        modification=true;
    }
}


UV* UVManager::trouverUV(const string& c)const
{
    for(unsigned int i=0; i<nbUV; i++)
        if (c==uvs[i]->getCode()) return uvs[i];
    return 0;
}

UV& UVManager::getUV(const string& code)
{
    UV* uv=trouverUV(code);
    if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante");
    return *uv;
}

const UV& UVManager::getUV(const string& code)const
{
    return const_cast<UVManager*>(this)->getUV(code);
    // on peut aussi dupliquer le code de la méthode non-const
}

void UVManager::save(const string& f)
{
    file=f;
    // maj du fichier d'UV
    ofstream fout(file.c_str(),ofstream::trunc); // toutes les UVs existantes sont écrasées
    for(unsigned int i=0; i<nbUV; i++) {
        fout<<uvs[i]->getCode()<<"\n";
        fout<<uvs[i]->getTitre()<<"\n";
        fout<<uvs[i]->getNbCredits()<<"\n";
        fout<<uvs[i]->getCategorie()<<"\n";
        cout<<*uvs[i]<<"\n";
    }
    fout.close();
}

UVManager::~UVManager()
{
    if(file!="") save(file);
    for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
    delete [] uvs;
    file="";
}
/*
 UVManager::UVManager(const UVManager& um):nbUV(um.nbUV),nbMaxUV(um.nbMaxUV), uvs(new UV*[um.nbUV]){
 for(unsigned int i=0; i<nbUV; i++) uvs[i]=new UV(*um.uvs[i]);
 }

 UVManager& UVManager::operator=(const UVManager& um){
 if (this==&um) return *this;
 this->~UVManager();
 for(unsigned int i=0; i<um.nbUV; i++) addItem(new UV(*um.uvs[i]));
 return *this;
 }*/
