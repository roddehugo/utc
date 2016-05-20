#include "UTProfiler.h"
#include <fstream>
#include <sstream>

//UVManager* UVManager::instanceUnique = 0; //

UVManager::Handler UVManager::handler=Handler();

ostream& operator<<(ostream& f, const UV& uv){
	return f<<uv.getCode()<<", "<<uv.getCategorie()<<", "<<uv.getNbCredits()<<" credits, "<<uv.getTitre();
}

istream& operator>>(istream& f, Categorie& cat){
	string str;
	f>>str;
	if (str=="CS") cat=CS;
	else
	if (str=="TM") cat=TM;
	else
	if (str=="SP") cat=SP;
	else
	if (str=="TSH") cat=TSH;
	else {
		ostringstream e;
		e<<"erreur, lecture categorie : "<<str<<" n'est pas une categorie traitee";
		throw UTProfilerException(e.str());
	}
	return f;
}

ostream& operator<<(ostream& f, const Categorie& cat){
	switch(cat){
	case CS: f<<"CS"; break;
	case TM: f<<"TM"; break;
	case SP: f<<"SP"; break;
	case TSH: f<<"TSH"; break;
	default: throw UTProfilerException("erreur, categorie non traitee");
	}
	return f;
}

UVManager::UVManager(const string& f):uvs(0),nbUV(0),nbMaxUV(0),file(f),modification(false){
}

void UVManager::load(const string& f){
	if (f!="") this->~UVManager();
    file=f;
    ifstream fin(file.c_str()); // open file
    if (!fin) throw UTProfilerException("erreur, lors de l'ouverture du fichier d'UV");
    char tmp[256];
    while (!fin.eof()&&fin.good()){
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

void UVManager::addItem(UV* uv){
	if (nbUV==nbMaxUV){
		UV** newtab=new UV*[nbMaxUV+10];
		for(unsigned int i=0; i<nbUV; i++) newtab[i]=uvs[i];
		nbMaxUV+=10;
		UV** old=uvs;
		uvs=newtab;
		delete[] old;
	}
	uvs[nbUV++]=uv;
}

void UVManager::ajouterUV(const string& c, const string& t, unsigned int nbc, Categorie cat){
	if (trouverUV(c)) {
		ostringstream str;
		str<<"erreur, UVManager, UV "<<c<<" deja existante";
		throw UTProfilerException(str.str());	
	}else{
		UV* newuv=new UV(c,t,nbc,cat);
		addItem(newuv);
		modification=true;
	}
}


UV* UVManager::trouverUV(const string& c)const{
	for(unsigned int i=0; i<nbUV; i++)
		if (c==uvs[i]->getCode()) return uvs[i];
	return 0;
}

UV& UVManager::getUV(const string& code){
	UV* uv=trouverUV(code);
	if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante");
	return *uv;
}

const UV& UVManager::getUV(const string& code)const{
	return const_cast<UVManager*>(this)->getUV(code);
		// on peut aussi dupliquer le code de la méthode non-const
}

void UVManager::save(const string& f){
    file=f;
    // maj du fichier d'UV
    ofstream fout(file.c_str(),ofstream::trunc); // toutes les UVs existantes sont écrasées
    for(unsigned int i=0; i<nbUV; i++){
        fout<<uvs[i]->getCode()<<"\n";
        fout<<uvs[i]->getTitre()<<"\n";
        fout<<uvs[i]->getNbCredits()<<"\n";
        fout<<uvs[i]->getCategorie()<<"\n";
        cout<<*uvs[i]<<"\n";
    }
    fout.close();
}

UVManager::~UVManager(){
    if(file!="") save(file);
    for(unsigned int i=0; i<nbUV;i++) delete uvs[i];
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
