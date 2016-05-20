#ifndef UT_PROFILER_h
#define UT_PROFILER_h

#include <QString>
#include <QTextStream>

using namespace std;

class UTProfilerException
{
public:
    UTProfilerException(const QString& message, const QString &f="na", unsigned int l=0):
        info(message),file(f),line(l) {}
    QString getInfo() const
    {
        return info;
    }
#ifndef NDEBUG
    // retourne le fichier dans lequel cettte exception a été levée.
    QString getFile() const
    {
        return file;
    }
    // retourne la ligne du fichier à laquelle cette exception a été levée.
    unsigned int getLine() const
    {
        return line;
    }
#endif
private:
    QString info;
    QString file;
    unsigned int line;

};

enum Categorie {
    /* Connaissances Scientifiques */ CS,  /* Techniques et Méthodes */ TM,
    /* Technologies et Sciences de l'Homme */ TSH, /* Stage et Projet */ SP
};

QTextStream& operator<<(QTextStream& f, const Categorie& s);
Categorie StringToCategorie(const QString& s);
QString CategorieToString(Categorie c);
QTextStream& operator>>(QTextStream& f, Categorie& cat);

enum Note { A, B, C, D, E, F, FX, RES, ABS, /* en cours */ EC  };
enum Saison { Automne, Printemps };
inline QTextStream& operator<<(QTextStream& f, const Saison& s)
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

inline QTextStream& operator<<(QTextStream& f, const Semestre& s)
{
    return f<<s.getSaison()<<s.getAnnee()%100;
}

class UV
{
    QString code;
    QString titre;
    unsigned int nbCredits;
    Categorie categorie;
    bool automne;
    bool printemps;
    UV(const UV& u);
    UV& operator=(const UV& u);
    UV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p):
        code(c),titre(t),nbCredits(nbc),categorie(cat),automne(a),printemps(p) {}
    friend class UVManager;
public:
    QString getCode() const
    {
        return code;
    }
    QString getTitre() const
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
    bool ouvertureAutomne() const
    {
        return automne;
    }
    bool ouverturePrintemps() const
    {
        return printemps;
    }
    void setCode(const QString& c)
    {
        code=c;
    }
    void setTitre(const QString& t)
    {
        titre=t;
    }
    void setNbCredits(unsigned int n)
    {
        nbCredits=n;
    }
    void setCategorie(Categorie c)
    {
        categorie=c;
    }
    void setOuvertureAutomne(bool b)
    {
        automne=b;
    }
    void setOuverturePrintemps(bool b)
    {
        printemps=b;
    }
};

QTextStream& operator<<(QTextStream& f, const UV& uv);


class UVManager
{
private:
    UV** uvs;
    unsigned int nbUV;
    unsigned int nbMaxUV;
    void addItem(UV* uv);
    bool modification;
    UV* trouverUV(const QString& c) const;
    UVManager(const UVManager& um);
    UVManager& operator=(const UVManager& um);
    UVManager();
    ~UVManager();
    QString file;
    friend struct Handler;
    struct Handler {
        UVManager* instance;
        Handler():instance(0) {}
        ~Handler()
        {
            if (instance) delete instance;
            instance=0;
        }
    };
    static Handler handler;

public:

    void load(const QString& f);
    void save(const QString& f);
    static UVManager& getInstance();
    static void libererInstance();
    void ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p);
    const UV& getUV(const QString& code) const;
    UV& getUV(const QString& code);

    class Iterator
    {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Iterator(UV** u, unsigned nb):currentUV(u),nbRemain(nb) {}
    public:
        Iterator():nbRemain(0),currentUV(0) {}
        bool isDone() const
        {
            return nbRemain==0;
        }
        void next()
        {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            nbRemain--;
            currentUV++;
        }
        UV& current() const
        {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    Iterator getIterator()
    {
        return Iterator(uvs,nbUV);
    }

    class iterator
    {
        UV** current;
        iterator(UV** u):current(u) {}
        friend class UVManager;
    public:
        iterator():current(0) {};
        UV& operator*() const
        {
            return **current;
        }
        bool operator!=(iterator it) const
        {
            return current!=it.current;
        }
        iterator& operator++()
        {
            ++current;
            return *this;
        }
    };
    iterator begin()
    {
        return iterator(uvs);
    }
    iterator end()
    {
        return iterator(uvs+nbUV);
    }

    class FilterIterator
    {
        friend class UVManager;
        UV** currentUV;
        unsigned int nbRemain;
        Categorie categorie;
        FilterIterator(UV** u, unsigned nb, Categorie c):currentUV(u),nbRemain(nb),categorie(c)
        {
            while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie) {
                nbRemain--;
                currentUV++;
            }
        }
    public:
        FilterIterator():nbRemain(0),currentUV(0) {}
        bool isDone() const
        {
            return nbRemain==0;
        }
        void next()
        {
            if (isDone())
                throw UTProfilerException("error, next on an iterator which is done");
            do {
                nbRemain--;
                currentUV++;
            } while(nbRemain>0 && (*currentUV)->getCategorie()!=categorie);
        }
        UV& current() const
        {
            if (isDone())
                throw UTProfilerException("error, indirection on an iterator which is done");
            return **currentUV;
        }
    };
    FilterIterator getFilterIterator(Categorie c)
    {
        return FilterIterator(uvs,nbUV,c);
    }
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
