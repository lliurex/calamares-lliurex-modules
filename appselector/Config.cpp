
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
    
    gs->insert( "LliurexExtraApps", apps );
    //qDebug()<<"storing layout "<<m_layout;
}

void Config::setConfigurationMap(const QVariantMap& configurationMap)
{
    QMap<QString, QVariant>::const_iterator i = configurationMap.find("apps");
    
    if (i!=configurationMap.end()) {
        QVariantList apps = i.value().toList();
        
        QList<QVariant>::const_iterator j = apps.begin();
        
        while (j!=apps.end()) {
            
            QMap<QString,QVariant> app = (*j).toMap();
            
            QMap<QString, QVariant>::const_iterator p = app.find("name");
            QMap<QString, QVariant>::const_iterator q = app.find("icon");
            
            if (p!=app.end() and q!=app.end()) {
                m_appsModel.append(new App(p.value().toString(),q.value().toString()));
            }
            
            j++;
        }
    }
    
    i = configurationMap.find("services");
    
    if (i!=configurationMap.end()) {
        QVariantList services = i.value().toList();
        
        QList<QVariant>::const_iterator j = services.begin();
        
        while (j!=services.end()) {
            
            QMap<QString,QVariant> srv = (*j).toMap();
            
            QMap<QString, QVariant>::const_iterator p = srv.find("name");
            QMap<QString, QVariant>::const_iterator q = srv.find("icon");
            
            if (p!=srv.end() and q!=srv.end()) {
                m_servicesModel.append(new App(p.value().toString(),q.value().toString()));
            }
            
            j++;
        }
    }
}
