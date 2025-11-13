#include "App.h"

#include <optional>

#include <SFML/Graphics/Color.hpp>

App::App()
: window(sf::VideoMode({1920u, 1080u}), "CMake SFML Project")
, grid(40, 30)
, gridView(grid)
{
    window.setFramerateLimit(144);

    gridView.setCellSize(25.0f);
    gridView.setOrigin({50.0f, 50.0f});

    for (std::size_t y = 0; y < grid.height(); ++y)
    {
        for (std::size_t x = 0; x < grid.width(); ++x)
        {
            grid.set(x, y, (x + y) % 2 == 0);
        }
    }
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
    window.draw(gridView);
    window.display();
}
