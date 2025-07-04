#include <gui/drivescreen_screen/DriveScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DriveScreenView::DriveScreenView()
{
    setSpeed(0);
    setMaxTemp(0);
    setAvgTemp(0);
    setBatteryLevel(100);
    setBatteryPower(0);
    setClock("000 : 00 : 000");
    setDriveMode(false);
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

   const int16_t textWidth = (this->speed).getTextWidth(); 
   (this->speed).setWidth(textWidth);
   (this->speed).centerX();
   
   const Rect& speedRect = (this->speed).getRect();
   const int16_t speedRight = speedRect.x + speedRect.width;

   kmh.setX(speedRight);

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

void DriveScreenView::setClock(const char* clock) 
{
    Unicode::strncpy(clockBuffer, clock, CLOCK_SIZE);
    (this->clock).invalidate();
}

void DriveScreenView::setDriveMode(bool driveMode) 
{
    (this->driveMode).setVisible(driveMode);
    driveModeBox.setVisible(driveMode);
}