import QtQuick 2.3
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import edu.parse.demo 1.0

Rectangle {
    id: root;
    width: 1280;
    height: 800;
    color: "lightgrey";

    signal insert(string name, double price, string currency, int quantity);

    ProductModel {
        id: model;
    }

    Connections {
        target: root;
        onInsert: model.insert(name, price, currency, quantity);
    }

    RowLayout {
        id: rowContianer;
        anchors.fill: parent;
        ListView {
            id: elements;
            width: 800;
            delegate: Item {
                width: elements.width;
                Text {
                    id: idField;
                    text: "id: " + model.modeldata.id;
                }
            }
        }
        Item {
            width: 480;
            ColumnLayout {
                RowLayout {
                    Text {
                        id: nameLabel;
                        text: "name";
                    }
                    TextField {
                        id: nameField;
                    }
                }

                RowLayout {
                    Text {
                        id: priceLabel;
                        width: 150;
                        text: "price";
                    }
                    TextField {
                        id: prieField;
                        validator: DoubleValidator{}
                    }
                }

                RowLayout {
                    Text {
                        id: currencyLabel;
                        text: "currency";
                    }
                    TextField {
                        id: currencyField;
                    }
                }

                RowLayout {
                    Text {
                        id: quantityLabel;
                        text: "quantity";
                    }
                    TextField {
                        id: quantityField;
                        validator: IntValidator {}
                    }
                }
                Button {
                    id: addButton;
                    text: "new";
                    onClicked: root.insert(nameField.text, prieField.text, currencyField.text, quantityField.text);
                }
            }

        }
    }
}
