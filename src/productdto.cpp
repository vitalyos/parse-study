#include "productdto.h"

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
