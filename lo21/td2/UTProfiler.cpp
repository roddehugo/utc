//
//  UTProfiler.cpp
//  UTProfiler
//
//  Created by Samuel F on 27/03/2014.
//  Copyright (c) 2014 Samuel. All rights reserved.
//

#include "UTProfiler.h"
void UVManager::addItem(UV * uv ){
    if (nbUV<nbMaxUV) {
        nbUV++;
        uvs[nbUV]=uv;
    }
    
    else {
        UV** uvsn;
        uvsn= new UV*[nbMaxUV+10];
        memcpy(uvsn, uvs, sizeof(UV*)*nbMaxUV );
        nbMaxUV+=10;
        UV** old=uvs;
        uvs=uvsn;
        delete [] old;
        nbUV++;
        uvs[nbUV]=uv;
    }

}

UVManager::UVManager():uvs(0),nbUV(0),nbMaxUV(0){}

void UVManager::ajouterUV(const string& c, const string &t, unsigned int nbc, Categorie cat){
    if (trouveUV(c)!=0) {
                throw UTProfilerException(string("UV ")+c+string(" déja existante "));
        }
    UV* pt= new UV (c,t,nbc,cat);
    addItem(pt);
    }

UV* UVManager::trouveUV(const string&c) const {
    for (unsigned int i=0; i<nbUV; i++) {
        if (uvs[i]->getCode()==c)
            return uvs[i];
    }
    return 0;
}
UV& UVManager::getUV(const string& code){
    UV* uv=trouveUV(code);
    if (uv==0) throw UTProfilerException(string("UV ")+code+string(" n'existe pas."));
    return *uv;
}

const UV& UVManager::getUV(const string& code) const {
    //appel de la méthode non-const
    return const_cast<UVManager*>(this)->getUV(code);
}
UVManager::~UVManager(){
    for (unsigned int i=0; i<=nbUV; i++) {
        delete uvs[i];
    }
    delete [] uvs;
}
UVManager::UVManager(const UVManager& m):
    nbUV(m.nbUV),nbMaxUV(m.nbUV),uvs(new UV* [nbUV])
{for (unsigned int i=0; i<nbUV; i++)
    uvs[i]=new UV(*m.uvs[i]);//création d'une nouvelle UV par recopie
    
}
UVManager& UVManager::operator=(const UVManager& m){
    if (this!=&m){//protection auto affectation
        //detruire les anciennes uv
        for(unsigned int i=0;i<nbUV;i++) delete uvs[i];
    }
    nbUV=0;
    for(unsigned int i=0;i<nbUV;i++){
        UV* uv= new UV(*m.uvs[i]);
        addItem(uv);
    }
    
    return *this ;
}


