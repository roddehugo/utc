//
//  Contener.h
//  LO21D9
//
//  Created by Hugo RODDE on 15/05/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#ifndef LO21D9_contener_h
#define LO21D9_contener_h


#include <string>
#include <stdexcept>

namespace TD
{
class ContenerException : public std::exception
{
protected :
    std::string info;
public:
    ContenerException(const std::string& i="") throw() :info(i) {}
    const char* what() const throw()
    {
        return info.c_str();
    }
    ~ContenerException() throw() {}
};

// classe abstraite -> destructeur virtuel
// classe fille instanciable car on redefinit toutes les méthodes virtuelles pures + quelques methodes virtuelles simple
template <class T>
class Contener
{
protected:
    unsigned int nbElem;
public:
    unsigned int size() const
    {
        return nbElem;
    }
    bool empty() const
    {
        return nbElem==0;
    }
    // virtual simple ==> methodes polymorphiques qui peuvent être redéfinies
    // dans les classes filles mais dont on peut fournir un comportement par défaut dans la classe mère.
    // virtual abstraite (=0) ==> on est obligé de définir la méthode dans les classes filles
    virtual T& elem(unsigned int)=0;
    virtual const T& elem(unsigned int) const=0;
    virtual T& front();
    virtual const T& front() const;
    virtual T& back();
    virtual const T& back() const;
    virtual void push_back(const T& x)=0;
    virtual void pop_back()=0;
    virtual void clear();
    Contener(unsigned int nb):nbElem(nb) {};
    virtual ~Contener();
};

template <class T>
T& Contener<T>::front()
{
    return elem(0);
}

template <class T>
const T& Contener<T>::front() const
{
    return elem(0);
}

template <class T>
T& Contener<T>::back()
{
    return elem(nbElem);
}

template <class T>
const T& Contener<T>::back() const
{
    return elem(nbElem);
}

template <class T>
void Contener<T>::clear()
{
    while (!empty()) {
        pop_back();
    }
}

template <class T>
Contener<T>::~Contener() {}

}

#endif

//
//  stack.h
//  LO21D9
//
//  Created by Hugo RODDE on 22/05/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#ifndef LO21D9_stack_h
#define LO21D9_stack_h
namespace TD
{
namespace AO  //Adapter Object
{
template <class T, class CONT=Vector<T> > //Design pattern strategy avec CONT
class Stack
{
    CONT pile;
public:
    bool empty() const
    {
        return pile.empty();
    }
    void push(const T& x)
    {
        pile.push_back();    //qui empile un objet
    }
    void pop()
    {
        pile.pop_back();
    }; //qiu dépile le dernier élement empilé
    unsigned int size() const
    {
        return pile.size();
    }
    T& top()
    {
        return pile.back();    //qui renvoie une référence sur le dernier élément empilé
    }
    const T& top() const
    {
        return pile.back();
    }
    void clear()
    {
        pile.clear();
    }

};
};
namespace AC  //Adapter Class
{
template <class T, class CONT=Vector<T> > //Design pattern strategy avec CONT
class Stack: private CONT
{
public:
    bool empty() const
    {
        return this->CONT::empty();
    }
    void push(const T& x)
    {
        this->CONT::push_back();    //qui empile un objet
    }
    void pop()
    {
        this->CONT::pop_back();
    }; //qiu dépile le dernier élement empilé
    unsigned int size() const
    {
        return this->CONT::size();
    }
    T& top()
    {
        return this->CONT::back();    //qui renvoie une référence sur le dernier élément empilé
    }
    const T& top() const
    {
        return this->CONT::back();
    }
    void clear()
    {
        this->CONT::clear();
    }

};
};
};

#endif

//
//  vector.h
//  LO21D9
//
//  Created by Hugo RODDE on 15/05/2014.
//  Copyright (c) 2014 Hugo RODDE. All rights reserved.
//

#ifndef LO21D9_vector_h
#define LO21D9_vector_h

namespace TD
{

template <class T>
class Vector : public Contener<T>
{
private:
    T* tab;
    unsigned int capacity;
public:
    // pour utiliser les attributs et méthodes de la classe mère on utlise this->
    Vector(unsigned int nbElem=0, const T& val=T()):
        Contener<T>(nbElem), //le constructeur par recopie est généré par défaut car on ne l'a pas redéfini
        tab(new T[this->size()]), //le constructeur sans argument doit exister
        capacity(this->size())
    {
        for (unsigned int i=0; i<this->size(); i++) {
            // Il faut que l'operateur d'affectation de T existe. Ok pour les types par défaut
            tab[i]=val;
        }
    }

    Vector(const Vector<T>& copy):
        Contener<T>(copy),
        tab(new T[this->size()]),
        capacity(this->size())
    {
        for (unsigned int i=0; i<this->size(); i++) {
            // Il faut que l'operateur d'affectation de T existe. Ok pour les types par défaut
            tab[i]=copy.tab[i];
        }
    }

    ~Vector();

    T& elem(unsigned int i);
    const T& elem(unsigned int i) const;
    void push_back(const T& x);
    void pop_back();
    // on peut ré implémenter clear() dans le cas où on peut aller plus vite que le comportement par défaut définie dans Contener
    void clear();
    T& operator[](unsigned int i)
    {
        return elem(i);
    }
    const T& operator[](unsigned int i) const
    {
        return elem(i);
    }
    Vector<T>& operator=(const Vector<T>& other);

    class iterator
    {
        Vector<T>* v;
        unsigned int current;
        iterator(Vector<T>* _v, unsigned int p):v(_v),current(p) {}
        friend class Vector<T>;
    public:
        iterator():v(0),current(0) {};
        T& operator*() const
        {
            return (*v)[current];
        }
        bool operator!=(iterator it) const
        {
            return v!=it.v || current!=it.current;
        }
        bool operator==(iterator it) const
        {
            return v==it.v && current==it.current;
        }
        iterator& operator++()
        {
            ++current;
            return *this;
        }
        iterator& operator--()
        {
            --current;
            return *this;
        }
    };
    iterator begin()
    {
        return iterator(this,0);
    }
    iterator end()
    {
        return iterator(this,this->nbElem);
    }

};

template <class T>
Vector<T>::~Vector()
{
    delete[] tab;
}

template <class T>
T& Vector<T>::elem(unsigned int i)
{
    if (i >= this->size()) {
        throw ContenerException("index out of range");
    }
    return tab[i];
}

template <class T>
const T& Vector<T>::elem(unsigned int i) const
{
    if (i >= this->size()) {
        throw ContenerException("index out of range");
    }
    return tab[i];
}

template <class T>
void Vector<T>::pop_back()
{
    if(this->empty()) {
        throw ContenerException("empty container");
    }
    --this->nbElem;
    //logiquement il faudrait detruire par la suite avec des opérateurs de bas niveaux new et delete
}

template <class T>
void Vector<T>::push_back(const T& val)
{
    if(this->size()==capacity) {
        //c'est mieux de faire un * pour ne pas avoir un comportement linéaire mais logarithmique en terme de complexité
        T* new_t=new T[this->size()*2];
        for (unsigned int i=0; i<this->size(); i++) {
            new_t[i] = tab[i];
        }
        capacity*=2;
        T* old=tab;
        tab=new_t;
        delete[] old;
    }
    tab[this->nbElem++]=val;
}

template <class T>
void Vector<T>::clear()
{
    this->nbElem=0;
    //logiquement il faudrait detruire par la suite avec des opérateurs de bas niveaux new et delete
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    //on vérifie qu'on ne fait pas une auto-affectation
    if(this!=&other) {
        this->~Vector<T>();
        capacity=other-this->size();
        this->nbElem=capacity;
        tab = new T[capacity];
        for (unsigned int i; i<capacity; i++) {
            tab[i]=other.elem(i);
        }
    }
}
};

#endif

