
#include "LayoutViewStep.hpp"

#include <GlobalStorage.h>
#include <JobQueue.h>

#include <QDebug>

CALAMARES_PLUGIN_FACTORY_DEFINITION( LayoutViewStepFactory, registerPlugin< LayoutViewStep >(); )

LayoutViewStep::LayoutViewStep(QObject* parent) : Calamares::QmlViewStep( parent )
{
    m_config = new Config(this);
}

LayoutViewStep:: ~LayoutViewStep()
{
    
}

QString LayoutViewStep::prettyName() const
{
    return tr("Keyboard") + "--";
}

bool LayoutViewStep::isNextEnabled() const
{
    return true;
}

bool LayoutViewStep::isBackEnabled() const
{
    return true;
}

bool LayoutViewStep::isAtBeginning() const
{
    return true;
}

bool LayoutViewStep::isAtEnd() const
{
    return true;
}

void LayoutViewStep::onActivate()
{
    
    QVariant tmp = Calamares::JobQueue::instance()->globalStorage()->value("localeConf");
    const QMap<QString, QVariant> conf = tmp.toMap();
    
    QString lang = conf["LANG"].toString();
    
    m_config->setLang(lang);
}

void LayoutViewStep::onLeave()
{
    m_config->store();
}

Calamares::JobList LayoutViewStep::jobs() const
{
    return Calamares::JobList();
}

void LayoutViewStep::setConfigurationMap(const QVariantMap& configurationMap)
{
    qDebug()<<"LV::CM";
    
    Calamares::QmlViewStep::setConfigurationMap( configurationMap );
    m_config->setConfigurationMap(configurationMap);
}

Calamares::RequirementsList LayoutViewStep::checkRequirements()
{
    Calamares::RequirementsList checkEntries;
    
    return checkEntries;
}

QObject* LayoutViewStep::getConfig()
{
    return m_config;
}
