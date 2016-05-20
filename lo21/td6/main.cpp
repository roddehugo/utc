#include <iostream>
#include "evenement.h"

using namespace std;

int main(){

    using namespace std;
    using namespace TIME;
    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    e1.afficher();
    e2.afficher();
    Rdv e(Date(11,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    std::cout<<"RDV:";
    e.afficher();
    return 0;
}
