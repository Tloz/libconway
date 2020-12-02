#ifndef WORLD_H
#define WORLD_H

/***************************************************************************
*             World module for libConway
*
*   File    : world.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : December 2, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libconway
*   Purpose : Header for managing 2D array of cell in Conway's Game of life.
*             
*
***************************************************************************/

/**************************************************************************\
*                            METHODS YOU'LL FIND                           *
****************************************************************************


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/

// As we overload flux operator <<, we need to include iostream
#include <iostream>
#include <vector>


template<class TYPE>
    class World
    {
    private:
        size_t m_height, m_width;
        std::vector<TYPE> m_matrix;
    public:
        World(size_t height, size_t width) :
                m_height(height), m_width(width), m_matrix(m_height * m_width)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        World(size_t height, size_t width, TYPE init) :
                m_height(height), m_width(width), m_matrix(m_height * m_width, init)
        {
            if((m_height * m_width) == 0)
                throw std::logic_error("None of the dimension can be zero.");
        }

        // This function is used when you want to acces an element to replace it
        TYPE & operator()(size_t x, size_t y)
        {
            // As a size_t is always at least 0, we don't have to check if
            // the coordinates are below zero, just over dimensions
            if(x >= m_width)
                throw std::out_of_range("x has to be less than " + std::to_string(m_width) + " (current x = " + std::to_string(x) + ")");
            if(y >= m_height)
                throw std::out_of_range("y has to be less than " + std::to_string(m_width) + " (current y = " + std::to_string(y) + ")");
            return m_matrix[y * m_width + x];
        }

        TYPE operator()(size_t x, size_t y) const
        {
            // As a size_t is always at least 0, we don't have to check if
            // the coordinates are below zero, just over dimensions
            // if(x >= m_width)
            //     throw std::out_of_range("x has to be less than " + std::to_string(m_width) + " (current x = " + std::to_string(x) + ")");
            // if(y >= m_height)
            //     throw std::out_of_range("y has to be less than " + std::to_string(m_width) + " (current y = " + std::to_string(y) + ")");
            return m_matrix[y * m_width + x];
        }

        size_t height() const
        {
            return m_height;
        }

        size_t width() const
        {
            return m_width;
        }

        friend std::ostream & operator<<(std::ostream & out, const World & in)
        {
            for (unsigned int i = 0; i < in.height(); i++)
            {
                for (unsigned int j = 0; j < in.width(); j++)
                {
                    out << in(i, j) << ' ';
                }
                out << std::endl;
            }

            return out;
        }

        size_t cardinal() const
        {
            return m_width * m_height;
        }

        void computeNeighbors(size_t x, size_t y)
        {
            int neighbors = 0;
            for(int lat = -1; lat <= 1; ++lat)
            {
                int newX = x + lat;
                if((newX < 0) || (newX >= m_width)) // newX is Out of Bounds
                {
                    continue;
                }
                else
                {
                    for (int vert = -1; vert <= 1; ++vert)
                    {
                        int newY = y + vert;
                        if((newY < 0) || (newY >= m_height)) // newY is Out of Bounds
                        {
                            continue;
                        }
                        else // So here we are sure to be inside the 2DA
                        {
                            if((newX == x) && (newY == y)) // we don't want to count the given cell
                                continue;
                            if(this(newX, newY) != 0)
                                neighbors++;
                        }
                    }
                }
            }
            this(x, y).neighbors(neighbors);
        }

        void evolve()
        {
            for (int y = 0; y < m_height; ++y)
            {
                for (int x = 0; x < m_width; ++x)
                {
                    this(x, y).computeEvolution();
                }
            }

            for (int y = 0; y < m_height; ++y)
            {
                for (int x = 0; x < m_width; ++x)
                {
                    this(x, y).evolve();
                }
            }
        }
    };

#endif // WORLD_H /****************** END OF FILE - world.h *****************/

