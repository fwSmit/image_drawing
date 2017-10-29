#include "Project_imageDrawing.h"
#include <assert.h>

Project_imageDrawing::Project_imageDrawing(sf::RenderWindow& _window) : Project(_window){
    file_name = "rabbit.jpg";
    assert(img.loadFromFile(file_name));
	shape.setRadius(radius);
    shape.setOrigin(shape.getRadius(),shape.getRadius());
    //sf::RectangleShape shape(sf::Vector2f (size, size));
    //shape.setOrigin(0.5 * shape.getSize().x, 0.5 * shape.getSize().y * 0.5);
    //vector<sf::RectangleShape> circles;
}

int Project_imageDrawing::randInt(int min, int max){
	return rand() % max + min;
}


Project_imageDrawing::~Project_imageDrawing(){}

void Project_imageDrawing::loop(){
		for(int i = 0; i < 100; i ++) {
            sf::Vector2i pos;
            //pos.x = size* randInt(0, window.getSize().x/size);
            //pos.y = size* randInt(0, window.getSize().y/size);
            //sf::Vector2i pos = sf::Mouse::getPosition(window);
            //cout << pos.x << " " << pos.y << endl;
            pos.x = randInt(0, window.getSize().x);
            pos.y = randInt(0, window.getSize().y);
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
}

