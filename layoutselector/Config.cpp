
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
    gs->insert( "LliurexDesktopLayout", m_layout );
    qDebug()<<"storing layout "<<m_layout;
}

