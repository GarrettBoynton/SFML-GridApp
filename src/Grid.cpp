#include "Grid.h"

#include <stdexcept>

Grid::Grid(std::size_t width, std::size_t height, bool initialValue)
    : m_width(width)
    , m_height(height)
    , m_cells(height, std::vector<bool>(width, initialValue))
{
}

std::size_t Grid::width() const noexcept
{
    return m_width;
}

std::size_t Grid::height() const noexcept
{
    return m_height;
}

bool Grid::get(std::size_t x, std::size_t y) const
{
    if (y >= m_height || x >= m_width)
    {
        throw std::out_of_range("Grid::get - index out of range");
    }
    return m_cells[y][x];
}

void Grid::set(std::size_t x, std::size_t y, bool value)
{
    if (y >= m_height || x >= m_width)
    {
        throw std::out_of_range("Grid::set - index out of range");
    }
    m_cells[y][x] = value;
}

const std::vector<bool>& Grid::operator[](std::size_t y) const
{
    if (y >= m_height)
    {
        throw std::out_of_range("Grid::operator[] const - index out of range");
    }
    return m_cells[y];
}

std::vector<bool>& Grid::operator[](std::size_t y)
{
    if (y >= m_height)
    {
        throw std::out_of_range("Grid::operator[] - index out of range");
    }
    return m_cells[y];
}
