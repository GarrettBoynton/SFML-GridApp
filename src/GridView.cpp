#include "GridView.h"

#include <SFML/Graphics/RenderTarget.hpp>

GridView::GridView(const Grid& grid)
    : m_grid(grid)
    , m_cellSize(10.0f)
    , m_origin(0.0f, 0.0f)
    , m_cellShapePrototype({m_cellSize, m_cellSize})
{
    m_cellShapePrototype.setOutlineThickness(1.0f);
    m_cellShapePrototype.setOutlineColor(sf::Color(50, 50, 50));
}

void GridView::setCellSize(float size)
{
    m_cellSize = size;
    m_cellShapePrototype.setSize({m_cellSize, m_cellSize});
}

float GridView::cellSize() const noexcept
{
    return m_cellSize;
}

void GridView::setOrigin(const sf::Vector2f& origin)
{
    m_origin = origin;
}

const sf::Vector2f& GridView::origin() const noexcept
{
    return m_origin;
}

sf::Vector2f GridView::cellToScreen(std::size_t x, std::size_t y) const
{
    return {m_origin.x + static_cast<float>(x) * m_cellSize,
            m_origin.y + static_cast<float>(y) * m_cellSize};
}

sf::Vector2f GridView::cellDimensions() const noexcept
{
    return {m_cellSize, m_cellSize};
}

void GridView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape cellShape = m_cellShapePrototype;

    for (std::size_t y = 0; y < m_grid.height(); ++y)
    {
        for (std::size_t x = 0; x < m_grid.width(); ++x)
        {
            cellShape.setPosition(cellToScreen(x, y));
            if (m_grid.get(x, y))
            {
                cellShape.setFillColor(sf::Color::White);
            }
            else
            {
                cellShape.setFillColor(sf::Color(30, 30, 30));
            }
            target.draw(cellShape, states);
        }
    }
}
