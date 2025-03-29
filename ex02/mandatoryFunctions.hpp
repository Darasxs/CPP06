#ifndef MANDATORYFUNCTIONS_HPP
# define MANDATORYFUNCTIONS_HPP

# include "classA.hpp"
# include "classB.hpp"
# include "classC.hpp"
# include "Base.hpp"
# include <iostream>
# include <string>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif