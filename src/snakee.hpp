
#ifndef UNTITLED5_SNAKEE_HPP
#define UNTITLED5_SNAKEE_HPP
typedef struct parametre{
    int move;
    int Size;
    float delai;
    int Score;
    int snaketaille2;
    int move2 ;
    int snaketaille;
} parametre;


void snakee(sf::RenderWindow &window,sf:: Clock &timer,sf::Sound &sound_menu,sf::Sprite &sprite,sf::Texture &back,sf::RectangleShape &player, sf::RectangleShape &player2,sf::Texture &texture,sf::Sprite &pomet,sf::Sprite &pieget,parametre &parametr, int &musiqueIsPlaying,int NbJoueur);
void mache(parametre &parametr);

#endif //UNTITLED5_SNAKEE_HPP
