#include <gui/drivescreen_screen/DriveScreenView.hpp>
#include <gui/drivescreen_screen/DriveScreenPresenter.hpp>

DriveScreenPresenter::DriveScreenPresenter(DriveScreenView& v)
    : view(v)
{

}

void DriveScreenPresenter::activate()
{

}

void DriveScreenPresenter::deactivate()
{

}

void DriveScreenPresenter::setSpeed(int speed)
{
    view.setSpeed(speed);
}

void DriveScreenPresenter::setMaxTemp(int maxTemp)
{
    view.setMaxTemp(maxTemp);
}

void DriveScreenPresenter::setAvgTemp(int avgTemp)
{
    view.setAvgTemp(avgTemp);
}

void DriveScreenPresenter::setBatteryLevel(int batteryLevel)
{
    view.setBatteryLevel(batteryLevel);
}

void DriveScreenPresenter::setBatteryPower(int batteryPower)
{
    view.setBatteryPower(batteryPower);
}
