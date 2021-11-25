//
// Created by Thomas on 07/11/2021.
//

#include "nbJoueur.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

NbJoueur::NbJoueur(float width, float height)
{


    if (!font.loadFromFile("../Font/Vandalism.ttf"))
    {
        //erreur;
    }

    nbJoueur[0].setFont(font);
    nbJoueur[0].setFillColor(sf::Color::Green);
    nbJoueur[0].setString("un Joueur");
    //menu[0].setOrigin(width/2,height/2);
    nbJoueur[0].setPosition(sf::Vector2f((width/2)-50, height/(NB_ITEMM + 1) * 1));
    //menu[0].setCharacterSize(60);

    nbJoueur[1].setFont(font);
    nbJoueur[1].setFillColor(sf::Color::White);
    nbJoueur[1].setString("Deux joueur");
    //menu[1].setOrigin(width/2,height/2);
    nbJoueur[1].setPosition(sf::Vector2f((width/2)-50, height/(NB_ITEMM + 1) * 2));
    //menu[1].setCharacterSize(60);

    choix=0;
}

NbJoueur::NbJoueur()
{

}

void NbJoueur::draw(sf::RenderWindow &window)
{
    int musiqueIsPlayingMenu =0;


    if(musiqueIsPlayingMenu == 0){
        //sound_menuu.play();
        musiqueIsPlayingMenu = 1;
    }

    sf::Texture texture;
    sf::Texture backMenu;
    backMenu.loadFromFile("../images/retro_blur.jpg");
    sf::Sprite sprite;
    sprite.setTexture(backMenu);
    window.draw(sprite);
    for (int i=0; i<NB_ITEMM; i++)
    {
        window.draw(nbJoueur[i]);
    }
}

void NbJoueur::bas()
{
    if (choix + 1 < NB_ITEMM)
    {

        nbJoueur[choix].setFillColor(sf::Color::White);
        choix++;
        nbJoueur[choix].setFillColor(sf::Color::Green);

    }
}
void NbJoueur::haut()
{
    if (choix - 1 >=0)
    {
        nbJoueur[choix].setFillColor(sf::Color::White);
        choix--;
        nbJoueur[choix].setFillColor(sf::Color::Green);
    }
}
int NbJoueur::confirmer_choix()
{
    return choix;
}