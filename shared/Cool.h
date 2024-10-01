#ifndef COOL_H
#define COOL_H

#include <string>

class SuperClass
{
public:
	SuperClass() = default;
	virtual ~SuperClass() = default;

	SuperClass(const SuperClass&) = default;
	SuperClass& operator=(const SuperClass&) = default;

	SuperClass(SuperClass&&) = default;
	SuperClass& operator=(SuperClass&&) = default;

	std::string test() const { return "test"; }
};

#endif // COOL_H