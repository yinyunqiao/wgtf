CMAKE_MINIMUM_REQUIRED( VERSION 3.1.1 )
PROJECT( plg_progress_manager_test )

INCLUDE( WGToolsCoreProject )
find_package(QT5)

REMOVE_DEFINITIONS( /WX )
ADD_DEFINITIONS(
	-D_CRT_SECURE_NO_WARNINGS
)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET( COMMAND_SRCS
	commands/test_command.hpp
	commands/test_command.cpp
)
SOURCE_GROUP( "Commands" FILES ${COMMAND_SRCS} )

SET( ALL_SRCS
	mainwindow/mainwindow.cpp
	mainwindow/mainwindow.hpp
	plg_progress_manager_test.cpp
)
SOURCE_GROUP( "" FILES ${ALL_SRCS} )

BW_QT_ADD_QRC(plg_progress_manager_test resources/plg_progress_manager_test)
BW_GLOB_RESOURCE_FILES()

BW_ADD_TOOL_PLUGIN( plg_progress_manager_test SHARED
	${ALL_SRCS}
	${COMPILED_RESOURCES}
	${COMMAND_SRCS}
)

BW_TARGET_LINK_LIBRARIES( plg_progress_manager_test PRIVATE
	core_command_system
	core_reflection
	core_generic_plugin
	core_ui_framework
    Qt5::Core
    Qt5::Gui
    Qt5::Quick
    Qt5::Widgets
)

BW_PROJECT_CATEGORY( plg_progress_manager_test "Plugins" )
