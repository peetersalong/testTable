#ifndef TRACKSORTFILTERPROXYMODEL_H
#define TRACKSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class TrackSortFilterProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT
public:
  Q_INVOKABLE void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

public:
  TrackSortFilterProxyModel(QObject* parent = nullptr);
};

#endif // TRACKSORTFILTERPROXYMODEL_H
