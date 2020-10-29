#include "../Includes/Game.hpp"
#include <iostream>
#include <unistd.h>

void        Game::drawMap(void)
{
    int16_t posHead = this->pos.front();
    for (int i = 0; i < this->mapSizeX + 1; i++)
    {
        for (int j = 0; j < this->mapSizeY + 1; j++)
        {
            if (i == 0 || i == this->mapSizeX || j == 0 || j == this->mapSizeY)
                std::cout << '*';
            else
            {
                if ((posHead & 0xFF) == j && ((posHead & 0xFF00) >> 8) == i)
                    std::cout << "\x1b[35m";
                std::cout << this->tab[i][j];
                if ((posHead & 0xFF) == j && ((posHead & 0xFF00) >> 8) == i)
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

void        Game::setApplePos()
{
    bool done = true;
    while (1)
    {
        done = true;
        this->applepos = (rand() % this->mapSizeX) + ((rand() % this->mapSizeY) << 8);
        for (auto a : this->pos)
        {
            if (a == this->applepos)
            {
                done = false;
                break;
            }
        }
        if (done == true)
            break;
    }
    this->tab[this->applepos & 0xFF][(this->applepos & 0xFF00) >> 8] = 'a';
}

void        Game::Snake(void)
{
    bool eat = false;
    this->setApplePos();
    while (1)
    {
        eat = false;
        int16_t last = this->pos.front();
        int16_t apple = this->applepos;
        this->dir = 1 << ((rand() % 3) + 1);
        switch (this->dir & 0b1111)
        {
            case 1: /* Right */
                if ((((last & 0xFF)) - 1) <= 0)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                else if ((((last & 0xFFFF)) - 1) == apple)
                    eat = true;
                this->pos.push_front(last - 1);
                placeSnake(last - 1);
                break;
            case 2: /* Bot */
                if ((((last & 0xFF00) >> 8) + 1) >= this->mapSizeY)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                else if ((((last & 0xFFFF)) + (1 << 8)) == apple)
                    eat = true;
                this->pos.push_front(last + (1 << 8));
                placeSnake(last + (1 << 8));
                break;
            case 4: /* Top */
                if ((((last & 0xFF00) >> 8) - 1) <= 0)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                else if ((((last & 0xFFFF)) - (1 << 8)) == apple)
                    eat = true;
                this->pos.push_front(last - (1 << 8));
                placeSnake(last - (1 << 8));
                break;
            default: /* Left */
                if ((((last & 0xFF)) + 1) >= this->mapSizeX)
                {
                    std::cout << "End" << std::endl;
                    return ;
                }
                else if ((((last & 0xFFFF)) + (1)) == apple)
                    eat = true;
                this->pos.push_front(last + 1);
                placeSnake(last + 1);
                break;
        }
        if (eat == false)
        {
            last = this->pos.back();
            removeSnake(last);
        }
        else
            setApplePos();
        this->pos.pop_back();
        drawMap();
        usleep(this->_speed);
        if (this->_speed > 5000)
            this->_speed -= 1000;
    }
}