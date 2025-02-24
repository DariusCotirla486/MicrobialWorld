#pragma once
#include "Repository.h"


class Service
{
public:
	Repository* repo;

	Service() {
		this->repo = new Repository();
	};

	vector<Biologist>& getBiologistsService() { return repo->getBiologists(); };
	vector<Bacterium>& getBacteriaService() { return repo->getBacteria(); };
	void addBacteria(string name, string species, int size, string diseases);
};

