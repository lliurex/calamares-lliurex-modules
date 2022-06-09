
cmake_minimum_required( VERSION 3.16 FATAL_ERROR )

project( calamares-lliurex-modules
    VERSION 1.0
    LANGUAGES C CXX
)

#hack
set (SYSTEM_LIB "/usr/lib/x86_64-linux-gnu/")
set( CMAKE_MODULE_PATH ${SYSTEM_LIB}/cmake/Calamares )

find_package(ECM ${ECM_VERSION} NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

find_package( Qt5 ${QT_VERSION} CONFIG REQUIRED Core Quick QuickWidgets )
find_package( KF5 QUIET COMPONENTS CoreAddons Crash DBusAddons )
find_package( Calamares  REQUIRED calamaresui )

# Recognize more macros to trigger automoc
if(NOT CMAKE_VERSION VERSION_LESS "3.10.0")
    list(APPEND CMAKE_AUTOMOC_MACRO_NAMES
        "K_PLUGIN_FACTORY_WITH_JSON"
        "K_EXPORT_PLASMA_DATAENGINE_WITH_JSON"
        "K_EXPORT_PLASMA_RUNNER"
    )
endif()

include( FeatureSummary )

include( CMakeColors )
include( CalamaresAddBrandingSubdirectory )
include( CalamaresAddLibrary )
include( CalamaresAddModuleSubdirectory )
include( CalamaresAddPlugin )
include( CalamaresAddTest )
include( CalamaresAddTranslations )

set( Calamares_LIBRARIES calamares )

calamares_add_module_subdirectory( layoutselector )
calamares_add_module_subdirectory( appselector )

set( PLUGIN_DESTINATION ${SYSTEM_LIB}/calamares/modules/ )
install( DIRECTORY "layoutselectorbackend" DESTINATION ${PLUGIN_DESTINATION})
install( DIRECTORY "appselectorbackend" DESTINATION ${PLUGIN_DESTINATION})
install( DIRECTORY "lliurexactions" DESTINATION ${PLUGIN_DESTINATION})
install( DIRECTORY "divertmirror" DESTINATION ${PLUGIN_DESTINATION})
install( DIRECTORY "undivertmirror" DESTINATION ${PLUGIN_DESTINATION})
install( DIRECTORY "unlockdpkgunlocker" DESTINATION ${PLUGIN_DESTINATION})
