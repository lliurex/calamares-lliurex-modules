
#include "Config.hpp"

#include <GlobalStorage.h>
#include <JobQueue.h>

Config::Config(QObject* parent) : QObject(parent)
{
}

void Config::store()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
}
