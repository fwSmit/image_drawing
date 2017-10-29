#include <SFML/Graphics.hpp>
#include "Project_imageDrawing.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	Project_imageDrawing pr(window);
    return 0;
}
