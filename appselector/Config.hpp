
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>
#include <QList>

class App: public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( QString name MEMBER m_name READ name)
    Q_PROPERTY( QString icoName MEMBER m_iconName READ iconName)
    
    public:
    
    QString m_name;
    QString m_iconName;
    
    QString name () const
    {
        return m_name;
    }
    
    QString iconName () const
    {
        return m_iconName;
    }
    
    App(QString name,QString iconName) : m_name(name),m_iconName(iconName)
    {
    }
};

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( int step MEMBER m_step NOTIFY stepChanged)
    Q_PROPERTY(QList<QObject *> appsModel MEMBER m_appsModel CONSTANT)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void setConfigurationMap(const QVariantMap& configurationMap);
    
    void store();
    
    int m_step;
    QList<QObject *> m_appsModel;
        
    Q_SIGNALS:
    
    void stepChanged();
    
};

#endif
