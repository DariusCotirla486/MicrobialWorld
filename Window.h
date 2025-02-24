#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Window.h"
#include "Service.h"
#include "tableModel.h"
#include <qsortfilterproxymodel.h>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget* parent, Service* service, Biologist* biologist);
    ~Window();
    void showOnlySpecies();
    void handleSpecies();
    void populateComboBox();
    void handleAdd();
    void handleAddDisease();
    void handleDiseaseShow();
    void handleView();

private:
    Ui::WindowClass ui;
    Service* service;
    Biologist* biologist;
    tableModel* model;
};
