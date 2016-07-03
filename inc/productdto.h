#ifndef PRODUCTDTO_H
#define PRODUCTDTO_H

#include <QObject>
#include <QtGlobal>
#include <QString>

class ProductDTO : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY contentChanged)
    Q_PROPERTY(double price READ price WRITE setPrice NOTIFY contentChanged)
    Q_PROPERTY(QString currency READ currency WRITE setCurrency NOTIFY contentChanged)
    Q_PROPERTY(quint16 quantity READ quantity WRITE setQuantity NOTIFY contentChanged)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY contentChanged)
public:
    explicit ProductDTO(QObject *parentObj = Q_NULLPTR);

    QString name() const;
    void setName(const QString &name);

    double price() const;
    void setPrice(double price);

    QString currency() const;
    void setCurrency(const QString &currency);

    quint16 quantity() const;
    void setQuantity(const quint16 &quantity);

    QString id() const;
    void setId(const QString &id);

signals:
    void contentChanged();

public slots:

private:
    QString m_id;
    QString m_name;
    double m_price;
    QString m_currency;
    quint16 m_quantity;

    static QString ID_KEY;
    static QString NAME_KEY;
    static QString PRICE_KEY;
    static QString CURRENCY_KEY;
    static QString QUANTITY_KEY;
};

#endif // PRODUCTDTO_H
