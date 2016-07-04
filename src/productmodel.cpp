#include "productmodel.h"

#include <QDebug>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QList>

#include "productdto.h"

const QString ProductModel::REST_URL = "http://192.168.0.172:1337/parse/classes/Products";
const QByteArray ProductModel::APP_ID = "demo";
const QByteArray ProductModel::PARSE_APP_ID_HEADER = "X-Parse-Application-Id";

ProductModel::ProductModel(QObject *aParent)
    : QObject(aParent)
{
    m_insertManager = new QNetworkAccessManager(this);
    m_getAllManager = new QNetworkAccessManager(this);

    connect(m_insertManager, &QNetworkAccessManager::finished, this, &ProductModel::parseInsertResponse);
    connect(m_getAllManager, &QNetworkAccessManager::finished, this, &ProductModel::parseGetAllResponse);

    connect(this, &ProductModel::requireProducts, this, &ProductModel::getAll);
}

ProductModel::~ProductModel()
{
    delete m_insertManager;
}

void ProductModel::parseInsertResponse(QNetworkReply *response)
{
    qDebug () << "insert response: " << response->readAll();
}

void ProductModel::parseGetAllResponse(QNetworkReply *response)
{
    auto respText = response->readAll();
    qDebug () << "get all response: " << respText;

    auto array = QJsonDocument::fromJson(respText).object().value("results").toArray();

    QList<ProductDTO*> dtos;

    for (const auto& el: array)
    {
        ProductDTO* prod = new ProductDTO(this);
        prod->fromJson(el.toObject());
        dtos << prod;
    }
}

void ProductModel::insert(QString name, double price, QString currency, int quantity)
{
    ProductDTO *prod = new ProductDTO();
    prod->setName(name);
    prod->setPrice(price);
    prod->setCurrency(currency);
    prod->setQuantity(quantity);

    QNetworkRequest request;
    request.setUrl(REST_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(PARSE_APP_ID_HEADER, APP_ID);

    m_insertManager->post(request, QJsonDocument(prod->toJson()).toJson());

    emit requireProducts();
}

void ProductModel::getAll()
{
    QNetworkRequest request;
    request.setUrl(REST_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(PARSE_APP_ID_HEADER, APP_ID);

    m_getAllManager->get(request);
}
