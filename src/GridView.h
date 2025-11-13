#ifndef GRID_VIEW_H
#define GRID_VIEW_H

#include "Grid.h"

#include <SFML/Graphics.hpp>

class GridView : public sf::Drawable
{
public:
    explicit GridView(const Grid& grid);

    void setCellSize(float size);
    float cellSize() const noexcept;

    void setOrigin(const sf::Vector2f& origin);
    const sf::Vector2f& origin() const noexcept;

    sf::Vector2f cellToScreen(std::size_t x, std::size_t y) const;
    sf::Vector2f cellDimensions() const noexcept;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    const Grid& m_grid;
    float m_cellSize;
    sf::Vector2f m_origin;
    sf::RectangleShape m_cellShapePrototype;
};

#endif // GRID_VIEW_H
