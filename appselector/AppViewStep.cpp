
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
    return tr("Default layout");
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
}

void AppViewStep::back()
{
}

bool AppViewStep::isAtBeginning() const
{
    return true;
}

bool AppViewStep::isAtEnd() const
{
    return true;
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
