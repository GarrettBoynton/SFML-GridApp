#include "App.h"

#include <optional>

App::App()
: window(sf::VideoMode({1920u, 1080u}), "CMake SFML Project")
{
    window.setFramerateLimit(144);
}

void App::run()
{
    while (window.isOpen())
    {
        processEvents();
        render();
    }
}

void App::processEvents()
{
    for (std::optional<sf::Event> event; (event = window.pollEvent());)
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}

void App::render()
{
    window.clear();
    window.display();
}
