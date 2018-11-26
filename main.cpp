#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "trackmodel.h"
#include "tracksortfilterproxymodel.h"

void fillDataModel(TrackModel* tracksModel)
{
  tracksModel->appendTrack({12, 103});
  tracksModel->appendTrack({22, 78});
  tracksModel->appendTrack({32, 200});
}

int main(int argc, char *argv[])
{
  //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  TrackModel tracksModel;
  fillDataModel(&tracksModel);

  TrackSortFilterProxyModel sortFilterModel;
  sortFilterModel.setSourceModel(&tracksModel);
  sortFilterModel.setSortRole(TrackModel::DataA);
  sortFilterModel.setSortCaseSensitivity(Qt::CaseInsensitive);
  sortFilterModel.setDynamicSortFilter(true);

  QQmlContext* ctxt = engine.rootContext();
  ctxt->setContextProperty("tracksModel", &sortFilterModel);

  return app.exec();
}
