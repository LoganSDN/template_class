#include "€.hpp"

€::€( void ) { std::cout<< "Default € constructor called " << std::endl; }

€::€( const € &€ ) { (*this) = €; }

€::~€( void ) { std::cout << "Deconstructor called" << std::endl; }

€ &€::operator=(const € &€) { return (*this); }