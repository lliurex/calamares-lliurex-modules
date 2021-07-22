
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>
#include <QMap>

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( QString layout MEMBER m_layout NOTIFY layoutChanged)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void store();
    Q_INVOKABLE QString translate(QString id);
    void setConfigurationMap(const QVariantMap& configurationMap);
    void setLang(QString lang);
    
    protected:
    
    QString m_layout;
    QString m_lang;
    QMap<QString, QMap<QString, QString> > m_translations;
    
    Q_SIGNALS:
    
    void layoutChanged();
    void translationsChanged();
};

#endif
