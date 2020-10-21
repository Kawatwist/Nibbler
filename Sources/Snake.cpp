#include "../Includes/Game.hpp"
#include <iostream>
#include <unistd.h>

void        Game::drawMap(void)
{
    int8_t posHead = this->pos.front();
    for (int i = 0; i < this->mapSizeX + 1; i++)
    {
        for (int j = 0; j < this->mapSizeY + 1; j++)
        {
            if (i == 0 || i == this->mapSizeX || j == 0 || j == this->mapSizeY)
                std::cout << '*';
            else
            {
                if ((posHead & 0xFF) == i && ((posHead & 0xFF00) >> 8) == j)
                    std::cout << "\x1b[35m";
                std::cout << this->tab[i][j];
                if ((posHead & 0xFF) == i && ((posHead & 0xFF00) >> 8) == j)
                    std::cout << "\x1b[0m";
            }
            if (j == this->mapSizeY)
                std::cout << std::endl;
        }
    }
}

void        Game::removeSnake(int16_t i)
{
    this->tab[(i & 0xFF00) >> 8][i & 0xFF] = ' ';
}

void        Game::placeSnake(int16_t i)
{
    this->tab[(i & 0xFF00) >> 8][i & 0xFF] = 'S';
}

/*
1 Right
2 Bot
4 Top
8 Left
*/
void        Game::Snake(void)
{
    while (1)
    {
        int16_t last = this->pos.front();
        this->dir = 1 << ((rand() % 3) + 1);
        switch (this->dir & 0b1111)
        {
            case 1: /* Right */
                if ((((last & 0xFF)) - 1) >= this->mapSizeX)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                this->pos.push_front(last - 1);
                placeSnake(last - 1);
                break;
            case 2: /* Bot */
                if ((((last & 0xFF00) >> 8) + 1) >= this->mapSizeY)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                this->pos.push_front(last + (1 << 8));
                placeSnake(last + (1 << 8));
                break;
            case 4: /* Top */
                if ((((last & 0xFF00) >> 8) - 1) <= 0)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                this->pos.push_front(last - (1 << 8));
                placeSnake(last - (1 << 8));
                break;
            default: /* Left */
                if ((((last & 0xFF)) + 1) <= 0)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                this->pos.push_front(last + 1);
                placeSnake(last + 1);
                break;
        }
        last = this->pos.back();
        removeSnake(last);
        this->pos.pop_back();
        drawMap();
        usleep(this->_speed);
        if (this->_speed > 5000)
            this->_speed -= 1000;
    }
}