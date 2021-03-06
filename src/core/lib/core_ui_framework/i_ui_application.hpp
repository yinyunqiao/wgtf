#ifndef I_UI_APPLICATION_HPP
#define I_UI_APPLICATION_HPP

#include "core_dependency_system/i_interface.hpp"
#include "core_generic_plugin/interfaces/i_application.hpp"
#include "layout_hint.hpp"

#include <map>
#include <memory>

namespace wgt
{
class IAction;
class IComponent;
class IMenu;
class IWindow;
class IView;

typedef std::map< std::string, IWindow * > Windows;

class IUIApplication : public Implements< IApplication >
{
public:
	virtual ~IUIApplication() {}

	virtual void addWindow( IWindow & window ) = 0;
	virtual void removeWindow( IWindow & window ) = 0;
	virtual void addView( IView & view ) = 0;
	virtual void removeView( IView & view ) = 0;
	virtual void addMenu( IMenu & menu ) = 0;
	virtual void removeMenu( IMenu & menu ) = 0;
	virtual void addAction( IAction & action ) = 0;
	virtual void removeAction( IAction & action ) = 0;
	virtual void setWindowIcon(const char* path, const char* windowId = "") = 0;
	virtual const Windows & windows() const = 0;
};
} // end namespace wgt
#endif//I_UI_APPLICATION_HPP
