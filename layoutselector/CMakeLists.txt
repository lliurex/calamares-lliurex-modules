
# hack
include_directories("/usr/include/libcalamares")

calamares_add_plugin( layoutselector
    TYPE viewmodule
    EXPORT_MACRO PLUGINDLLEXPORT_PRO
    SOURCES
        LayoutViewStep.cpp
        Config.cpp
    RESOURCES
        layoutselector.qrc
    LINK_PRIVATE_LIBRARIES
        KF6::CoreAddons
    SHARED_LIB
)
