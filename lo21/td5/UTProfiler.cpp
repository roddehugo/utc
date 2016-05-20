#include "UTProfiler.h"

#include <sstream>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>

QTextStream& operator<<(QTextStream& f, const UV& uv){
	return f<<uv.getCode()<<", "<<uv.getCategorie()<<", "<<uv.getNbCredits()<<" credits, "<<uv.getTitre();
}

QTextStream& operator>>(QTextStream& f, Categorie& cat){
    QString str;
	f>>str;
    if (str=="CS") cat=CS;
	else
    if (str=="TM") cat=TM;
	else
    if (str=="SP") cat=SP;
	else
    if (str=="TSH") cat=TSH;
	else {
        throw UTProfilerException("erreur, lecture categorie");
	}
	return f;
}

Categorie StringToCategorie(const QString& str){
    if (str=="CS") return CS;
    else
    if (str=="TM") return TM;
    else
    if (str=="SP") return SP;
    else
    if (str=="TSH") return TSH;
    else {
        throw UTProfilerException(QString("erreur, StringToCategorie, categorie ")+str+" inexistante");
    }
}

QString CategorieToString(Categorie c){
    switch(c){
    case CS: return "CS";
    case TM: return "TM";
    case SP: return "SP";
    case TSH: return "TSH";
    default: throw UTProfilerException("erreur, categorie non traitee",__FILE__,__LINE__);
    }
}

QTextStream& operator<<(QTextStream& f, const Categorie& cat){
    return f<<CategorieToString(cat);
}

UVManager::UVManager():uvs(0),nbUV(0),nbMaxUV(0),file(""),modification(false){
}


void UVManager::load(const QString& f){
    if (file!=f) this->~UVManager();
    file=f;

    QFile fin(file);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw UTProfilerException("Erreur ouverture fichier UV");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named uvs, we'll go to the next.
            if(xml.name() == "uvs") continue;
            // If it's named uv, we'll dig the information from there.
            if(xml.name() == "uv") {
                QString code;
                QString titre;
                unsigned int nbCredits;
                Categorie cat;
                bool automne=false;
                bool printemps=false;

                QXmlStreamAttributes attributes = xml.attributes();
                /* Let's check that uvs has attribute. */
                if(attributes.hasAttribute("automne")) {
                    QString val =attributes.value("automne").toString();
                    automne=(val == "true" ? true : false);
                }
                if(attributes.hasAttribute("printemps")) {
                    QString val =attributes.value("printemps").toString();
                    printemps=(val == "true" ? true : false);
                }

                xml.readNext();
                //We're going to loop over the things because the order might change.
                //We'll continue the loop until we hit an EndElement named uv.


                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "uv")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        // We've found code.
                        if(xml.name() == "code") {
                            xml.readNext(); code=xml.text().toString();
                        }
                        // We've found titre.
                        if(xml.name() == "titre") {
                            xml.readNext(); titre=xml.text().toString();
                        }
                        // We've found credits.
                        if(xml.name() == "credits") {
                            xml.readNext(); nbCredits=xml.text().toString().toUInt();
                        }
                        // We've found categorie
                        if(xml.name() == "categorie") {
                            xml.readNext(); cat=StringToCategorie(xml.text().toString());
                        }
                    }
                    // ...and next...
                    xml.readNext();
                }
                ajouterUV(code,titre,nbCredits,cat,automne,printemps);

            }
        }
    }
    // Error handling.
    if(xml.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier UV, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
}



void UVManager::save(const QString& f){
    file=f;
    QFile newfile( file);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text)) throw UTProfilerException(QString("erreur ouverture fichier xml"));
     QXmlStreamWriter stream(&newfile);
     stream.setAutoFormatting(true);
     stream.writeStartDocument();
     stream.writeStartElement("uvs");
     for(unsigned int i=0; i<nbUV; i++){
         stream.writeStartElement("uv");
         stream.writeAttribute("automne", (uvs[i]->ouvertureAutomne())?"true":"false");
         stream.writeAttribute("printemps", (uvs[i]->ouverturePrintemps())?"true":"false");
         stream.writeTextElement("code",uvs[i]->getCode());
         stream.writeTextElement("titre",uvs[i]->getTitre());
         QString cr; cr.setNum(uvs[i]->getNbCredits());
         stream.writeTextElement("credits",cr);
         stream.writeTextElement("categorie",CategorieToString(uvs[i]->getCategorie()));
         stream.writeEndElement();
     }
     stream.writeEndElement();
     stream.writeEndDocument();

     newfile.close();

}

UVManager::~UVManager(){
    if (file!="") save(file);
	for(unsigned int i=0; i<nbUV; i++) delete uvs[i];
	delete[] uvs;
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

void UVManager::ajouterUV(const QString& c, const QString& t, unsigned int nbc, Categorie cat, bool a, bool p){
	if (trouverUV(c)) {
        throw UTProfilerException(QString("erreur, UVManager, UV ")+c+QString("déja existante"));
	}else{
        UV* newuv=new UV(c,t,nbc,cat,a,p);
		addItem(newuv);
		modification=true;
	}
}

UV* UVManager::trouverUV(const QString& c)const{
	for(unsigned int i=0; i<nbUV; i++)
		if (c==uvs[i]->getCode()) return uvs[i];
	return 0;
}

UV& UVManager::getUV(const QString& code){
	UV* uv=trouverUV(code);
    if (!uv) throw UTProfilerException("erreur, UVManager, UV inexistante",__FILE__,__LINE__);
	return *uv;
}


const UV& UVManager::getUV(const QString& code)const{
	return const_cast<UVManager*>(this)->getUV(code);
		// on peut aussi dupliquer le code de la méthode non-const
}

UVManager::Handler UVManager::handler=Handler();

UVManager& UVManager::getInstance(){
    if (!handler.instance) handler.instance = new UVManager; /* instance créée une seule fois lors de la première utilisation*/
    return *handler.instance;
}

void UVManager::libererInstance(){
    if (handler.instance) { delete handler.instance; handler.instance=0; }
}
