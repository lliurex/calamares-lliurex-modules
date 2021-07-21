
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>
#include <QList>
#include <QMap>
#include <QDebug>

class App: public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( QString name MEMBER m_name READ name CONSTANT)
    Q_PROPERTY( QString displayName MEMBER m_iconName READ displayName CONSTANT)
    Q_PROPERTY( QString iconName MEMBER m_iconName READ iconName CONSTANT)
    Q_PROPERTY( QString description MEMBER m_iconName READ description CONSTANT)
    Q_PROPERTY (QString translation READ translation CONSTANT)
    Q_PROPERTY (bool checked MEMBER m_checked NOTIFY checkedChanged)
    
    public:
    
    QString m_name;
    QString m_displayName;
    QString m_description;
    QString m_iconName;
    bool m_checked;
    QMap<QString,QString> m_translation;
    
    QString name () const
    {
        return m_name;
    }
    
    QString displayName () const
    {
        return m_displayName;
    }
    
    QString iconName () const
    {
        return m_iconName;
    }
    
    QString description () const
    {
        return m_description;
    }
    
    QString translation () const
    {
        QString ret = m_translation[m_lang];
        qDebug()<<"ret:"<<ret;
        
        if (ret.size()==0) {
            return m_description;
        }
        
        return ret;
    }
    
    void setLang (QString lang)
    {
        qDebug()<<"setting lang as "<<lang;
        m_lang=lang;
    }
    
    App(QString name, QString displayName, QString iconName, QString description, bool checked, QMap<QString,QString> translation) :
        m_name(name),
        m_displayName(displayName),
        m_iconName(iconName),
        m_description(description),
        m_checked(checked),
        m_translation(translation)
    {
    }
    
    Q_SIGNALS:
        
    void checkedChanged();
    
    private:
    
    QString m_lang;

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
    
    void setLang(QString lang);
    
    int m_step;
    QList<QObject *> m_appsModel;
    QList<QObject *> m_servicesModel;
        
    Q_SIGNALS:
    
    void stepChanged();
    
    private:
    
    QString m_lang;
    
};

#endif
