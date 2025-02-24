#include "Service.h"

void Service::addBacteria(string name, string species, int size, string diseases)
{
	vector<Bacterium>& bacteria = repo->getBacteria();
	for (auto bacterium : bacteria) {
		if (bacterium.species == species && bacterium.name == name)
			throw exception("Invalid name or species!");
	}
	this->repo->addBacteria(Bacterium(name, species, size, diseases));
}