#include <iostream>
#include "Racine.hpp"
#include "constantes.hpp"
#include "Carte.hpp"
#include "Population.hpp"

using namespace std;

Racine::Racine(unsigned short nombreVille, unsigned short nombreIndividu){
  largeurFenetre=500; 
  longueurFenetre=400;
	nbreVille=nombreVille; 
	nbreIndividu=nombreIndividu;
  //if(  !texture.loadFromFile( "Images/textureA.png" )  )cout<<"fail load im"<<endl;
  frame=0;
  pop=new Population(nombreVille, nbreIndividu);
  render_window.create(sf::VideoMode(largeurFenetre, longueurFenetre), "shoot", sf::Style::Default);
carte=new Carte(nombreVille);
}

void Racine::initialiser(){
	cout<<"test"<<endl;	
}

void Racine::lancerProg(){
	//unsigned short stock=0;
	render_window.setFramerateLimit(20);	
	
	sf::Event event;
  sf::Clock clock;
	sfg::Button::Ptr button( sfg::Button::Create( "BOUTON" ) );
  button->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Racine::initialiser, this );
	sfg::Button::Ptr bubu( sfg::Button::Create( "bubu" ) );
  bubu->GetSignal( sfg::Widget::OnLeftClick ).Connect( &Racine::initialiser, this );

	sfg::Box::Ptr box( sfg::Box::Create( sfg::Box::VERTICAL, 5.0f ) );
  box->Pack( button, false );
	box->Pack( bubu, false );

	sfg::Window::Ptr window( sfg::Window::Create() );
  window->SetTitle( "sf" );
  window->Add( box );

	sfg::Desktop desktop;
  desktop.Add( window );
	render_window.resetGLStates();
	while ( render_window.isOpen() ){
	  //sf::Clock temps;
		//window.pollEvent(event);
		//render_window.pollEvent( event );
		//desktop.HandleEvent( event );

		while( render_window.pollEvent( event ) ) {
      desktop.HandleEvent( event );
      // If window is about to be closed, leave program.
      if( event.type == sf::Event::Closed  ||  sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) {
              render_window.close();
      }
		}
		desktop.Update( clock.restart().asSeconds() );
		render_window.clear();
    m_sfgui.Display( render_window );
    render_window.display();
		

		//window.draw( joueur->getSprite() );
	}
} 

Racine::~Racine(){}
