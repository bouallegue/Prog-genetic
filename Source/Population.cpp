Population::Population(unsigned short nombreVille, unsigned short nombreIndividu){
	nbreVille=nombreVille; 
	nbreIndividu=nombreIndividu;
	tabIndividu=new Individu[nombreIndividu](nombreVille);
	
}

void Population::afficherPop(){
	for(unsigned short i=0;i<nbreIndividu;i++){
	 	tabIndividu[i].afficherInd();
	}
}

Population::~Population(){
	delete tabIndividu;
}

