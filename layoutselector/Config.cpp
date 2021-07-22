
#include "Config.hpp"

#include <GlobalStorage.h>
#include <JobQueue.h>

#include <QDebug>

Config::Config(QObject* parent) : QObject(parent)
{
}

void Config::store()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
    gs->insert( "lliurexDesktopLayout", m_layout );
    qDebug()<<"storing layout "<<m_layout;
}

QString Config::translate(QString id)
{
    QString ret = m_translations[m_lang][id];
    
    if (ret.size()==0) {
        return id;
    }
    return ret;
}

void Config::setLang(QString lang)
{
    m_lang=lang;
    
    emit translationsChanged();
}

void Config::setConfigurationMap(const QVariantMap& configurationMap)
{
    QMap<QString, QVariant>::const_iterator i = configurationMap.find("translations");
    
    if (i!=configurationMap.end()) {
        QVariantList langs = i.value().toList();
        
        QList<QVariant>::const_iterator j = langs.begin();
        
        while (j!=langs.end()) {
            QMap<QString,QVariant> lang = (*j).toMap();
            
            QMap<QString, QVariant>::const_iterator name = lang.find("lang");
            QMap<QString, QVariant>::const_iterator messages = lang.find("messages");
            
            if (name!=lang.end() and messages!=lang.end()) {
                qDebug()<<"Translation for:"<<name.value().toString();
                
                QVariantList msgs = messages.value().toList();
                
                QList<QVariant>::const_iterator q = msgs.begin();
                
                while (q!=msgs.end()) {
                    QMap<QString,QVariant> msg = (*q).toMap();
                    
                    QMap<QString, QVariant>::const_iterator id = msg.find("id");
                    QMap<QString, QVariant>::const_iterator value = msg.find("value");
                    
                    m_translations[name.value().toString()][id.value().toString()] = value.value().toString();
                    
                    q++;
                }
                
            }
            
            j++;
        }
    }
}
