#ifndef SECTIONSCREENPRESENTER_HPP
#define SECTIONSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SectionScreenView;

class SectionScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SectionScreenPresenter(SectionScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SectionScreenPresenter() {}

private:
    SectionScreenPresenter();

    SectionScreenView& view;
};

#endif // SECTIONSCREENPRESENTER_HPP
