#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>

class App
{
public:
    App();

    void run();

private:
    void processEvents();
    void render();

    sf::RenderWindow window;
};

#endif // APP_H
