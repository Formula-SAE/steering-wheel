#ifndef DRIVESCREENVIEW_HPP
#define DRIVESCREENVIEW_HPP

#include <gui_generated/drivescreen_screen/DriveScreenViewBase.hpp>
#include <gui/drivescreen_screen/DriveScreenPresenter.hpp>

class DriveScreenView : public DriveScreenViewBase
{
public:
    DriveScreenView();
    virtual ~DriveScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setSpeed(int speed);
    void setMaxTemp(int maxTemp);
    void setAvgTemp(int avgTemp);
    void setBatteryLevel(int batteryLevel);
    void setBatteryPower(int batteryPower);
    void setClock(const char* clock);
    void setDriveMode(bool driveMode);
protected:
};

#endif // DRIVESCREENVIEW_HPP
