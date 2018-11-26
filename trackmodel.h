#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QTimer>

struct Track
{
  int dataA;
  int dataB;
};

class TrackModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  enum Role {
    DataA = Qt::UserRole,
    DataB,
    ColumnsCount // keep it last
  };

  TrackModel(QObject* parent = nullptr);

  int rowCount(const QModelIndex& parent) const override;
  int columnCount(const QModelIndex& parent) const override;
  QVariant data(const QModelIndex& index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

  void appendTrack(const Track& track);

private:
  QList<Track> tracks;
};

#endif // TRACKMODEL_H
