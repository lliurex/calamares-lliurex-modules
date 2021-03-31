
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>
#include <QList>

class App: public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( QString name MEMBER m_name READ name CONSTANT)
    Q_PROPERTY( QString iconName MEMBER m_iconName READ iconName CONSTANT)
    Q_PROPERTY (bool checked MEMBER m_checked NOTIFY checkedChanged)
    
    public:
    
    QString m_name;
    QString m_displayName;
    QString m_description;
    QString m_iconName;
    bool m_checked;
    
    QString name () const
    {
        return m_name;
    }
    
    QString iconName () const
    {
        return m_iconName;
    }
    
    App(QString name,QString iconName) : m_name(name),m_iconName(iconName), m_checked(false)
    {
    }
    
    Q_SIGNALS:
        
    void checkedChanged();
};

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( int step MEMBER m_step NOTIFY stepChanged)
    Q_PROPERTY(QList<QObject *> appsModel MEMBER m_appsModel CONSTANT)
    Q_PROPERTY(QList<QObject *> servicesModel MEMBER m_servicesModel CONSTANT)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void setConfigurationMap(const QVariantMap& configurationMap);
    
    void store();
    
    int m_step;
    QList<QObject *> m_appsModel;
    QList<QObject *> m_servicesModel;
        
    Q_SIGNALS:
    
    void stepChanged();
    
};

#endif
