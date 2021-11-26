#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <iostream>
#include <random>
#include "menu.hpp"
#include "nbJoueur.hpp"
#include "snakee.hpp"


//-------initialisation du tableaux

int main()
{
    pomme pome ={0,0};
    piege pieges ={0,0};
    parametre parametr = {1,20,75,0,3,1,3};
    int larg = 640;
    int longueur = 640;
    int Size = 20;

    sf::RenderWindow window( sf::VideoMode( larg, longueur), "Awesome Game" );
    sf:: Clock timer;
    srand(time(NULL));
    Menu menu(640, 640);
    NbJoueur nbjoueur(640,640);
    int choixUser=0, choixUserBis=0;
    sf::Texture texturepieget;
    texturepieget.loadFromFile("../images/piege.png");
    sf::Texture texturepomet;
    texturepomet.loadFromFile("../images/Pomme.png");
    sf::Sprite pieget;
    pieget.setTexture(texturepieget);
    pieget.scale(sf::Vector2f(1,1));
    sf::Sprite pomet;
    pomet.setTexture(texturepomet);
    pomet.scale(sf::Vector2f(1,1));
    sf::Color colorsnake(147,112,219);
    sf::Color colorsnake2(100,112,219);
    sf::RectangleShape player(sf::Vector2f(parametr.Size,parametr.Size));
    player.setFillColor(colorsnake);
    sf::RectangleShape player2(sf::Vector2f(parametr.Size,parametr.Size));
    player.setFillColor(colorsnake2);

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

    while (window.isOpen()) {
        if (choixUser == 0) {
            menu.draw(window);
            window.display();
        }
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Z) {
                    menu.haut();
                } else if (event.key.code == sf::Keyboard::S) {
                    menu.bas();
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    if (menu.confirmer_choix() == 0) choixUser = 1;
                    else if (menu.confirmer_choix() == 1) choixUser = 2;
                    else if (menu.confirmer_choix() == 2) choixUser = 3;
                }
            }
            if (event.type == sf::Event::Closed)

                window.close();
        }
        if (choixUser == 1) {
                window.clear();
            if (choixUserBis == 0) {
                nbjoueur.draw(window);
                window.display();
            }
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Z) {
                        nbjoueur.haut();
                    } else if (event.key.code == sf::Keyboard::S) {
                        nbjoueur.bas();
                    }
                    if (event.key.code == sf::Keyboard::Enter) {
                        if (nbjoueur.confirmer_choix() == 0) choixUserBis = 1;
                        else if (nbjoueur.confirmer_choix() == 1) choixUserBis = 2;
                    }
                }
                if (event.type == sf::Event::Closed)

                    window.close();


            }
            if (choixUserBis > 0){
                snakee(window,timer,sound_menu,sprite,back,player,player2,texture,pomet,pieget, parametr,pome,pieges, musiqueIsPlaying, choixUserBis);
            }

        }

    }
}




