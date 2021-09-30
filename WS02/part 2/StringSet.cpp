#define _CRT_SECURE_NO_WARNINGS
#include "StringSet.h"
#include <iostream>
#include <fstream>
namespace sdds
{
	StringSet::StringSet()
	{
		elements = nullptr;
		numOfStrings = 0;
	}
	StringSet::StringSet(StringSet& obj)
	{
		if (&obj != this)
		{
			delete[] elements;
			elements = new std::string[obj.numOfStrings];
			numOfStrings = obj.numOfStrings;
			for (size_t i = 0; i < numOfStrings; i++)
			{
				elements[i] = obj.elements[i];
			}
		}
	}

	StringSet::StringSet(StringSet&& obj) noexcept
	{
		if (&obj != this)
		{
			numOfStrings = obj.numOfStrings;
			elements = obj.elements;
			obj.elements = nullptr;
			obj.numOfStrings = 0;
		}
	}
	
	StringSet::~StringSet()
	{
		delete[] elements;
		elements = nullptr;
	}
	StringSet::StringSet(char* fileName)
	{
		std::ifstream in(fileName);
		if (in.is_open() == false)
		{
			std::cout << "Cannot open file [" << fileName << "]\n";
		}
		else
		{
			std::string temp;
			while (std::getline(in,temp,' '))
			{
				numOfStrings++;
			}
			elements = new std::string[numOfStrings];
			in.clear();
			in.seekg(0);
			for (size_t i = 0; i < numOfStrings; i++)
			{
				std::getline(in, elements[i], ' ');
			}
		}
		in.close();
	}
	size_t StringSet::size()
	{
		return numOfStrings;
	}
	std::string StringSet::operator[](size_t index)
	{
		std::string temp;
		if (index < numOfStrings && index >= 0 )
		{
			temp = elements[index];
		}
		else
		{
			temp = "";
		}
		return temp;
	}
	StringSet& StringSet::operator=(StringSet& obj)
	{
		if (&obj != this)
		{
			delete[] elements;
			elements = new std::string[obj.numOfStrings];
			numOfStrings = obj.numOfStrings;
			for (size_t i = 0; i < numOfStrings; i++)
			{
				elements[i] = obj.elements[i];
			}
		}
		return *this;
	}
	StringSet& StringSet::operator=(StringSet&& obj) noexcept
	{
		if (&obj != this)
		{
			numOfStrings = obj.numOfStrings;
			elements = obj.elements;
			obj.elements = nullptr;
			obj.numOfStrings = 0;
		}
		return *this;
	}
}