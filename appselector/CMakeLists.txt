
# hack
include_directories("/usr/include/libcalamares")

calamares_add_plugin( appselector
    TYPE viewmodule
    EXPORT_MACRO PLUGINDLLEXPORT_PRO
    SOURCES
        AppViewStep.cpp
        Config.cpp
    RESOURCES
        appselector.qrc
    LINK_PRIVATE_LIBRARIES
        KF6::CoreAddons
    SHARED_LIB
)
