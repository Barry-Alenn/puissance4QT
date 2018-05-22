import QtQuick 2.0

Rectangle {
width: 400
height: 400

    Rectangle {
        id: item
        width: 300
        height: 50
        anchors.centerIn: parent
        color: "chocolate"
        property bool rotated: false
        rotation: rotated ? 90 : 0
    }

    Connections {
        target: button
        onClicked: item.rotated = !item.rotated
    }

}

