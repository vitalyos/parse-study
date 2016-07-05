#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "productdto.h"

class ProductModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList prods READ getProducts WRITE setProducts NOTIFY productsChanged)
public:
    ProductModel(QObject* aParent = Q_NULLPTR);
    ~ProductModel();

    QVariantList getProducts() const;
    void setProducts(const QVariantList &products);

private:
    void parseInsertUpdateDeleteResponse(QNetworkReply* response);
    void parseGetAllResponse(QNetworkReply* response);
private:
    QNetworkAccessManager* m_insertUpdateDeleteManager;
    QNetworkAccessManager* m_getAllManager;

    QVariantList m_products;

signals:
    void requireProducts();
    void productsChanged();

private:
    const static QString REST_URL;
    const static QByteArray APP_ID;
    const static QByteArray PARSE_APP_ID_HEADER;

public slots:
    void insert(QString name, double price, QString currency, int quantity);
    void update(QString id, QString name, double price, QString currency, int quantity);
    void getAll();
    void deleteProduct(const QSting& id);
};

#endif // PRODUCTMODEL_H
