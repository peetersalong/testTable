#include "tracksortfilterproxymodel.h"

#include <QDebug>

void TrackSortFilterProxyModel::sort(int column, Qt::SortOrder order)
{
  setSortRole(Qt::UserRole + column);  
  QSortFilterProxyModel::sort(column, order);
}

TrackSortFilterProxyModel::TrackSortFilterProxyModel(QObject* parent)
  : QSortFilterProxyModel(parent)
{

}

