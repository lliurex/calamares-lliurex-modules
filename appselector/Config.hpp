
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( int step MEMBER m_step NOTIFY stepChanged)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void setConfigurationMap(const QVariantMap& configurationMap);
    
    void store();
    
    int m_step;
        
    Q_SIGNALS:
    
    void stepChanged();
    
};

#endif
