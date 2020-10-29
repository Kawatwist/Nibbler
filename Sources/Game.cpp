#include "../Includes/Game.hpp"

/* Constructor */

Game::Game(int8_t Width, int8_t Height)
{
	this->mapSizeX = Width;
	this->mapSizeY = Height;
	this->pos.push_front((this->mapSizeX << 7) + (this->mapSizeY >> 1) + 3);
	this->pos.push_front((this->mapSizeX << 7) + (this->mapSizeY >> 1) + 2);
	this->pos.push_front((this->mapSizeX << 7) + (this->mapSizeY >> 1) + 1);
	this->pos.push_front((this->mapSizeX << 7) + (this->mapSizeY >> 1));
	for (int i = 0; i < this->mapSizeX; i++)
		for (int j = 0; j < this->mapSizeY; j++)
			this->tab[i][j] = ' ';
	this->tab[this->mapSizeX / 2][this->mapSizeY / 2] = 'S';
	this->tab[this->mapSizeX / 2][this->mapSizeY / 2 + 1] = 'S';
	this->tab[this->mapSizeX / 2][this->mapSizeY / 2 + 2] = 'S';
	this->tab[this->mapSizeX / 2][this->mapSizeY / 2 + 3] = 'S';
	this->dir = 4;
	this->_speed = 100000;
}

Game::~Game()
{
}

Game::Game(Game const & Class)
{
	*this = Class;
}

Game & Game::operator=(Game const & Class)
{
	return (*this);
}
etc/hosts.allow