
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

typedef struct pomme{
    int x,y;
} pomme;
typedef struct piege {
    int x,y;
} piege;


void snakee(sf::RenderWindow &window,sf:: Clock &timer,sf::Sound &sound_menu,sf::Sprite &sprite,sf::Texture &back,sf::RectangleShape &player, sf::RectangleShape &player2,sf::Texture &texture,sf::Sprite &pomet,sf::Sprite &pieget,parametre &parametr,pomme &pomme,piege &piege, int &musiqueIsPlaying,int NbJoueur);
void mache(parametre &parametr,pomme &pomme,piege &piege);

#endif //UNTITLED5_SNAKEE_HPP
