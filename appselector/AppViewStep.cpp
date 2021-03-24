
#include "AppViewStep.hpp"

CALAMARES_PLUGIN_FACTORY_DEFINITION( AppViewStepFactory, registerPlugin< AppViewStep >(); )

AppViewStep::AppViewStep(QObject* parent) : Calamares::QmlViewStep( parent )
{
    m_config = new Config(this);
}

AppViewStep:: ~AppViewStep()
{
    
}

QString AppViewStep::prettyName() const
{
    return tr("Extra goodies");
}

bool AppViewStep::isNextEnabled() const
{
    return true;
}

bool AppViewStep::isBackEnabled() const
{
    return true;
}

void AppViewStep::next()
{
    m_config->m_step=1;
    emit m_config->stepChanged();
    qDebug()<<"next!";
}

void AppViewStep::back()
{
    m_config->m_step=0;
    emit m_config->stepChanged();
    qDebug()<<"back!";
}

bool AppViewStep::isAtBeginning() const
{
    return (m_config->m_step==0);
}

bool AppViewStep::isAtEnd() const
{
    return (m_config->m_step==1);
}

void AppViewStep::onLeave()
{
    m_config->store();
}

Calamares::JobList AppViewStep::jobs() const
{
    return Calamares::JobList();
}

void AppViewStep::setConfigurationMap(const QVariantMap& configurationMap)
{
    Calamares::QmlViewStep::setConfigurationMap( configurationMap );
    m_config->setConfigurationMap(configurationMap);
}

Calamares::RequirementsList AppViewStep::checkRequirements()
{
    Calamares::RequirementsList checkEntries;
    
    return checkEntries;
}

QObject* AppViewStep::getConfig()
{
    return m_config;
}
