
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
    Q_PROPERTY (QString translation READ translation NOTIFY translationChanged)
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
        QString ret = m_translation;
        
        if (ret.size()==0) {
            return m_description;
        }
        
        return ret;
    }
    
    void translate(QString value)
    {
        m_translation=value;
        emit translationChanged();
    }
    
    App(QString name, QString displayName, QString iconName, QString description, bool checked) :
        m_name(name),
        m_displayName(displayName),
        m_iconName(iconName),
        m_description(description),
        m_checked(checked)
    {
    }
    
    Q_SIGNALS:
        
    void checkedChanged();
    void translationChanged();
    
    private:
    
    QString m_lang;
    QString m_translation;

};

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( int step MEMBER m_step NOTIFY stepChanged)
    Q_PROPERTY(QList<QObject *> appsModel MEMBER m_appsModel NOTIFY appsModelChanged)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void setConfigurationMap(const QVariantMap& configurationMap);
    
    void store();
    
    void setLang(QString lang);
    
    Q_INVOKABLE QString translate(QString id);
    
    int m_step;
    QList<QObject *> m_appsModel;
        
    Q_SIGNALS:
    
    void stepChanged();
    void appsModelChanged();
    
    private:
    
    QString m_lang;
    
    QMap<QString, QMap<QString, QString> > m_translations;
    
};

#endif
