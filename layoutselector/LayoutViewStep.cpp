
#include "LayoutViewStep.hpp"

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
    return tr("Default layout");
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

Calamares::JobList LayoutViewStep::jobs() const
{
    return Calamares::JobList();
}

void LayoutViewStep::setConfigurationMap(const QVariantMap& configurationMap)
{
    Calamares::QmlViewStep::setConfigurationMap( configurationMap );
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
