
#include "AppViewStep.hpp"

#include <utils/Retranslator.h>

#include <GlobalStorage.h>
#include <JobQueue.h>

CALAMARES_PLUGIN_FACTORY_DEFINITION( AppViewStepFactory, registerPlugin< AppViewStep >(); )

AppViewStep::AppViewStep(QObject* parent) : Calamares::QmlViewStep( parent )
{
    m_config = new Config(this);
    
    //CALAMARES_RETRANSLATE_SLOT(&AppViewStep::onRetranslate);
    /*
    connect( CalamaresUtils::Retranslator::retranslatorFor( this ), 
                       &CalamaresUtils::Retranslator::languageChange, 
                       [=]() {qDebug()<<"EAT THIS";});
                       
    */

}

AppViewStep:: ~AppViewStep()
{
    
}

QString AppViewStep::prettyName() const
{
    return tr("Software LliureX");
}

bool AppViewStep::isNextEnabled() const
{
    return true;
}

bool AppViewStep::isBackEnabled() const
{
    return true;
}


bool AppViewStep::isAtBeginning() const
{
    return true;
}

bool AppViewStep::isAtEnd() const
{
    return true;
}




void AppViewStep::onActivate()
{
    onRetranslate();
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

void AppViewStep::onRetranslate()
{
    
    QVariant tmp = Calamares::JobQueue::instance()->globalStorage()->value("localeConf");
    const QMap<QString, QVariant> conf = tmp.toMap();
    
    QString lang = conf["LANG"].toString();
    
    m_config->setLang(lang);
}
