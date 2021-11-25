//
// Created by Thomas on 07/11/2021.
//

#ifndef UNTITLED5_MENU_H
#define UNTITLED5_MENU_H
#include "SFML/Graphics.hpp"
#define NB_ITEM 3


class Menu
{
public:
    Menu();
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void haut();
    void bas();
    int confirmer_choix();
private :
    int choix;
    sf::Font font;
    sf::Text menu[NB_ITEM];

};


#endif //UNTITLED5_MENU_H
