#ifndef LOG_H
#define LOG_H
#include "timing.h"
#include <iostream>
#include "evenement.h"



class log
{
public:
    virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string & s)=0;
    virtual void displayLog(std::ostream& f) const=0;
    log();
};
namespace AD
{

class MyLog : public log
{
    TIME::Agenda A;

public:
    void addEvt (const TIME::Date& d, const TIME::Horaire& h, const std::string& s)
    {
        TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
        A<<e;
    }
    void displayLog(std::ostream& f ) const
    {
        A.afficher(f);
    }
};

}

namespace AC
{

class MyLog : public log , private TIME::Agenda
{
public:
    void addEvt (const TIME::Date& d, const TIME::Horaire& h, const std::string& s)
    {
        TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
        *this<<e;
    }
    void displayLog(std::ostream& f ) const
    {
        afficher(f);
    }
};

}

#endif // LOG_H
