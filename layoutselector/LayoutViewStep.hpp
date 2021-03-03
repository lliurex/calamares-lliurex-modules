

#ifndef LAYOUTVIEWSTEP_HPP
#define LAYOUTVIEWSTEP_HPP

#include <DllMacro.h>
#include <modulesystem/Requirement.h>
#include <utils/PluginFactory.h>
#include <viewpages/ViewStep.h>

#include <QObject>

class PLUGINDLLEXPORT LayoutViewStep : public Calamares::ViewStep
{
    Q_OBJECT
    
    public:
    
    explicit LayoutViewStep( QObject* parent = nullptr );
    ~LayoutViewStep() override;

    QString prettyName() const override;

    QWidget* widget() override;

    bool isNextEnabled() const override;
    bool isBackEnabled() const override;

    bool isAtBeginning() const override;
    bool isAtEnd() const override;

    Calamares::JobList jobs() const override;

    void setConfigurationMap( const QVariantMap& configurationMap ) override;

    Calamares::RequirementsList checkRequirements() override;
};

#endif
