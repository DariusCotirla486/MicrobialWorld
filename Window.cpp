#include "Window.h"
#include <qmessagebox.h>


Window::Window(QWidget* parent, Service* s, Biologist* b)
    : QMainWindow(parent), service(s), biologist(b)
{
    ui.setupUi(this);
    vector<Bacterium>& bacteria = service->getBacteriaService();
    model = new tableModel();
    model->setData(bacteria);
    ui.BacteriaTableView->setModel(model);
    populateComboBox();
    connect(ui.SpeciesComboBox, &QComboBox::currentIndexChanged, this, &Window::handleSpecies);
    connect(ui.pushButton, &QPushButton::clicked, this, &Window::handleAdd);
    connect(ui.BacteriaTableView, &QTableView::clicked, this, &Window::handleDiseaseShow);
    connect(ui.AddDiseaseButton, &QPushButton::clicked, this, &Window::handleAddDisease);
    connect(ui.ViewButton, &QPushButton::clicked, this, &Window::handleView);
}

void Window::populateComboBox()
{
    ui.SpeciesComboBox->clear();
    string allSpecies = biologist->speciesStudied;
    istringstream iss(allSpecies);
    string currentSpecies;
    ui.SpeciesComboBox->addItem(QString("All"));
    while (getline(iss, currentSpecies, ' ')) {
        ui.SpeciesComboBox->addItem(QString::fromStdString(currentSpecies));
    }
}

void Window::handleAdd()
{
    string name = ui.NameLineEdit->text().toStdString();
    string species = ui.SpeciesLineEdit->text().toStdString();
    int size = stoi(ui.SizeLineEdit->text().toStdString());
    string diseases = ui.DiseasesLineEdit->text().toStdString();
    try {
        service->addBacteria(name, species, size, diseases);
        vector<Bacterium>& bacteria = service->getBacteriaService();
        model->setData(bacteria);
    }
    catch (exception& e) {
        QMessageBox::information(this, "Error", "Another one with name or species found!");
    }
}

void Window::handleAddDisease()
{
    QString disease = ui.DiseaseAddedLineEdit->text();
    ui.DiseasesListView->addItem(disease);
}

void Window::handleDiseaseShow()
{
    ui.DiseasesListView->clear();
    QModelIndex index = ui.BacteriaTableView->currentIndex();
    Bacterium bacterium = service->getBacteriaService()[index.row()];
    string diseases = bacterium.causes;
    istringstream iss(diseases);
    string disease;
    while (getline(iss, disease, ' ')) {
        ui.DiseasesListView->addItem(QString::fromStdString(disease));
    }
}

void Window::showOnlySpecies()
{
    
}

void Window::handleView()
{
    Window* species_window = new Window(this, service, biologist);
    species_window->show();
    species_window->showOnlySpecies();
}

Window::~Window()
{}

void Window::handleSpecies()
{
    string species = ui.SpeciesComboBox->currentText().toStdString();
    vector<Bacterium>& bacteria = service->getBacteriaService();
    vector<Bacterium> bacteria_with_species;
    for (auto bacterium : bacteria) {
        if (bacterium.species == species)
            bacteria_with_species.push_back(bacterium);
    }
    if (species == "All") {
        model->setData(bacteria);
    }
    else 
        model->setData(bacteria_with_species);
}
