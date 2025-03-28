#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

class Serializer
{
  private:
	Serializer(void);
	Serializer(const Serializer *copy);
	Serializer &operator=(const Serializer &copy);
	~Serializer(void);

  public:
	static void uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif