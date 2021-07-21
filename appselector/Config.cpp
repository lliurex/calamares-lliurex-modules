
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
    
    while(i!=m_appsModel.end()) {
        
        App* app = static_cast<App*>(*i);
        
        app->setLang(lang);
        i++;
    }
}

void Config::setConfigurationMap(const QVariantMap& configurationMap)
{
    
    qDebug()<<"*** I'm being reconfigured ***";
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
            QMap<QString, QVariant>::const_iterator translation = app.find("translation");
            
            if (name!=app.end() and display!=app.end() and icon!=app.end()) {
                QString desc = (description!=app.end()) ? description.value().toString() : QString();
                bool chk = (checked!=app.end()) ? checked.value().toBool() : false;
                
                QMap<QString,QString> translationStrings;
                
                if (translation!=app.end()) {
                    qDebug()<<"** Translation available";
                     //translations available 
                    
                    QVariantList ts = translation.value().toList();
                    QList<QVariant>::const_iterator q = ts.begin();
                    
                    while (q!=ts.end()) {
                        QMap<QString,QVariant> r = (*q).toMap();
                        QMap<QString, QVariant>::const_iterator name = r.find("name");
                        QMap<QString, QVariant>::const_iterator value = r.find("value");
                        
                        if (name!=r.end() and value!=r.end()) {
                           qDebug()<<name.value().toString()<<":"<<value.value().toString();
                            translationStrings[name.value().toString()]=value.value().toString();
                        }
                        
                        q++;
                    }
                    
                }
                
                m_appsModel.append(new App(
                    name.value().toString(),
                    display.value().toString(),
                    icon.value().toString(),
                    desc,
                    chk,
                    translationStrings
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
                
                QMap<QString,QString> translationStrings;
                
                m_servicesModel.append(new App(
                    name.value().toString(),
                    display.value().toString(),
                    icon.value().toString(),
                    desc,
                    chk,
                    translationStrings
                    ));
            }
            
            j++;
        }
    }
}
