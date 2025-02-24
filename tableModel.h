#pragma once
#include <qabstractitemmodel.h>
#include "Service.h"
#include <algorithm>


class tableModel : public QAbstractTableModel
{
private:
	vector<Bacterium> bacteria;

public:

	explicit tableModel(QObject* parent = nullptr);
	void setData(vector<Bacterium> b);
	int rowCount(const QModelIndex& parent) const;
	int columnCount(const QModelIndex& parent) const;
	QVariant data(const QModelIndex& index, int role) const;
};