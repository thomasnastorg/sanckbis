//
// Created by Thomas on 07/11/2021.
//

#include "menu.h"
#include "SFML/Graphics.hpp"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        //erreur;
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Jouer");
    menu[0].setPosition(sf::Vector2f(width/2, height/(NB_ITEM + 1) * 1));
    //menu[0].setCharacterSize(60);

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width/2, height/(NB_ITEM + 1) * 2));
    //menu[1].setCharacterSize(60);

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quitter");
    menu[2].setPosition(sf::Vector2f(width/2, height/(NB_ITEM + 1) * 3));
    //menu[2].setCharacterSize(60);

    choix=0;
}

Menu::Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i=0; i<NB_ITEM; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::bas()
{
    if (choix + 1 < NB_ITEM)
    {

        menu[choix].setFillColor(sf::Color::White);
        choix++;
        menu[choix].setFillColor(sf::Color::Blue);

    }
}
void Menu::haut()
{
    if (choix - 1 >=0)
    {
        menu[choix].setFillColor(sf::Color::White);
        choix--;
        menu[choix].setFillColor(sf::Color::Blue);
    }
}
int Menu::confirmer_choix()
{
    return choix;
}