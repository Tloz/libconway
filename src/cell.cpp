#include "../inc/cell.h"

#include <iostream>

Cell::Cell() : m_value(0)
{
    m_evolve = false;
    m_neighbors = 0;
}

Cell::Cell(int value) : m_value(value)
{
    m_evolve = false;
    m_neighbors = 0;
}

Cell::~Cell()
{

}

bool Cell::alive()
{
    return m_value != 0;
}

void Cell::kill()
{
    m_value = 0;
}

void Cell::born()
{
    m_value = 1;
}

void Cell::change()
{
    if(m_value == 0)
        m_value = 1;
    else
        m_value = 0;
}

std::string Cell::to_string() const
{
    if(m_value == 0)
        return " ";
    else
        return "#";
}

void Cell::neighbors(unsigned int value)
{
    m_neighbors = value;
}
unsigned int Cell::neighbors()
{
    return m_neighbors;
}

void Cell::computeEvolution()
{
    if(((!alive()) && (neighbors() == 3)) || ((alive()) && ((neighbors() == 2) || (neighbors() == 3))))
        m_evolve = true;
    else if(alive())
        m_evolve = true;
}

void Cell::evolve()
{
    if(m_evolve)
    {
        this->change();
        m_evolve = false;
        m_neighbors = 0;
    }
}

std::ostream& operator<<(std::ostream &flux, Cell const& c)
{
    flux << c.to_string();
    return flux;
}
