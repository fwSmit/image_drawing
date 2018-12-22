#include <SFML/Graphics.hpp>
#include "Project_imageDrawing.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	Project_imageDrawing pr(window);
	    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Update the window
	pr.loop();
        window.display();
    }
    return 0;
}
