#include "Slav.h"
#include <fstream>
#include <stdlib.h>
#include <sstream> //to_string
#include <iterator>   //istream_iterator
#include <algorithm>   //istream_iterator

using namespace std;
/*
template<typename T>						//to_string
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}*/

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}

gender Slav::specify()
{
	if(_name[_name.length()-1]!='a')return m;
	else return f;

}