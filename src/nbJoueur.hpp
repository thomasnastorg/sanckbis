//
// Created by Thomas on 07/11/2021.
//

#ifndef UNTITLED5_NBJOUER_HPP
#define UNTITLED5_NBJOUER_HPP
#include "SFML/Graphics.hpp"
#define NB_ITEMM 2


class NbJoueur
{
public:
    NbJoueur();
    NbJoueur(float width, float height);

    void draw(sf::RenderWindow &window);
    void haut();
    void bas();
    int confirmer_choix();
private :
    int choix;
    sf::Font font;
    sf::Text nbJoueur[NB_ITEMM];

};


#endif //UNTITLED5_NBJOUER_HPP
