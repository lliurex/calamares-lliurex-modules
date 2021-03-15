
cmake_minimum_required( VERSION 3.3 FATAL_ERROR )

project( calamares-lliurex-modules
    VERSION 1.0
    LANGUAGES C CXX
)

# hack
set( CMAKE_MODULE_PATH "/usr/lib/x86_64-linux-gnu/cmake/Calamares" )

find_package(ECM ${ECM_VERSION} NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})

find_package( Qt5 ${QT_VERSION} CONFIG REQUIRED Core Quick QuickWidgets )
find_package( KF5 QUIET COMPONENTS CoreAddons Crash DBusAddons )

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
