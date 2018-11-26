#include "trackmodel.h"

#include <QList>
#include <QDebug>

TrackModel::TrackModel(QObject* parent)
  : QAbstractTableModel(parent)
{
}

int TrackModel::rowCount(const QModelIndex& /*parent*/) const
{
  return tracks.size();
}

int TrackModel::columnCount(const QModelIndex& /*parent*/) const
{
  return ColumnsCount - Qt::UserRole;
}

QVariant TrackModel::data(const QModelIndex& index, int role) const
{
  if(!index.isValid())
    return QVariant();

  if(index.row() >= tracks.size())
    return QVariant();

  Track track = tracks.at(index.row());
  switch (role)
  {
    case DataA:
      return QVariant(track.dataA);
    case DataB:
      return QVariant(track.dataB);
    default:
      return QVariant();
  }
  return QVariant();
}

QHash<int, QByteArray> TrackModel::roleNames() const
{
  QHash<int, QByteArray> roles;
  roles[DataA] = "DataARole";
  roles[DataB] = "DataBRole";
  return roles;
}

void TrackModel::appendTrack(const Track& track)
{

  beginInsertRows(QModelIndex(), tracks.size(), tracks.size());
  tracks.append(track);
  endInsertRows();
}
