#ifndef DRIVESCREENPRESENTER_HPP
#define DRIVESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DriveScreenView;

class DriveScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DriveScreenPresenter(DriveScreenView& v);

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

    virtual ~DriveScreenPresenter() {}
    
    void setSpeed(int speed) override;
    void setMaxTemp(int maxTemp) override;
    void setAvgTemp(int avgTemp) override;
    void setBatteryLevel(int batteryLevel, int minBatteryLevel, int maxBatteryLevel) override;
    void setBatteryPower(int batteryPower, int minBatteryPower, int maxBatteryPower) override;

private:
    DriveScreenPresenter();

    DriveScreenView& view;
};

#endif // DRIVESCREENPRESENTER_HPP
