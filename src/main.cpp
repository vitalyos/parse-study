#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

#include "productmodel.h"
#include "productdto.h"

void registerTypes()
{
    qmlRegisterType<ProductModel>("edu.parse.demo", 1, 0, "ProductModel");
    qmlRegisterType<ProductDTO>("edu.parse.demo", 1, 0, "ProductDTO");
}

int main(int argc, char *argv[])
{
    registerTypes();
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl("qrc://../qml/App.qml"));
    view.show();

    return app.exec();
}
