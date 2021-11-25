
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <iostream>
#include <random>
#include "snakee.hpp"

struct snake{
    int x,y;
}snakes[100];

struct snake2{
    int x,y;
}snakes2[100];

struct piege {

    int x,y;
} piege;
struct pomme{
    int x,y;
} pome;


void snakee(sf::RenderWindow &window,sf:: Clock &timer,sf::Sound &sound_menu,sf::Sprite &sprite,sf::Texture &back,sf::RectangleShape &player, sf::RectangleShape &player2,sf::Texture &texture,sf::Sprite &pomet,sf::Sprite &pieget,parametre &parametr, int &musiqueIsPlaying)
{



if (musiqueIsPlaying == 0){
                sound_menu.play();
                musiqueIsPlaying = 1;
            }
            window.draw(sprite);
            window.clear();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

	      if(parametr.move != 2){
        parametr.move=0;
	      }

	    }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){

	      if(parametr.move != 3){
        parametr.move = 1;
              }

            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

	      if(parametr.move != 0){
        parametr.move = 2;
              }

            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){

	      if(parametr.move != 1){
        parametr.move = 3;
              }

	    }

	      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
              if(parametr.move2 != 2){
            parametr.move2=0;
	      }

            }
	    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

              if(parametr.move2 !=3){
            parametr.move2 = 1;
              }
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

              if(parametr.move2 != 0){
        parametr.move2 = 2;
              }
	    }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

	      if(parametr.move2 != 1){
        parametr.move2 = 3;
              }

            }


        if(timer.getElapsedTime().asMilliseconds()>parametr.delai)
        {
            mache( parametr);
            for(int i = 1; i<parametr.snaketaille; i++)
            {
                if(snakes[0].x == snakes[i].x)
                {
                    if(snakes[0].y == snakes[i].y)
                    {
                       window.close();
		    }
	    }

		if (snakes[0].x == parametr.Size && snakes[0].y == parametr.Size)
            {
                window.close();
            }
		 if (snakes2[0].x == parametr.Size && snakes2[0].y == parametr.Size)
            {
                window.close();
            }



	    if (snakes2[0].x == piege.x && snakes2[0].y == piege.y){
            parametr.snaketaille2 = parametr.snaketaille2-1;
            parametr.Score = parametr.Score-20;
             piege.x=rand()%parametr.Size;
             piege.y=rand()%parametr.Size;
             pome.x=rand()%parametr.Size;
             pome.y=rand()%parametr.Size;

            }

            if (snakes[0].x == piege.x && snakes[0].y == piege.y){
            parametr.snaketaille = parametr.snaketaille-1;
            parametr.delai = parametr.delai+4;
            parametr.Score = parametr.Score-20;
             piege.x=rand()%parametr.Size;
             piege.y=rand()%parametr.Size;
             pome.x=rand()%parametr.Size;
             pome.y=rand()%parametr.Size;
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


        for ( int i = 0; i < parametr.snaketaille; i++){

            player.setPosition(snakes[i].x*25,snakes[i].y*25);
            window.draw(player);



        }
	for ( int i = 0; i < parametr.snaketaille2; i++){
	  player2.setPosition(snakes2[i].x*25,snakes2[i].y*25);
	    window.draw(player2);


	}
        pomet.setPosition(pome.x*25,pome.y*25);
	pieget.setPosition(piege.x*25,piege.y*25);
	window.draw(pomet);
	window.draw(pieget);
        window.display();

	    }
    }

void mache(parametre &parametr){
    for(int i = parametr.snaketaille; i> 0;i--)
    {



        snakes[i].x = snakes[i-1].x;
        snakes[i].y = snakes [i-1].y;
    }

    for(int i = parametr.snaketaille2; i> 0;i--)
    {

        snakes2[i].x = snakes2[i-1].x;
        snakes2[i].y = snakes2[i-1].y;
    }
    if (parametr.move==0) snakes[0].y -= 1;
    if (parametr.move==1) snakes[0].x += 1;
    if (parametr.move==2) snakes[0].y += 1;
    if (parametr.move==3) snakes[0].x -= 1;

    if (parametr.move2==0) snakes2[0].y -= 1;
    if (parametr.move2==1) snakes2[0].x += 1;
    if (parametr.move2==2) snakes2[0].y += 1;
    if (parametr.move2==3) snakes2[0].x -= 1;


    if (snakes[0].x > 25)
    {
        snakes[0].x = 0;
    } else if (snakes[0].x < 0)
    {
        snakes[0].x = 25;
    } else if (snakes[0].y > 25)
    {
        snakes[0].y = 0;
    } else if (snakes[0].y < 0)
    {
        snakes[0].y = 25;
    }

    if (snakes2[0].x > 25)
    {
        snakes2[0].x = 0;
    } else if (snakes2[0].x < 0)
    {
        snakes2[0].x = 25;
    } else if (snakes2[0].y > 25)
    {
        snakes2[0].y = 0;
    } else if (snakes2[0].y < 0)
    {
        snakes2[0].y = 25;
    }


    if (snakes[0].x == pome.x && snakes[0].y == pome.y){

        pome.x=rand()%(parametr.Size);
        pome.y=rand()%parametr.Size;
        piege.x=rand()%parametr.Size;
        piege.y=rand()%parametr.Size;
        parametr.Score = parametr.Score+10;
        parametr.snaketaille++;

        parametr.delai = parametr.delai-4;
        printf("%.2f",parametr.delai);
    }

    if (snakes2[0].x == pome.x && snakes2[0].y == pome.y){

        pome.x=rand()%parametr.Size;
        pome.y=rand()%parametr.Size;
        piege.x=rand()%parametr.Size;
        piege.y=rand()%parametr.Size;
        parametr.Score = parametr.Score+10;
        parametr.snaketaille2++;
    }



    if ( pome.x == piege.x && pome.y == piege.y){

        piege.x=rand()%parametr.Size;
        piege.y=rand()%parametr.Size;

        pome.x=rand()%parametr.Size;
        pome.y=rand()%parametr.Size;
    }
}
