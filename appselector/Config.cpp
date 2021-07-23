
#include "Config.hpp"

#include <GlobalStorage.h>
#include <JobQueue.h>

#include <QDebug>

Config::Config(QObject* parent) : QObject(parent)
{
    m_step=0;
    
}

void Config::store()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
    QList<QVariant> apps;
    
    QList<QObject* >::const_iterator i = m_appsModel.begin();
    
    while(i!=m_appsModel.end()) {
        
        App* app = static_cast<App*>(*i);
        
        if (app->m_checked) {
            apps.append(app->m_name);
        }
        
        i++;
    }
    
    gs->insert( "lliurexExtraApps", apps );
    
    QList<QVariant> services;
    
    QList<QObject* >::const_iterator j = m_servicesModel.begin();
    
    while(j!=m_servicesModel.end()) {
        
        App* app = static_cast<App*>(*j);
        
        if (app->m_checked) {
            services.append(app->m_name);
        }
        
        j++;
    }
    
    gs->insert("lliurexExtraServices", services );

}

void Config::setLang(QString lang)
{
    QList<QObject* >::const_iterator i = m_appsModel.begin();
    m_lang=lang;
    
    while(i!=m_appsModel.end()) {
        
        App* app = static_cast<App*>(*i);
        
        QString id = app->description();
        
        app->translate(m_translations[lang][id]);
        //qDebug()<<"translation:"<<m_translations[lang][id];
        i++;
    }
    
    emit appsModelChanged();
}

QString Config::translate(QString id)
{
    //qDebug()<<"invoked translation"<<id<<":"<<m_lang<<":"<<m_translations[m_lang][id];
    QString ret = m_translations[m_lang][id];
    
    if (ret.size()==0) {
        return id;
    }
    return ret;
}

void Config::setConfigurationMap(const QVariantMap& configurationMap)
{
    
    QMap<QString, QVariant>::const_iterator i = configurationMap.find("apps");
    
    if (i!=configurationMap.end()) {
        QVariantList apps = i.value().toList();
        
        QList<QVariant>::const_iterator j = apps.begin();
        
        while (j!=apps.end()) {
            
            QMap<QString,QVariant> app = (*j).toMap();
            
            QMap<QString, QVariant>::const_iterator name = app.find("name");
            QMap<QString, QVariant>::const_iterator display = app.find("display");
            QMap<QString, QVariant>::const_iterator icon = app.find("icon");
            QMap<QString, QVariant>::const_iterator description = app.find("description");
            QMap<QString, QVariant>::const_iterator checked = app.find("checked");
            
            if (name!=app.end() and display!=app.end() and icon!=app.end()) {
                QString desc = (description!=app.end()) ? description.value().toString() : QString();
                bool chk = (checked!=app.end()) ? checked.value().toBool() : false;
                
                m_appsModel.append(new App(
                    name.value().toString(),
                    display.value().toString(),
                    icon.value().toString(),
                    desc,
                    chk
                    ));
            }
            
            j++;
        }
    }
    
    i = configurationMap.find("services");
    
    if (i!=configurationMap.end()) {
        QVariantList services = i.value().toList();
        
        QList<QVariant>::const_iterator j = services.begin();
        
        while (j!=services.end()) {
            
            QMap<QString,QVariant> app = (*j).toMap();
            
            QMap<QString, QVariant>::const_iterator name = app.find("name");
            QMap<QString, QVariant>::const_iterator display = app.find("display");
            QMap<QString, QVariant>::const_iterator icon = app.find("icon");
            QMap<QString, QVariant>::const_iterator description = app.find("description");
            QMap<QString, QVariant>::const_iterator checked = app.find("checked");
            
            if (name!=app.end() and display!=app.end() and icon!=app.end()) {
                QString desc = (description!=app.end()) ? description.value().toString() : QString();
                bool chk = (checked!=app.end()) ? checked.value().toBool() : false;
                
                m_servicesModel.append(new App(
                    name.value().toString(),
                    display.value().toString(),
                    icon.value().toString(),
                    desc,
                    chk
                    ));
            }
            
            j++;
        }
    }
    
    i = configurationMap.find("translations");
    
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
    
    //qDebug()<<m_translations;
}
