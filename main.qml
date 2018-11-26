import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4  // use alias to prevent mixing with controls 2.x

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Test table")

    signal trackSelected(int index)

    TableView {
        id: tracksTableView
        anchors.fill: parent
        sortIndicatorVisible: true

        TableViewColumn {
            role: "DataARole"
            title: "A"
            width: 80
        }
        TableViewColumn {
            role: "DataBRole"
            title: "B"
            width: 100
        }

        model: tracksModel

        Component.onCompleted: {
            tracksModel.sort(sortIndicatorColumn, sortIndicatorOrder)
        }

        onSortIndicatorColumnChanged: {
            var selectedRow = currentRow;
            tracksModel.sort(sortIndicatorColumn, sortIndicatorOrder)
            selection.select(tracksModel);
        }

        onSortIndicatorOrderChanged: {
            tracksModel.sort(sortIndicatorColumn, sortIndicatorOrder)
        }

        onClicked: {
            trackSelected(row)
        }
    }
}
