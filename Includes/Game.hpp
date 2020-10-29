#ifndef Game_HPP
# define Game_HPP

#include <cstdint>
#include <list>

class Game
{
	private:
		int8_t					_hp;
		int32_t					_speed;
		int8_t					tab[20][20];
		std::list<int16_t>		pos;
		int8_t					dir;
		int8_t					mapSizeX;
		int8_t					mapSizeY;
		int16_t					applepos;
		/* Private Data */
	protected:
		/* Protected Data */
	public:
		void					setApplePos(void);
		void					removeSnake(int16_t i);
		void        			placeSnake(int16_t i);
		void					drawMap();
		void					Snake();
		/* Get Attribute Function */
		int8_t					getSpeed() const {return (this->_speed);};
		int8_t					getHp() const {return (this->_hp);};
		/* Constructor / Destructor */
		Game(int8_t Width, int8_t Height);
		Game(Game const & Class);
		Game & operator=(Game const & Class);
		~Game();
};

#endif
