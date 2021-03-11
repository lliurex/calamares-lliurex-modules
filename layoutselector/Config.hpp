
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>

class Config : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY( QString layout MEMBER m_layout NOTIFY layoutChanged)
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void store();
    
    protected:
    
    QString m_layout;
    
    Q_SIGNALS:
    
    void layoutChanged();
};

#endif
