#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <iostream>
#include <random>
#include "menu.hpp"

using std::cout;
int Score = 0;
int Size = 20;
int larg = 640, longueur = 640;
int move = 1;
int snaketaille2 = 3;
int move2 = 1;
float delai = 75;
struct snake{
    int x,y;
}snake[100];

struct snake2{
  int x,y;
}snake2[100];


struct pomme{
    int x,y;
}pome;

struct piege {

  int x,y;
}piege;

int snaketaille = 3;
void  marche()
{

    for(int i = snaketaille; i> 0;i--)
    {

      
        snake[i].x = snake[i-1].x;
        snake[i].y = snake [i-1].y;
    }

        for(int i = snaketaille2; i> 0;i--)
    {

	snake2[i].x = snake2[i-1].x;
	snake2[i].y = snake2[i-1].y;
    }
    if (move==0) snake[0].y -= 1;
    if (move==1) snake[0].x += 1;
    if (move==2) snake[0].y += 1;
    if (move==3) snake[0].x -= 1;
    
    if (move2==0) snake2[0].y -= 1;
    if (move2==1) snake2[0].x += 1;
    if (move2==2) snake2[0].y += 1;
    if (move2==3) snake2[0].x -= 1;


    if (snake[0].x > 25)
    {
        snake[0].x = 0;
    } else if (snake[0].x < 0)
    {
        snake[0].x = 25;
    } else if (snake[0].y > 25)
    {
        snake[0].y = 0;
    } else if (snake[0].y < 0)
    {
        snake[0].y = 25;
    }
    
        if (snake2[0].x > 25)
    {
     	snake2[0].x = 0;
    } else if (snake2[0].x < 0)
    {
	snake2[0].x = 25;
    } else if (snake2[0].y > 25)
    {
        snake2[0].y = 0;
    } else if (snake2[0].y < 0)
    {
     	snake2[0].y = 25;
    }


    if (snake[0].x == pome.x && snake[0].y == pome.y){

        pome.x=rand()%Size;
        pome.y=rand()%Size;
	piege.x=rand()%Size;
	piege.y=rand()%Size;
	Score = Score+10;
        snaketaille++;
	
	delai = delai-4;
	printf("%.2f",delai);
    }

    if (snake2[0].x == pome.x && snake2[0].y == pome.y){

	pome.x=rand()%Size;
    	pome.y=rand()%Size;
        piege.x=rand()%Size;
        piege.y=rand()%Size;
        Score = Score+10;
        snaketaille2++;
    }


    
    if ( pome.x == piege.x && pome.y == piege.y){

	 piege.x=rand()%Size;
	 piege.y=rand()%Size;

    pome.x=rand()%Size;
    pome.y=rand()%Size;


    } 





}

//-------initialisation du tableaux

int main()
{
  sf::Texture texturepieget;
  texturepieget.loadFromFile("../images/piege.png");
  sf::Texture texturepomet;
  texturepomet.loadFromFile("../images/Pomme.png");

  
  sf::Color colorsnake(147,112,219);
  sf::Color colorsnake2(100,112,219);
    sf:: Clock timer;
    srand(time(NULL));
    piege.x=rand()%Size;
    piege.y=rand()%Size;

    pome.x=rand()%Size;
    pome.y=rand()%Size;
    sf::RenderWindow window( sf::VideoMode( larg, longueur), "Awesome Game" );
    sf::RectangleShape player(sf::Vector2f(Size,Size));
    player.setFillColor(colorsnake);
    sf::RectangleShape player2(sf::Vector2f(Size,Size));
    player.setFillColor(colorsnake2);




     sf::Sprite pieget;
    pieget.setTexture(texturepieget);
    pieget.scale(sf::Vector2f(1,1));
    sf::Sprite pomet;
    pomet.setTexture(texturepomet);
    pomet.scale(sf::Vector2f(1,1));
    sf::Texture texture;
    sf::Texture back;
    back.loadFromFile("../images/retro.jpg");
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sprite.setTexture(back);
    sprite.setOrigin(size.x / 2, size.y / 2);
    
    sf::SoundBuffer buffer;
    buffer.loadFromFile("../song/BlueNavi-Starcade.wav");

    sf::Sound sound_menu;
    sound_menu.setBuffer(buffer);
    sound_menu.setVolume(50.f);
    int musiqueIsPlaying = 0;

    Menu menu(640, 640);
    int choixUser=0;


    while (window.isOpen())
    {
        if(choixUser == 0){
        menu.draw(window);
        window.display();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Z)
                {
		   menu.haut();
                }
                else if(event.key.code == sf::Keyboard::S)
                {
                    menu.bas();
                }
                if(event.key.code == sf::Keyboard::Enter)
                {
                    if(menu.confirmer_choix() == 0) choixUser = 1;
                    else if(menu.confirmer_choix() == 1) choixUser = 2;
                    else if(menu.confirmer_choix() == 2) choixUser = 3;
                }
            }
            if (event.type == sf::Event::Closed)

                window.close();
        }
        if (choixUser == 1) {
            if (musiqueIsPlaying == 0){
                sound_menu.play();
                musiqueIsPlaying = 1;
            }
            window.draw(sprite);
            window.clear();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

	      if(move != 2){
		move=0;
	      }
	      
	    }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

	      if(move != 3){
		move = 1;
              }

            }

	    
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

	      if(move != 0){
		move = 2;
              }

            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){

	      if(move != 1){
		move = 3;
              }

	    }

	      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
              if(move2 != 2){
                move2=0;
	      }

            }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

              if(move2 !=3){
                move2 = 1;
              }

            }


            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

              if(move2 != 0){
		move2 = 2;
              }

	    }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

	      if(move2 != 1){
                move2 = 3;
              }

            }


        if(timer.getElapsedTime().asMilliseconds()>delai)
        {
            marche();
            for(int i = 1; i<snaketaille; i++)
            {
                if(snake[0].x == snake[i].x)
                {
                    if(snake[0].y == snake[i].y)
                    {
                       window.close();
		    }
	    }

		if (snake[0].x == Size && snake[0].y == Size)
            {
                window.close();
            }
		 if (snake2[0].x == Size && snake2[0].y == Size)
            {
                window.close();
            }


		
	    if (snake2[0].x == piege.x && snake2[0].y == piege.y){
              snaketaille2 = snaketaille2-1;
          Score = Score-20;
             piege.x=rand()%Size;
             piege.y=rand()%Size;
             pome.x=rand()%Size;
             pome.y=rand()%Size;

            }
	    
            if (snake[0].x == piege.x && snake[0].y == piege.y){
              snaketaille = snaketaille-1;
              delai = delai+4;
              Score = Score-20;
             piege.x=rand()%Size;
             piege.y=rand()%Size;
             pome.x=rand()%Size;
             pome.y=rand()%Size;
            }
	
	    

            timer.restart();
        }
	    }
    




	

	char nb = '0';
            std::string PATH = "../images/animation_backend/retro";
            std::string path;
            while (nb <= '9') {

                path = PATH;
		path += nb;
                nb += 1;
                path += ".jpg";

		back.loadFromFile(path);
                sf::Vector2u size = texture.getSize();
     	        sprite.setTexture(back);
	        sprite.setOrigin(size.x / 2, size.y / 2);
                window.clear();
	        window.draw(sprite);

    		
        window.draw(sprite);
	    
	
        for ( int i = 0; i < snaketaille; i++){

            player.setPosition(snake[i].x*25,snake[i].y*25);
            window.draw(player);



        }
	for ( int i = 0; i < snaketaille2; i++){
	  player2.setPosition(snake2[i].x*25,snake2[i].y*25);
	    window.draw(player2);


	}


        pomet.setPosition(pome.x*25,pome.y*25);
	pieget.setPosition(piege.x*25,piege.y*25);
	window.draw(pomet);
	window.draw(pieget);
        window.display();

	    
	    }
	    }	    
	}
	}


    
