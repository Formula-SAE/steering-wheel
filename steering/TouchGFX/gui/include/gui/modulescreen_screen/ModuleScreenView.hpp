#ifndef MODULESCREENVIEW_HPP
#define MODULESCREENVIEW_HPP

#include <gui_generated/modulescreen_screen/ModuleScreenViewBase.hpp>
#include <gui/modulescreen_screen/ModuleScreenPresenter.hpp>

class ModuleScreenView : public ModuleScreenViewBase
{
public:
    ModuleScreenView();
    virtual ~ModuleScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MODULESCREENVIEW_HPP
