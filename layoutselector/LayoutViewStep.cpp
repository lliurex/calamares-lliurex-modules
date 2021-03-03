
#include "LayoutViewStep.hpp"

LayoutViewStep::LayoutViewStep( QObject* parent)
{
}

LayoutViewStep:: ~LayoutViewStep()
{
}

QString LayoutViewStep::prettyName()
{
    return tr("Default layout");
}

QWidget* LayoutViewStep::widget()
{
    return nullptr;
}

bool LayoutViewStep::isNextEnabled()
{
}

bool LayoutViewStep::isBackEnabled()
{
}

bool LayoutViewStep::isAtBeginning()
{
}

bool LayoutViewStep::isAtEnd()
{
}

Calamares::JobList LayoutViewStep::jobs()
{
}

void LayoutViewStep::setConfigurationMap( const QVariantMap& configurationMap )
{
}

Calamares::RequirementsList LayoutViewStep::checkRequirements()
{
}
