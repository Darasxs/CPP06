#ifndef MANDATORYFUNCTIONS_HPP
# define MANDATORYFUNCTIONS_HPP

# include "A.hpp"
# include "B.hpp"
# include "Base.hpp"
# include "C.hpp"
# include <iostream>
# include <string>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif