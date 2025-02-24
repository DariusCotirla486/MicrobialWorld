#include "GUI.h"

void GUI::load_windows()
{
	vector<Biologist>& biologists = service->getBiologistsService();
	for (int i = 0; i < biologists.size(); i++) {
		auto window = new Window(nullptr, this->service, &biologists[i]);
		window->setWindowTitle(QString::fromStdString(biologists[i].name));
		windows.push_back(window);
	}
}

GUI::GUI()
{
	this->service = new Service();
	load_windows();
}

void GUI::display_windows()
{
	for (auto window : windows) {
		window->show();
	}
}
