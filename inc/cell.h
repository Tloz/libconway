#ifndef CELL_H
#define CELL_H

/***************************************************************************
*             Cell module for libConway
*
*   File    : cell.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : December 2, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libconway
*   Purpose : Header for managing cell objetcs in a Conway's Game of Life.
*             
*
***************************************************************************/

/**************************************************************************\
*                            METHODS YOU'LL FIND                           *
****************************************************************************
*
*   - Cell(): default ctor cuz C++ needs it
*   - Cell(int value): the only ctor you'll use, just give it an int value
*   that  will be stored in the cell. Zero is a dead cell, anything else is
*   a living cell.
*   - ~Cell(): dtor
*   - bool alive(): return false is the cell is dead, true otherwise.
*   - void kill(): kill the cell
*   - void born(): make the cell alive (or resurrect it)
*   - void change(): if cell is alive, will kill it, otherwise make it alive
*   - void neighbors(uint value): tell the cell how many neighbors it has.
*   - uint neighbors(): ask the cell how many neighbors it has.
*   - void computeEvolution(): tell the cell if it will have to evolve
*   - void evolve(): change the living state of the cell IF IT HAS TO
*   That mean you can call this method on any cell, even if it doesn't have
*   to change. As long as you've told the cell how many neighbors it has and
*   called computeEvolution(), you can call this function no matter what
*   - std::string to_string(): return # if the cell is alive, otherwise
*   return a string with juste a space char
*   - operator<<(): quick and easy way to show the cell
*
***************************************************************************/


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

// As we overload flux operator <<, we need to include iostream
#include <iostream>

class Cell
{
private:
    int m_value;
    bool m_evolve;
    unsigned int m_neighbors;

public:
    Cell();
    Cell(int value);
    ~Cell();

    bool alive();
    void kill();
    void born();
    void change();
    void neighbors(unsigned int value);
    unsigned int neighbors();
    void computeEvolution();
    void evolve();

    std::string to_string() const;
};

std::ostream& operator<<(std::ostream &flux, Cell const& c);

#endif // CELL_H /******************* END OF FILE - cell.h ******************/

