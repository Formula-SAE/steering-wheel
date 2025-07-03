#include <gui/drivescreen_screen/DriveScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DriveScreenView::DriveScreenView()
{

}

void DriveScreenView::setupScreen()
{
    DriveScreenViewBase::setupScreen();
}

void DriveScreenView::tearDownScreen()
{
    DriveScreenViewBase::tearDownScreen();
}

void DriveScreenView::setSpeed(int speed)
{
   Unicode::snprintf(speedBuffer, SPEED_SIZE, "%d", speed); 
   (this->speed).invalidate();
}

void DriveScreenView::setMaxTemp(int maxTemp)
{
   Unicode::snprintf(maxTempBuffer, MAXTEMP_SIZE, "%d", maxTemp); 
   (this->maxTemp).invalidate();
}

void DriveScreenView::setAvgTemp(int avgTemp)
{
   Unicode::snprintf(avgTempBuffer, AVGTEMP_SIZE, "%d", avgTemp); 
   (this->avgTemp).invalidate();
}

void DriveScreenView::setBatteryLevel(int batteryLevel)
{
    (this->batteryLevel).setValue(100 - batteryLevel);
}

void DriveScreenView::setBatteryPower(int batteryPower)
{
    (this->batteryPower).setValue(100 - batteryPower);
}