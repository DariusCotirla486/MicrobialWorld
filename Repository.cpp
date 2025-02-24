#include "Repository.h"

void Repository::read_bacteria()
{
	ifstream fin("bacteria.txt");
	string line;
	while (getline(fin, line)) {
		istringstream iss(line);
		string name, species, size_string, diseases;
		getline(iss, name, ',');
		getline(iss, species, ',');
		getline(iss, size_string, ',');
		getline(iss, diseases, ',');
		int size = stoi(size_string);
		bacteria.push_back(Bacterium(name, species, size, diseases));
	}
	fin.close();
}

void Repository::read_biologists()
{
	ifstream fin("biologists.txt");
	string line;
	while (getline(fin, line)) {
		istringstream iss(line);
		string name, species;
		getline(iss, name, ',');
		getline(iss, species, ',');
		biologists.push_back(Biologist(name, species));
	}
	fin.close();
}

void Repository::write_bacteria()
{
	ofstream file("bacteria.txt", std::ios::trunc);
	for (auto bacterium : bacteria) {
		file << bacterium.name << "," << bacterium.species << "," << to_string(bacterium.size) << "," << bacterium.causes << "\n";
	}
	file.close();
}

void Repository::read()
{
	this->read_bacteria();
	this->read_biologists();
}
