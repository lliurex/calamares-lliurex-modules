
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <QString>
#include <QObject>

class Config : public QObject
{
    Q_OBJECT
    
    
    public:
    
    Config(QObject* parent = nullptr);
    
    void store();
    
    protected:
    
    
};

#endif
