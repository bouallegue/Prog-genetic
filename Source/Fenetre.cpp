#include <sstream>
#include "Fenetre.hpp"
#include "constantes.hpp"

using namespace std;

Fenetre::Fenetre(){
	 windowSF.create(sf::VideoMode(LARGEUR_FENETRE, LONGUEUR_FENETRE), "shoot", sf::Style::Default);
	 // MIN MAX PAS
	 spinNombreVille = sfg::SpinButton::Create( 3.f, 20.f, 1.f );
	 // taille du spinbox
	 spinNombreVille->SetRequisition( sf::Vector2f( 80.f, 0.f ) );
	 // Set the number of digits to display after the decimal point.
	 //spinNombreVille->SetDigits( 0 );
	 spinNombreInd = sfg::SpinButton::Create( 10.f, 500.f, 10.f );
	 // taille du spinbox
	 spinNombreInd->SetRequisition( sf::Vector2f( 80.f, 0.f ) );
	 // Set the number of digits to display after the decimal point.
	 //spinNombreInd->SetDigits( 0 );
	 combOpSelect = sfg::ComboBox::Create();
	 combOpSelect->AppendItem( "opA" );
	 combOpSelect->PrependItem( "opB" );
	 
	 combOpReplace = sfg::ComboBox::Create();
	 combOpReplace->AppendItem( "opA" );
	 combOpReplace->PrependItem( "opB" );
	 
	 combModCroismnt = sfg::ComboBox::Create();
	 combModCroismnt->AppendItem( "opA" );
	 combModCroismnt->PrependItem( "opB" );
	 //valeur par defaut
	 nbrVille=4;
	 nbrIndividu=10;
	 opSelect=0;
	 opReplace=0;
	 modeCroisement=0;
}

void Fenetre::gestionEvent(){
	 sf::Event event;
	 sf::Clock clock;
	 sfg::Box::Ptr box( sfg::Box::Create( sfg::Box::VERTICAL, 5.0f ) );
	 sfg::Window::Ptr windowSFG( sfg::Window::Create() );
	 sfg::Desktop desktop;
	 sfg::Label::Ptr labelA, labelB, labelC, labelD, labelE, labelF;
	 sfg::Button::Ptr buttonReset, buttonLaunch;
	 
	 
	 labelA = sfg::Label::Create( "Nombre Villes?" );
	 labelB = sfg::Label::Create( "Nombre Individus?" );
	 labelC = sfg::Label::Create( "Operateur de selection?" );
	 labelD = sfg::Label::Create( "Operateur de remplacement?" );
	 labelE = sfg::Label::Create( "mode de croisement?" );
	 labelF = sfg::Label::Create( "iteration?" );
	 
	 buttonReset = sfg::Button::Create( "RESET" );
	 buttonLaunch = sfg::Button::Create( "LAUNCH" );
	 
	 windowSF.setFramerateLimit(20);
	 
	 // Set the entries of the combo box.
	 
	 
	 
	 spinNombreVille->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreVille, this );
	 spinNombreInd->GetSignal( sfg::SpinButton::OnValueChanged ).Connect( &Fenetre::setNombreInd, this );
	 combOpSelect->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseSelectionOperator, this );
	 combOpReplace->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseReplaceOperator, this );
	 combModCroismnt->GetSignal( sfg::ComboBox::OnSelect ).Connect( &Fenetre::chooseModeCroisement, this );
	 buttonReset->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Fenetre::signalReset, this );
	 buttonLaunch->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Fenetre::signalLaunch, this );

	 // Add the SpinButton to the box.
	 box->Pack( labelA );
	 box->Pack( spinNombreVille );
	 box->Pack( labelB );
	 box->Pack( spinNombreInd );
	 box->Pack( labelC );
	 box->Pack( combOpSelect );
	 box->Pack( labelD );
	 box->Pack( combOpReplace );
	 box->Pack( labelE );
	 box->Pack( combModCroismnt );
	 box->Pack( buttonReset, false );
	 box->Pack( buttonLaunch, false );
	 
	 
	 spinNombreVille->SetValue( 4.f );
	 windowSFG->SetTitle( "Fenetre" );
	 windowSFG->Add( box );
	 
	 desktop.Add( windowSFG );
	 
	 windowSF.resetGLStates();
	 
	while ( windowSF.isOpen() ){
		//sf::Clock temps;
		//window.pollEvent(event);
		if (/* event.type == sf::Event::Closed  ||*/  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
		  windowSF.close();
		  break;
		}
		while( windowSF.pollEvent( event ) ) {
		  desktop.HandleEvent( event );
		}
		desktop.Update( clock.restart().asSeconds() );
		// Rendering.
		//windowSF.clear(sf::Color::Black);
		sfgui.Display( windowSF );
		windowSF.display();
	}
}

void Fenetre::setNombreVille() {
	 nbrVille=spinNombreVille->GetValue ();
	 cout<< nbrVille<<"   Ville"<<endl;
}

void Fenetre::setNombreInd(){
	 nbrIndividu=spinNombreInd->GetValue ();
	 cout<<nbrIndividu<<"   Individu"<<endl;
}

void Fenetre::chooseSelectionOperator(){
	 opSelect=combOpSelect->GetSelectedItem();
	 cout<<opSelect<<"   operateur de selection"<<endl;
}

void Fenetre::chooseReplaceOperator(){
	 opReplace=combOpReplace->GetSelectedItem();
	 cout<<opReplace<<"   operateur de remplacement"<<endl;
}

void Fenetre::chooseModeCroisement(){
	 modeCroisement=combModCroismnt->GetSelectedItem();
	 cout<<modeCroisement<<"   Mode Croisement"<<endl;
}

void Fenetre::signalReset(){
	 cout<<"reset"<<endl;
}

void Fenetre::signalLaunch(){
	 cout<<"launch"<<endl;
}

Fenetre::~Fenetre(){
	 
}