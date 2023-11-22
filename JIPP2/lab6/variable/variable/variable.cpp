//
// Created by filip on 20.11.2023 
//

#include "Variable.h"

int Variable::getInt() const
{
	return *reinterpret_cast<int*>(var);
}

double Variable::getDouble() const
{
	return *reinterpret_cast<double*>(var);
}
char Variable::getChar() const
{
	return *reinterpret_cast<char*>(var);
}
short Variable::getShort() const
{
	return *reinterpret_cast<short*>(var);
}
unsigned Variable::getUnsigned() const
{
	return *reinterpret_cast<unsigned*>(var);
}

void Variable::setInt(int x)
{
	var = reinterpret_cast<double*>(new int(x));
}

void Variable::setDouble(double x)
{
	var = reinterpret_cast<double*>(new double(x));
}
void Variable::setChar(char x)
{
	var = reinterpret_cast<double*>(new char(x));
}
void Variable::setShort(short x)
{
	var = reinterpret_cast<double*>(new short(x));
}

void Variable::setUnsigned(unsigned x)
{
	var = reinterpret_cast<double*>(new unsigned(x));
}
