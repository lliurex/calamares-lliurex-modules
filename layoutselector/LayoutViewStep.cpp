
#include "LayoutViewStep.hpp"

CALAMARES_PLUGIN_FACTORY_DEFINITION( LayoutViewStepFactory, registerPlugin< LayoutViewStep >(); )

LayoutViewStep::LayoutViewStep(QObject* parent) : Calamares::QmlViewStep( parent )
{
}

LayoutViewStep:: ~LayoutViewStep()
{
}

QString LayoutViewStep::prettyName() const
{
    return tr("Default layout");
}

QWidget* LayoutViewStep::widget()
{
    return nullptr;
}

bool LayoutViewStep::isNextEnabled() const
{
}

bool LayoutViewStep::isBackEnabled() const
{
}

bool LayoutViewStep::isAtBeginning() const
{
}

bool LayoutViewStep::isAtEnd() const
{
}

Calamares::JobList LayoutViewStep::jobs() const
{
}

void LayoutViewStep::setConfigurationMap(const QVariantMap& configurationMap)
{
}

Calamares::RequirementsList LayoutViewStep::checkRequirements()
{
}
