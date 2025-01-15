#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>


class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	~Brain();
	Brain& operator=(const Brain &A);
	Brain (const Brain &A);

	const std::string getIdea(int i) const;
	void setIdea(std::string idea);
};

#endif