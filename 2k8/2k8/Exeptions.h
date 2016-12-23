#pragma once
#include <iostream>

using namespace std;

class Exeption
{
protected:
	int errorCode;

	Exeption();

	int getErrorCode();
};

class Empty : public Exeption
{
public:
	Empty();
	void printMessage();
};
class NoGreater : public Exeption
{
public:
	NoGreater();
	void printMessage();
};
class Ne4et : public Exeption
{
public:
	Ne4et();
	void printMessage();
};
class NoPlus : public Exeption
{
public:
	NoPlus();
	void printMessage();
};
class Limited100 : public Exeption
{
public:
	Limited100();
	void printMessage();
};
