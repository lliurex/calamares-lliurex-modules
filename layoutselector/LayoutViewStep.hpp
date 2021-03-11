

#ifndef LAYOUTVIEWSTEP_HPP
#define LAYOUTVIEWSTEP_HPP

#include "Config.hpp"

#include <DllMacro.h>
#include <modulesystem/Requirement.h>
#include <utils/PluginFactory.h>
#include <viewpages/ViewStep.h>
#include <viewpages/QmlViewStep.h>

#include <QObject>

class PLUGINDLLEXPORT LayoutViewStep : public Calamares::QmlViewStep
{
    Q_OBJECT
    
    public:
    
    explicit LayoutViewStep(QObject* parent = nullptr);
    ~LayoutViewStep() override;

    QString prettyName() const override;

    bool isNextEnabled() const override;
    bool isBackEnabled() const override;

    bool isAtBeginning() const override;
    bool isAtEnd() const override;
    
    void onLeave() override;

    Calamares::JobList jobs() const override;

    void setConfigurationMap(const QVariantMap& configurationMap) override;

    Calamares::RequirementsList checkRequirements() override;
    
    QObject* getConfig() override;
    
    protected:
    
    Config* m_config;
    
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( LayoutViewStepFactory )

#endif
