#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/menuscreen_screen/MenuItem.hpp>
#include <main.h>

Model::Model() : modelListener(0)
{

}

void Model::initMenuItems()
{
  int nMenuItems = 0;
  char *menuItems[nMenuItems] = {};

  modelListener->setMenuItems(menuItems, nMenuItems);
}

void Model::tick()
{

}
