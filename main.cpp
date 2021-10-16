#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ostream>
#include <iostream>
#include <random>
using std::cout;
void generationPomme(bool &object,sf::RenderWindow &window ,int &positionX, int &positionY);
void mouveSnack(int tableauxX [100],int tableauxY [100],sf::RenderWindow &window,sf::Vector2f &postion,int suiviX ,int suiviY);
int main()
{
    bool pomme = false;
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
    back.loadFromFile("/Users/thomas/SynologyDrive/snack/snackbis/images/brique.jpg");
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sprite.setTexture(back);
    sprite.setOrigin(size.x / 2, size.y / 2);
    //-------
    sf::RenderWindow window( sf::VideoMode( 640, 640), "Awesome Game" );
    sf::RectangleShape player(sf::Vector2f(50.0f,50.0f)) ;
    player.setFillColor(sf::Color::Black);
    //------ corps serpent
    sf::RectangleShape player2(sf::Vector2f(50.0f,50.0f)) ;
    player2.setFillColor(sf::Color::Red);
    sf::RectangleShape player3(sf::Vector2f(50.0f,50.0f)) ;
    player3.setFillColor(sf::Color::Yellow);

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
            player.move(-0.1f,-0.0f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,-50,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            player.move(0.1f,0.0f);
            // mouveSnack(tableauxX, tableauxY,window,postionFirst,50,0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
            player.move(0.0f,-0.1f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,0,-50);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            player.move(0.0f,0.1f);
            //mouveSnack(tableauxX, tableauxY,window,postionFirst,0,50);
        }
        generationPomme(pomme,window, positionX, positionY);
        window.draw(player);








        window.display();
    }


    return 0;
}

void mouveSnack(int tableauxX [100],int tableauxY [100],sf::RenderWindow &window,sf::Vector2f

&postion,int suiviX ,int suiviY){
    sf::RectangleShape player2(sf::Vector2f(50.0f,50.0f)) ;
    player2.setFillColor(sf::Color::Red);
    sf::RectangleShape player3(sf::Vector2f(50.0f,50.0f)) ;
    player3.setFillColor(sf::Color::Yellow);
    while (suiviX != 0 || suiviY != 0 ) {
        tableauxX[0] = postion.x + suiviX;
        tableauxY[0] = postion.y + suiviY;


        for (int i=0; i<100; i++)
        {
            int tpm1,tpm2;
            tableauxX[i+1]=tableauxX[i];
            tableauxY[i+1]=tableauxY[i];
            /*tpm1 = tableauxX[i+1];
            tableauxX[i+1] = tableauxX[i];
            tableauxX[i] =tpm1;
            tpm2 = tableauxY[i+1];
            tableauxY[i+1] = tableauxY[i];
            tableauxY[i] = tpm2;
        */
        }
        //player2.setPosition(tableauxX[0], tableauxX[0]);
        //player3.setPosition(tableauxX[1], tableauxX[1]);

        //window.draw(player2);
        // window.draw(player3);
    }


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
