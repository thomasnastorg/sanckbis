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
    int larg = 640;
    int longueur = 640;
    int Size = 20;

    sf::RenderWindow window( sf::VideoMode( larg, longueur), "Awesome Game" );
    sf:: Clock timer;
    Menu menu(640, 640);
    NbJoueur nbjoueur(640,640);
    int choixUser=0, choixUserBis=0;


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
            if (choixUserBis == 1){
                snakee(window, timer);
            }
        }
    }
}
