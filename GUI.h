#pragma once
#include "Service.h"
#include "Window.h"


class GUI
{
private:
	vector<Window*> windows;
	Service* service;
	void load_windows();

public:
	GUI();
	void display_windows();
};

