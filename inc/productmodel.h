#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ProductModel: public QObject
{
    Q_OBJECT
public:
    ProductModel(QObject* aParent = Q_NULLPTR);
    ~ProductModel();

private:
    void parseInsertResponse(QNetworkReply *response);

private:
    QNetworkAccessManager* m_insertManager;

private:
    const static QString REST_URL;
    const static QByteArray APP_ID;
    const static QByteArray PARSE_APP_ID_HEADER;
public slots:
    void insert(QString name, double price, QString currency, int quantity);
};

#endif // PRODUCTMODEL_H
