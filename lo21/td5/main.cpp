#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QFileDialog>
#include "UTProfiler.h"

int exercice1(int argc, char * argv[]){
    
    QApplication app(argc, argv);
    QPushButton b("TP6");
    b.show();
    QObject::connect(&b, SIGNAL(clicked()),&app, SLOT(quit()));
    return app.exec();
}
int exercice2(int argc, char * argv[]){
    
    QApplication app(argc, argv);
    QWidget fenetre;
    //fenetre.setFixedSize(750,300);
    QLineEdit code(&fenetre);
    code.setFixedWidth(180);
    QTextEdit titre(&fenetre);
    titre.setFixedSize(180,110);
    QPushButton sauver("Sauver",&fenetre);
    sauver.setFixedSize(80, 80);
    
    QVBoxLayout couche;
    couche.addWidget(&code);
    couche.addWidget(&titre);
    couche.addWidget(&sauver);
    fenetre.setLayout(&couche);
    
    UVManager& m = UVManager::getInstance();
    QString chemin = QFileDialog::getOpenFileName();
    m.load(chemin);
    
    UV& lo21=m.getUV("LO21");
    code.setText(lo21.getCode());
    titre.setText(lo21.getTitre());
    
    fenetre.show();
    return app.exec();
}

int main(int argc, char * argv[]){
    return exercice2(argc, argv);
}

