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
