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
