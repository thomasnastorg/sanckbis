#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <iostream>
#include <random>
#include "menu.h"
using std::cout;
int Size = 20;
int larg = 640, longueur = 640;
int move = 1;
int delai = 75;
struct snake{
    int x,y;
}snake[100];

struct pomme{
    int x,y;
}pome;

int snaketaille = 3;
void  marche()
{

    for(int i = snaketaille; i> 0;i--)
    {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake [i-1].y;
    }
    if (move==0) snake[0].y -= 1;
    if (move==1) snake[0].x += 1;
    if (move==2) snake[0].y += 1;
    if (move==3) snake[0].x -= 1;

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

    if (snake[0].x == pome.x && snake[0].y == pome.y){

        pome.x=rand()%Size;
        pome.y=rand()%Size;

        snaketaille++;
    }
}

//-------initialisation du tableaux

int main()
{

    sf:: Clock timer;

    pome.x=rand()%Size;
    pome.y=rand()%Size;

    sf::RenderWindow window( sf::VideoMode( larg, longueur), "Awesome Game" );
    sf::RectangleShape player(sf::Vector2f(Size,Size));
    player.setFillColor(sf::Color::Blue);
    sf:: RectangleShape apple(sf::Vector2f(Size,Size));
    apple.setFillColor(sf::Color::Yellow);

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& move != 2) move = 0;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& move != 3) move = 1;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& move != 0 ) move = 2;
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&& move != 1) move = 3;

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
            }

            if (snake[0].x == Size && snake[0].y == Size)
            {
                window.close();
            }
            timer.restart();
        }
        window.draw(sprite);
        for ( int i = 0; i < snaketaille; i++){

            player.setPosition(snake[i].x*25,snake[i].y*25);
            window.draw(player);
        }
        apple.setPosition(pome.x*25,pome.y*25);

        window.draw(apple);
        window.display();
        }
    }
}