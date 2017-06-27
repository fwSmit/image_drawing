#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int randInt(int min, int max)
{
    return rand() % max + min;
}


int main()
{
    int i = 0;
    int rad = 7;
    int size = 50;
    int decrement = 1;

    const string file_name = "rabbit.jpg";
    sf::Image img;
    if(!img.loadFromFile("images/" + file_name)){
        return EXIT_FAILURE;
    }

    sf::RenderWindow window(sf::VideoMode(img.getSize().x, img.getSize().y), "SFML works!");
    window.setVerticalSyncEnabled(1);

    //sf::CircleShape shape(rad);
    //vector<sf::CircleShape> circles;
    //shape.setOrigin(shape.getRadius(),shape.getRadius());
    //shape.setFillColor(sf::Color::Green);
    //cout << img.getSize().x << " " << img.getSize().y << endl;


    sf::RectangleShape shape(sf::Vector2f (size, size));
    shape.setOrigin(0.5 * shape.getSize().x, 0.5 * shape.getSize().y * 0.5);
    vector<sf::RectangleShape> circles;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if(i > 10 && rad > 1 && size > decrement) {
            i = 0;
            cout << "radius change" << endl;
            //rad -= 1;
            size -= decrement;
            cout << size << endl;
            shape.setSize(sf::Vector2f(size, size));
            //shape.setRadius(rad);
        }
        for(int i = 0; i < 100; i ++) {
            sf::Vector2i pos;
            pos.x = size* randInt(0, window.getSize().x/size);
            pos.y = size* randInt(0, window.getSize().y/size);
            //sf::Vector2i pos = sf::Mouse::getPosition(window);
            //cout << pos.x << " " << pos.y << endl;
            if(pos.x >= 0 && pos.x < img.getSize().x && pos.y >= 0 && pos.y < img.getSize().y) {
                sf::Color currColor = img.getPixel(pos.x, pos.y);
                currColor.a = 100;
                currColor.r = currColor.r;
                currColor.g = currColor.g;
                currColor.b = currColor.b;
                shape.setFillColor(currColor);
            }else{
                shape.setFillColor(sf::Color::Transparent);
            }
            //shape.left = pos.x + 0.5 * shape.width;
            //shape.top = pos.y + 0.5 * shape.height;

            shape.setPosition(sf::Vector2f(pos));
            circles.push_back(shape);
        }

        for(auto& i : circles) {
            window.draw(i);
        }
        //window.draw(shape);
        window.display();
        i++;
        //dcout << "frame " << i++ << endl;
    }

    return 0;
}
