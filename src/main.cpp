#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ostream>
#include <iostream>
#include <random>
using std::cout;
void generationPomme(bool &object,sf::RenderWindow &window ,int &positionX, int &positionY);
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

bool pomme = false;
int checkmove = 1;
int tableauxX [100],tableauxY [100]; //le fair avec un list si je peux
int positionX, positionY, suiviX=-50,suiviY=0;
//-------initialisation du tableaux


int main()
{

    float x = 0;
    float y = 0;

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
    sound_menu.play();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
        }



        int suiviX = 0;
        int suiviY = 0;
        window.draw(sprite);
        window.clear();
        sf::Vector2f postionFirst= player.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& move != 2) move = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& move != 3) move = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& move != 0 ) move = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&& move != 1) move = 3;




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



void generationPomme(bool &object, sf::RenderWindow &window, int &positionX, int &positionY )
{

    sf::RectangleShape pommme(sf::Vector2f(50.0f,50.0f)) ;
    pommme.setFillColor(sf::Color::Green);
    if(object == false)
    {
        sf::Vector2u size = window.getSize();
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distrx(1, size.x);
        std::uniform_int_distribution<int> distry(1, size.y);
        cout << distrx(eng) << "; ";
        positionX = distrx(eng);
        positionY = distry(eng);
        object = true;
    }

    pommme.setPosition(positionX,positionY);
    window.draw(pommme);
}

