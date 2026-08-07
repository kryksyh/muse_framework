muse_create_qml_module(muse_diagnostics_qml ALIAS muse::diagnostics_qml FOR muse_diagnostics)

set(_profiler_sources)
set(_profiler_qml_files)
if (MUSE_MODULE_GLOBAL_PROFILER)
    list(APPEND _profiler_sources
        system/profilerviewmodel.cpp
        system/profilerviewmodel.h
    )
    list(APPEND _profiler_qml_files
        DiagnosticProfilerDialog.qml
        DiagnosticProfilerPanel.qml
    )
endif()

qt_add_qml_module(muse_diagnostics_qml
    URI Muse.Diagnostics
    VERSION 1.0
    SOURCES
        actionsviewmodel.cpp
        actionsviewmodel.h
        devtools/crashhandlerdevtoolsmodel.cpp
        devtools/crashhandlerdevtoolsmodel.h
        diagnosticaccessiblemodel.cpp
        diagnosticaccessiblemodel.h
        diagnosticspathsmodel.cpp
        diagnosticspathsmodel.h
        keynav/abstractkeynavdevitem.cpp
        keynav/abstractkeynavdevitem.h
        keynav/diagnosticnavigationmodel.cpp
        keynav/diagnosticnavigationmodel.h
        keynav/keynavdevcontrol.cpp
        keynav/keynavdevcontrol.h
        keynav/keynavdevsection.cpp
        keynav/keynavdevsection.h
        keynav/keynavdevsubsection.cpp
        keynav/keynavdevsubsection.h
        system/graphicsinfomodel.cpp
        system/graphicsinfomodel.h
        ${_profiler_sources}
    QML_FILES
        DiagnosticAccessibleDialog.qml
        DiagnosticAccessiblePanel.qml
        DiagnosticActionsDialog.qml
        DiagnosticActionsPanel.qml
        DiagnosticGraphicsInfoDialog.qml
        DiagnosticGraphicsInfoPanel.qml
        DiagnosticNavigationDialog.qml
        DiagnosticNavigationPanel.qml
        DiagnosticPathsDialog.qml
        DiagnosticPathsPanel.qml
        ${_profiler_qml_files}
    IMPORTS
        TARGET muse_ui_qml
        TARGET muse_uicomponents_qml
)

fixup_qml_module_dependencies(muse_diagnostics_qml)

# Necessary for the auto-generated sources
target_include_directories(muse_diagnostics_qml PRIVATE devtools keynav system)
