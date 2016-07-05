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
    signal update(string id, string name, double price, string currency, int quantity)

    ProductModel {
        id: pmodel;
    }

    Connections {
        target: root;
        onInsert: pmodel.insert(name, price, currency, quantity);
    }

    RowLayout {
        id: rowContianer;
        anchors.fill: parent;

        ColumnLayout {
            Button {
                id: refreshBtn;
                text: "refresh";
                onClicked: pmodel.getAll();
            }

            ListView {
                id: elements;
                width: 800;
                height: 750;
                model: pmodel.prods;
                delegate: Component {
                    RowLayout {
                        height: 150;

                        ColumnLayout {
                            Text {
                                id: idLabel;
                                text: "id: ";
                            }
                            TextField {
                                id: idField;
                                text: model.modelData.id;
                                enabled: false;
                            }
                        }

                        ColumnLayout {
                            Text {
                                id: nameLabel;
                                text: "name: ";
                            }
                            TextField {
                                id: nameField;
                                text: model.modelData.name;
                            }
                        }

                        ColumnLayout {
                            Text {
                                id: priceLabel;
                                text: "price: ";
                            }
                            TextField {
                                id: priceField;
                                text: model.modelData.price;
                                validator: DoubleValidator{}
                            }
                        }

                        ColumnLayout {
                            Text {
                                id: currencyLabel;
                                text: "currency: ";
                            }
                            TextField {
                                id: currencyField;
                                text: model.modelData.currency;
                            }
                        }

                        ColumnLayout {
                            Text {
                                id: quantityLabel;
                                text: "quantity: ";
                            }
                            TextField {
                                id: quantityField;
                                text: model.modelData.quantity;
                                validator: IntValidator{}
                            }
                        }

                        ColumnLayout {
                            Button {
                                id: updateBtn;
                                text: "update";
                                onClicked: root.update(model.modelData.id, currencyField.text, priceField.text, currencyField.text, quantityField.text);
                            }

                            Button {
                                id: deleteButton;
                                text: "delete";
                                onClicked: pmodel.deleteProduct(model.modelData.id);
                            }
                        }
                    }
                }
            }
        }

        Item {
            width: 480;
            ColumnLayout {
                RowLayout {
                    Text {
                        id: nameInsertLabel;
                        text: "name";
                    }
                    TextField {
                        id: nameInsertField;
                    }
                }

                RowLayout {
                    Text {
                        id: priceInsertLabel;
                        width: 150;
                        text: "price";
                    }
                    TextField {
                        id: priceInsertField;
                        validator: DoubleValidator{}
                    }
                }

                RowLayout {
                    Text {
                        id: currencyInsertLabel;
                        text: "currency";
                    }
                    TextField {
                        id: currencyInsertField;
                    }
                }

                RowLayout {
                    Text {
                        id: quantityInsertLabel;
                        text: "quantity";
                    }
                    TextField {
                        id: quantityInsertField;
                        validator: IntValidator {}
                    }
                }
                Button {
                    id: addButton;
                    text: "new";
                    onClicked: root.insert(nameInsertField.text, priceInsertField.text, currencyInsertField.text, quantityInsertField.text);
                }
            }

        }
    }
}
