#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(480, 480), "Tanks");

    Font font;
    font.loadFromFile("20136.ttf");
    Text text("", font, 60);

    Texture polygon;
    polygon.loadFromFile("polygon.png");

    Sprite Polygon;
    Polygon.setTexture(polygon);
    Polygon.setPosition(0, 0);

    Texture tank_o;
    tank_o.loadFromFile("Sprite_tanks.png");

    Sprite Tank_o;
    Tank_o.setTexture(tank_o);
    Tank_o.setTextureRect(IntRect(0, 0, 19, 30));
    Tank_o.setPosition(70, 390);

    Texture tank_t;
    tank_t.loadFromFile("Sprite_tanks.png");

    Sprite Tank_t;
    Tank_t.setTexture(tank_t);
    Tank_t.setTextureRect(IntRect(0, 40, 17, 33));
    Tank_t.setPosition(390, 70);

    Texture boom;
    boom.loadFromFile("Sprite_tanks.png");

    Sprite Boom;
    Boom.setTexture(boom);
    Boom.setTextureRect(IntRect(0, 100, 70, 70));

    Texture boom_t;
    boom_t.loadFromFile("Sprite_tanks.png");

    Sprite Boom_t;
    Boom_t.setTexture(boom_t);
    Boom_t.setTextureRect(IntRect(0, 100, 70, 70));
     

    CircleShape bull(3);
    bull.setFillColor(Color::Red);

    CircleShape bull_Two(3);
    bull_Two.setFillColor(Color::Blue);

    Clock clock;

    int side = 1;
    int constSide = 0;
    int side_t = 1;
    int constSide_t = 0;
    int bulletRun = 1;
    int bulletRun_Two = 0;

    int xOne, yOne, xTwo, yTwo;
    int xb_One1, yb_One1, xb_Two1, yb_Two1;

    int width = 19;
    int height = 30;
    int width_t = 17;
    int height_t = 33;
    
    float anim = 0;
    float anim_t = 0;
    int boomR = 0;
    int boomR_t = 0;

    int live_One = 2;
    int live_Two = 2;
     

    int map[16][16] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,0},
        {0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0},
        {0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,0,0,1,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0},
        {0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
        {0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    while (window.isOpen() && live_One !=0 && live_Two!=0)
    {
        setlocale(LC_ALL, "Russian");

        xOne = Tank_o.getPosition().x;
        yOne = Tank_o.getPosition().y;
        xTwo = Tank_t.getPosition().x;
        yTwo = Tank_t.getPosition().y;


        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            Tank_o.setTextureRect(IntRect(38, 0, height, width));
            Tank_o.move(map[yOne / 30][xOne / 30] * map[(yOne + width) / 30][xOne / 30] * -0.1 * time, 0);
            side = 4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            Tank_o.setTextureRect(IntRect(68, 0, height, width));
            Tank_o.move(map[yOne/30][(xOne+height)/30]*map[(yOne+width)/30][(xOne+height)/30]*0.1 * time, 0);
            side = 2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up)) {
            Tank_o.setTextureRect(IntRect(0, 0, width, height));
            Tank_o.move(0, map[yOne / 30][xOne / 30] * map[yOne / 30][(xOne + width) / 30] * -0.1 * time);
            side = 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            Tank_o.setTextureRect(IntRect(19, 0, width, height));
            Tank_o.move(0, map[(yOne+height) / 30][xOne / 30] * map[(yOne + height) / 30][(xOne + width) / 30] * 0.1 * time);
            side = 3;
        }



        if (Keyboard::isKeyPressed(Keyboard::A)) {
            Tank_t.setTextureRect(IntRect(34, 40, height_t, width_t));
            Tank_t.move(map[yTwo / 30][xTwo / 30] * map[(yTwo + width_t) / 30][xTwo / 30] * -0.1 * time, 0);
            side_t = 4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::D)) {
            Tank_t.setTextureRect(IntRect(67, 40, height_t, width_t));
            Tank_t.move(map[yTwo / 30][(xTwo + height_t) / 30] * map[(yTwo + width_t) / 30][(xTwo + height_t) / 30] * 0.1 * time, 0);
            side_t = 2;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W)) {
            Tank_t.setTextureRect(IntRect(0, 40, width_t, height_t));
            Tank_t.move(0, map[yTwo / 30][xTwo / 30] * map[yTwo / 30][(xTwo + width_t) / 30] * -0.1 * time);
            side_t = 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            Tank_t.setTextureRect(IntRect(17, 40, width_t, height_t));
            Tank_t.move(0, map[(yTwo + height_t) / 30][xTwo / 30] * map[(yTwo + height_t) / 30][(xTwo + width_t) / 30] * 0.1 * time);
            side_t = 3;
        }

         


        if (Keyboard::isKeyPressed(Keyboard::RControl) && bulletRun==0) {
            if (side == 1) {
                bull.setPosition(xOne+ width/2, yOne); 
            }
            else if (side == 2) {
                bull.setPosition(xOne + height, yOne + width / 2);
            }
            else if (side == 3) {
                bull.setPosition(xOne + width / 2, yOne + height / 2);
            }
            else {
                bull.setPosition(xOne, yOne + width / 2);
            }
            bulletRun = 1;
            constSide = side;
        }
        if (Keyboard::isKeyPressed(Keyboard::E) && bulletRun_Two==0) {
            if (side_t == 1) {
                bull_Two.setPosition(xTwo + width_t / 2, yTwo);
            }
            else if (side_t == 2) {
                bull_Two.setPosition(xTwo + height_t, yTwo + width_t / 2);
            }
            else if (side_t == 3) {
                bull_Two.setPosition(xTwo + width_t / 2, yTwo + height_t / 2);
            }
            else {
                bull_Two.setPosition(xTwo, yTwo + width_t / 2);
            }
            constSide_t = side_t;
            bulletRun_Two = 1;
        }


        xb_One1 = bull.getPosition().x;
        yb_One1 = bull.getPosition().y;
        xb_Two1 = bull_Two.getPosition().x;
        yb_Two1 = bull_Two.getPosition().y;
        

        if ((bulletRun == 1) && (map[yb_One1/ 30][xb_One1 / 30] == 0)) {
            bulletRun = 0;
        }
        else if ((side_t == 1 || side_t == 3) && (xTwo + width_t) >= xb_One1 && xb_One1 >= xTwo && (yTwo + height_t) >= yb_One1 && yb_One1 >= yTwo) {
            boomR = 1;
            Boom.setPosition(xTwo,yTwo);
            bull.setPosition(0, 0);
            bulletRun = 0;
            live_Two-=1;
        }
        else if ((side_t == 2 || side_t == 4) && (xTwo + height_t) >= xb_One1 && xb_One1 >= xTwo && (yTwo + width_t) >= yb_One1 && yb_One1 >= yTwo) {
            boomR = 1;
            Boom.setPosition(xTwo, yTwo);
            bull.setPosition(0, 0);
            bulletRun = 0;
            live_Two -= 1;
        }
        else {
            if (constSide == 1) {
                bull.move(0, -0.1 * time);
            }
            else if (constSide == 2) {
                bull.move(0.1 * time, 0);
            }
            else if (constSide == 3) {
                bull.move(0, 0.1 * time);
            }
            else {
                bull.move(-0.1 * time, 0);
            }
        }

            
        if ((bulletRun_Two == 1) && (map[yb_Two1 / 30][xb_Two1 / 30] == 0)) {
            bulletRun_Two = 0;
        }
        else if ((side == 1 || side == 3) && (xOne + width) >= xb_Two1 && xb_Two1 >= xOne && (yOne + height) >= yb_Two1 && yb_Two1 >= yOne) {
            boomR_t = 1;
            Boom.setPosition(xOne, yOne);
            bull_Two.setPosition(0, 0);
            bulletRun_Two = 0;
            live_One -= 1;
        }
        else if ((side == 2 || side == 4) && (xOne + height) >= xb_Two1 && xb_Two1 >= xOne && (yOne + width) >= yb_Two1 && yb_Two1 >= yOne) {
            boomR_t = 1;
            Boom.setPosition(xOne, yOne);
            bull_Two.setPosition(0, 0);
            bulletRun_Two = 0;
            live_One -= 1;
        }
        else {
            if (constSide_t == 1) {
                bull_Two.move(0, -0.1 * time);
            }
            else if (constSide_t == 2) {
                bull_Two.move(0.1 * time, 0);
            }
            else if (constSide_t == 3) {
                bull_Two.move(0, 0.1 * time);
            }
            else {
                bull_Two.move(-0.1 * time, 0);
            }
        }


        if (boomR == 1) {
            anim += 0.01;
            if (anim < 7) {
                Boom.setTextureRect(IntRect(70 * int(anim), 100, 70, 70));
                Boom.setPosition(xTwo, yTwo);
            }
            else {
                boomR = 0;
                anim = 0;
                Tank_t.setPosition(390, 70);
            }
        }

        if (boomR_t == 1) {
            anim_t += 0.01;
            if (anim_t < 7) {
                Boom_t.setTextureRect(IntRect(70 * int(anim_t), 100, 70, 70));
                Boom_t.setPosition(xOne, yOne);
            }
            else {
                boomR_t = 0;
                anim_t = 0;
                Tank_o.setPosition(70, 390);
            }
        }
            
        
        window.clear();
        window.draw(Polygon);
        if (bulletRun == 1) {
            window.draw(bull);
        }
        if (bulletRun_Two == 1) {
            window.draw(bull_Two);
        }
        window.draw(Tank_o);
        window.draw(Tank_t);
        if (boomR == 1) {
            window.draw(Boom);
        }
        if (boomR_t == 1) {
            window.draw(Boom_t);
        }


        window.display();
        
    }
    text.setPosition(100, 100);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(Polygon);
        if (live_One == 0) {
            text.setString("win Blue");
            window.draw(text);
        }
        else if (live_Two == 0) {
            text.setString("win Green");
            window.draw(text);
        }
        window.display();
    }
    return 0;
}