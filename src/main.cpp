#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ostream>
#include <iostream>
#include <random>
using std::cout;
void generationPomme(bool &object,sf::RenderWindow &window ,int &positionX, int &positionY);
void mouveSnack(int tableauxX [100],int tableauxY [100],sf::RenderWindow &window,sf::Vector2f &postion,int suiviX ,int suiviY);
void tpTete(sf::Vector2f &postion,sf::RectangleShape player);

int main()

{

    bool pomme = false;
    int checkmove = 1;
    int tableauxX [100],tableauxY [100]; //le fair avec un list si je peux
    int positionX, positionY, suiviX=-50,suiviY=0;
    //-------initialisation du tableaux
    for (int i=1; i < 100; i++) {
        tableauxX[i]= 0;
        tableauxY[i]= 0;
    }
    // ------backgroud
    sf::Texture texture;
    sf::Texture back;
    back.loadFromFile("../images/brique.jpg");
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sprite.setTexture(back);
    sprite.setOrigin(size.x / 2, size.y / 2);
    //-------
    sf::RenderWindow window( sf::VideoMode( 640, 640), "Awesome Game" );
    sf::RectangleShape player(sf::Vector2f(50.0f,50.0f)) ;
    player.setOrigin(50 / 2, 50 / 2);
    player.setPosition(125, 25);
    player.setFillColor(sf::Color::Black);
    sf::Clock Clock;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        window.draw(sprite);
        sf::Vector2f postionFirst= player.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)&& checkmove != 1){
            player.move(-50.0f,-0.0f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,-50,0);
            suiviX = 50;
            suiviY = 0;
            checkmove = 3;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)&& checkmove != 3){
            player.move(50.0f,0.0f);
            // mouveSnack(tableauxX, tableauxY,window,postionFirst,50,0);
            suiviX = -50;
            suiviY = 0;
            checkmove = 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)&& checkmove != 4){
            player.move(0.0f,-50.0f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,0,-50);
            suiviX = 0;
            suiviY = 50;
            checkmove = 2;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)&& checkmove != 2 ){
            player.move(0.0f,50.0f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,0,50);
            suiviX = 0;
            suiviY = -50;
            checkmove = 4;
        }
        if(checkmove == 1){
            postionFirst.x=postionFirst.x+50;
            player.setPosition(postionFirst.x,postionFirst.y);
        }
        if(checkmove == 2){
            postionFirst.y=postionFirst.y-50;
            player.setPosition(postionFirst.x,postionFirst.y);
        }
        if(checkmove == 3){
            postionFirst.x=postionFirst.x - 50;
            player.setPosition(postionFirst.x,postionFirst.y);
        }
        if(checkmove == 4){
            postionFirst.y=postionFirst.y +50;
            player.setPosition(postionFirst.x,postionFirst.y);
        }
        window.setFramerateLimit(8);
        generationPomme(pomme,window, positionX, positionY);
        //tpTete(postionFirst,player);
        if(postionFirst.x > 640){
            player.setPosition(0, postionFirst.y);
        } else if(postionFirst.x < 0){
            player.setPosition(640, postionFirst.y);
        } else if(postionFirst.y > 640){
            player.setPosition(postionFirst.x, 0);
        } else if(postionFirst.y < 0){
            player.setPosition(postionFirst.x, 640);
        }
        window.draw(player);
        mouveSnack(tableauxX,tableauxY,window, postionFirst,suiviX,suiviY);
        window.draw(player);

        window.display();

    }


    return 0;
}

void mouveSnack(int* tableauxX ,int* tableauxY,sf::RenderWindow &window,sf::Vector2f &postion,int suiviX ,int suiviY){
    sf::RectangleShape player2(sf::Vector2f(50.0f,50.0f)) ;
    player2.setFillColor(sf::Color::Red);
    sf::RectangleShape player3(sf::Vector2f(50.0f,50.0f)) ;
    player3.setFillColor(sf::Color::Yellow);
    sf::RectangleShape player4(sf::Vector2f(50.0f,50.0f)) ;
    player4.setFillColor(sf::Color::Blue);
    sf::RectangleShape player5(sf::Vector2f(50.0f,50.0f)) ;
    player5.setFillColor(sf::Color::Blue);
    player2.setOrigin(50 / 2, 50 / 2);
    player3.setOrigin(50 / 2, 50 / 2);
    player4.setOrigin(50 / 2, 50 / 2);
    player5.setOrigin(50 / 2, 50 / 2);
    int stablepositonX = postion.x , stablepositonY = postion.y;

        tableauxX[3] = tableauxX[2]  ;
        tableauxY[3] = tableauxY[2] ;
        tableauxX[2] = tableauxX[1]  ;
        tableauxY[2] = tableauxY[1] ;
        tableauxX[1] = tableauxX[0] ;
        tableauxY[1] = tableauxY[0]  ;
        tableauxX[0] = postion.x+ suiviX;
        tableauxY[0] = postion.y + suiviY;


        stablepositonX = postion.x;
        stablepositonY = postion.y;


        player2.setPosition(tableauxX[0], tableauxY[0]);
        player3.setPosition(tableauxX[1], tableauxY[1]);
        player4.setPosition(tableauxX[2], tableauxY[2]);
        player5.setPosition(tableauxX[3], tableauxY[3]);

        window.draw(player2);
        window.draw(player3);
        window.draw(player4);
        window.draw(player5);



}

void generationPomme(bool &object, sf::RenderWindow &window, int &positionX, int &positionY )
{
    sf::RectangleShape pomme(sf::Vector2f(50.0f,50.0f)) ;
    pomme.setFillColor(sf::Color::Green);
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
    pomme.setPosition(positionX,positionY);
    window.draw(pomme);
}

void tpTete(sf::Vector2f &postion,sf::RectangleShape player){
    if(postion.x > 640){
        player.setPosition(0, postion.y);
    } else if(postion.x < 0){
        player.setPosition(640, postion.y);
    } else if(postion.y > 640){
        player.setPosition(postion.x, 0);
    } else if(postion.y > 640){
        player.setPosition(postion.x, 640);
    }
}