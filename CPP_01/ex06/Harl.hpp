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
	int logLevel;
	void	getLevel(std::string level);
	

	public:
	void complain( std::string level );


};


#endif