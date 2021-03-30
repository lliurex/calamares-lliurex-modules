
#include "Config.hpp"

#include <GlobalStorage.h>
#include <JobQueue.h>

#include <QDebug>

Config::Config(QObject* parent) : QObject(parent)
{
    m_step=0;
    m_appsModel.append(new App("Alfa","A"));
    m_appsModel.append(new App("Beta","B"));
    
}

void Config::store()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
    //gs->insert( "LliurexDesktopLayout", m_layout );
    //qDebug()<<"storing layout "<<m_layout;
}

void Config::setConfigurationMap(const QVariantMap& configurationMap)
{
    for (auto k: configurationMap.keys()) {
        qDebug()<<"key:"<<k<<"="<<configurationMap[k];
    }
}
