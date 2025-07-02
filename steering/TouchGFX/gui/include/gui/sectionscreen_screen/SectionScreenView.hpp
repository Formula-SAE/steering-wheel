#ifndef SECTIONSCREENVIEW_HPP
#define SECTIONSCREENVIEW_HPP

#include <gui_generated/sectionscreen_screen/SectionScreenViewBase.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>

class SectionScreenView : public SectionScreenViewBase
{
public:
    SectionScreenView();
    virtual ~SectionScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SECTIONSCREENVIEW_HPP
