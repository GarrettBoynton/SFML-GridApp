#ifndef GRID_H
#define GRID_H

#include <cstddef>
#include <vector>

class Grid
{
public:
    Grid(std::size_t width, std::size_t height, bool initialValue = false);

    std::size_t width() const noexcept;
    std::size_t height() const noexcept;

    bool get(std::size_t x, std::size_t y) const;
    void set(std::size_t x, std::size_t y, bool value);

    const std::vector<bool>& operator[](std::size_t y) const;
    std::vector<bool>& operator[](std::size_t y);

private:
    std::size_t m_width;
    std::size_t m_height;
    std::vector<std::vector<bool>> m_cells;
};

#endif // GRID_H
