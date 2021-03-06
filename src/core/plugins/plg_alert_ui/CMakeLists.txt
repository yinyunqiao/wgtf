CMAKE_MINIMUM_REQUIRED( VERSION 3.1.1 )
PROJECT( plg_alert_ui )

INCLUDE( WGToolsCoreProject )
INCLUDE( WGToolsCoreLibrary )

find_package(QT5)
find_package( Qt5Quick REQUIRED )

BW_QT_ADD_QRC(plg_alert_ui resources/plg_alert_ui)
BW_GLOB_RESOURCE_FILES()

SET( DISPLAY
	alert_models.cpp
	alert_models.hpp
)
SOURCE_GROUP( "Display Page" FILES ${DISPLAY} )

SET( DISPLAY_METADATA
	metadata/alert_models.mpp
)
SOURCE_GROUP( "Display Page\\Metadata" FILES ${DISPLAY_METADATA} )

SET( ALL_SRCS
	${DISPLAY}
	${DISPLAY_METADATA}
	plg_alert_ui.cpp
	popup_alert_presenter.cpp
	popup_alert_presenter.hpp
)
SOURCE_GROUP( "" FILES ${ALL_SRCS} )

BW_BLOB_SOURCES( BLOB_SRCS
	${ALL_SRCS}
)

BW_ADD_TOOL_PLUGIN( plg_alert_ui SHARED
	${BLOB_SRCS}
	${RESOURCE_FILES}
	${COMPILED_RESOURCES}
)

BW_TARGET_LINK_LIBRARIES( plg_alert_ui PRIVATE
	core_generic_plugin
	core_data_model
	core_qt_common
	core_reflection
	core_qt_script
	core_logging_system
	core_ui_framework
    Qt5::Core
    Qt5::Gui
    Qt5::Quick
    Qt5::Widgets
)

BW_PROJECT_CATEGORY( plg_alert_ui "Plugins" )
