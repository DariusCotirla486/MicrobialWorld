#include "tableModel.h"

tableModel::tableModel(QObject* parent) : QAbstractTableModel(parent)
{}

void tableModel::setData(vector<Bacterium> b)
{
	beginResetModel();
	this->bacteria = b;
	endResetModel();
}

int tableModel::rowCount(const QModelIndex& parent) const
{
	return bacteria.size();
}

int tableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant tableModel::data(const QModelIndex& index, int role) const
{
	if (role != Qt::DisplayRole)
		return {};

	int row = index.row();
	int col = index.column();
	Bacterium bacterium = bacteria[row];

	switch (col) {
	case 0: return QString::fromStdString(bacterium.name);
	case 1: return QString::fromStdString(bacterium.species);
	case 2: return QString::fromStdString(to_string(bacterium.size));
	case 3: return QString::fromStdString(bacterium.causes);
	default:
		break;
	}
}
