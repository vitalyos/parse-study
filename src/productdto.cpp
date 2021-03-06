#include "productdto.h"

QString ProductDTO::ID_KEY = "objectId";
QString ProductDTO::NAME_KEY = "name";
QString ProductDTO::PRICE_KEY = "price";
QString ProductDTO::CURRENCY_KEY = "currency";
QString ProductDTO::QUANTITY_KEY = "quantity";

ProductDTO::ProductDTO(QObject *parentObj) : QObject(parentObj)
{

}

QString ProductDTO::name() const
{
    return m_name;
}

void ProductDTO::setName(const QString &name)
{
    m_name = name;
    emit contentChanged();
}

double ProductDTO::price() const
{
    return m_price;
}

void ProductDTO::setPrice(double price)
{
    m_price = price;
    emit contentChanged();
}

QString ProductDTO::currency() const
{
    return m_currency;
}

void ProductDTO::setCurrency(const QString &currency)
{
    m_currency = currency;
    emit contentChanged();
}

quint16 ProductDTO::quantity() const
{
    return m_quantity;
}

void ProductDTO::setQuantity(const quint16 &quantity)
{
    m_quantity = quantity;
    emit contentChanged();
}

QString ProductDTO::id() const
{
    return m_id;
}

void ProductDTO::setId(const QString &id)
{
    m_id = id;
    emit contentChanged();
}

void ProductDTO::fromJson(const QJsonObject &source)
{
    m_id = source[ID_KEY].toString();
    m_name = source[NAME_KEY].toString();
    m_price = source[PRICE_KEY].toDouble();
    m_currency = source[CURRENCY_KEY].toString();
    m_quantity = source[QUANTITY_KEY].toInt();
    emit contentChanged();
}

QJsonObject ProductDTO::toJson() const
{
    QJsonObject destination;
    destination.insert(NAME_KEY, m_name);
    destination.insert(PRICE_KEY, m_price);
    destination.insert(CURRENCY_KEY, m_currency);
    destination.insert(QUANTITY_KEY, m_quantity);
    return destination;
}
