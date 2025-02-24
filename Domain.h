#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;


class Biologist
{
public:
	string name;
	string speciesStudied;
	Biologist(string name, string species) : name(name), speciesStudied(species) {};
};


class Bacterium {
public:
	string name;
	string species;
	string causes;
	int size;
	Bacterium(string n, string s, int sz, string c) : name(n), species(s), causes(c), size(sz) {};
};

