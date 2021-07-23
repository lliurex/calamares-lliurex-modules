

#ifndef APPVIEWSTEP_HPP
#define APPVIEWSTEP_HPP

#include "Config.hpp"

#include <DllMacro.h>
#include <modulesystem/Requirement.h>
#include <utils/PluginFactory.h>
#include <viewpages/ViewStep.h>
#include <viewpages/QmlViewStep.h>

#include <QObject>

class PLUGINDLLEXPORT AppViewStep : public Calamares::QmlViewStep
{
    Q_OBJECT
    
    public:
    
    explicit AppViewStep(QObject* parent = nullptr);
    ~AppViewStep() override;

    QString prettyName() const override;

    bool isNextEnabled() const override;
    bool isBackEnabled() const override;
    
    void next() override;
    void back() override;

    bool isAtBeginning() const override;
    bool isAtEnd() const override;
    
    void onActivate() override;
    void onLeave() override;

    Calamares::JobList jobs() const override;

    void setConfigurationMap(const QVariantMap& configurationMap) override;

    Calamares::RequirementsList checkRequirements() override;
    
    QObject* getConfig() override;
    
    protected:
    
    Config* m_config;
    
    public slots:
    
    void onRetranslate();
    
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( AppViewStepFactory )

#endif
