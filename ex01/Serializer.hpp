#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "Data.hpp"
# include <iostream>

class Serializer
{
  private:
	Serializer(void);
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
	~Serializer(void);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif