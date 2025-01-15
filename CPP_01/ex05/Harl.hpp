#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>


class Harl
{

	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	

	public:
	void complain( std::string level );

};
typedef void (Harl::*Harl_mem_func)(void);
struct Level_map
{
	const char* level;
	Harl_mem_func function;
};
#endif