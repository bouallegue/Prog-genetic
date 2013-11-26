#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"
#include "Fenetre.hpp"
#include "OpSelect.hpp"
#include "OpReproduction.hpp"
#include <iostream>

using namespace std;

extern Carte *carteG;
extern Population *popG;

Racine::Racine(){
	 pop=NULL;
	 carte=NULL;
	 stockDonnees=NULL;
	 classeOpSelect=new OpSelect;
	 fenetre=new Fenetre(this);
	 //if(  !texture.loadFromFile( "Images/textureA.png" )  )cout<<"fail load im"<<endl;
}

void Racine::initialiser(){
	 //nbreVille=nombreVille; 
	 //nbreIndividu=nombreIndividu;
	 //pop=new Population(nombreVille, nbreIndividu);
	 
	 //carte=new Carte(nombreVille);
}

void Racine::launch(Donnees *d){
	 if(stockDonnees)return;
	 stockDonnees=d;
	 carte=new Carte(stockDonnees->nbrVille);
	 carteG=carte;
	 //carte->affichage();
	 pop=new Population(stockDonnees->nbrVille, stockDonnees->nbrIndividu);
	 popG=pop;//var globale
	 //pop->afficherPop();
	 classeOpSelect->init();
	 std::vector<unsigned short> gro = classeOpSelect->roulette(5,0);
cout<<"fin rouletee"<<endl;
for(unsigned short i=0;i<gro.size();++i){
	cout<<gro[i]<<endl;
}
	 //classeOpSelect->roulette(1);
	 //classeOpSelect->tournoi(5, 10);
	 //classeOpSelect->elitisme(5);
	 classeOpReprod=new OpReproduction(gro);
cout<<"fin op reprod"<<endl;
	 Population enfants=classeOpReprod->newGen();
	 enfants.afficherPop();
}

void Racine::lancerProg(){
	fenetre->gestionEvent();
} 

Racine::~Racine(){
	 if(fenetre)delete fenetre;
	 if(carte)delete carte;
	 //if(pop)delete pop;BUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGG
	 if(classeOpSelect)delete classeOpSelect;
}
