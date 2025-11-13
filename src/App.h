#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>

#include "Grid.h"
#include "GridView.h"

class App
{
public:
    App();

    void run();

private:
    void processEvents();
    void render();

    sf::RenderWindow window;
    Grid grid;
    GridView gridView;
};

#endif // APP_H
