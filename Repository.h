#pragma once
#include "Domain.h"


class Repository
{
private:
	void read_bacteria();
	void read_biologists();
	void write_bacteria();
	void read();

public:
	vector<Biologist> biologists;
	vector<Bacterium> bacteria;
	Repository() { read(); };
	vector<Biologist>& getBiologists() { return biologists; };
	vector<Bacterium>& getBacteria() { return bacteria; };
	void addBacteria(Bacterium bacterium) {
		bacteria.push_back(bacterium);
		write_bacteria();
	};
};

