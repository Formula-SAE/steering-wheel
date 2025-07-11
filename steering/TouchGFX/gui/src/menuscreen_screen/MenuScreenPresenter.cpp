#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

#include <algorithm>
#include <cstring>

MenuScreenPresenter::MenuScreenPresenter(MenuScreenView& v)
    : view(v), currentIndex(0), firstTileIndex(0), lastTileIndex(4)
{

}

void MenuScreenPresenter::activate()
{
    model->initMenuItems();
}

void MenuScreenPresenter::deactivate()
{

}

void MenuScreenPresenter::setMenuItems(char* menuItems[], int nMenuItems)
{
    this->nMenuItems = nMenuItems;

    for (int i = 0; i < nMenuItems; ++i) {
        this->menuItems[i] = menuItems[i];
    }

    currentIndex = 0; 
    firstTileIndex = 0;
   
    lastTileIndex = std::min(nMenuItems - 1, NUM_TILES_TO_SHOW - 1);

    updateMenuTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonDown()
{
    if (!nMenuItems) {
        return;
    }
    currentIndex = std::min(currentIndex + 1, nMenuItems - 1);
    adaptIndexes();
    updateMenuTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonUp()
{
    if (!nMenuItems) {
        return;
    }
    currentIndex = std::max(currentIndex - 1, 0);
    adaptIndexes();
    updateMenuTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonConfirm()
{
    if (currentIndex < 0 || currentIndex >= nMenuItems) {
        return;
    }

    if (menuItems[currentIndex] == nullptr) {
        return;
    }

    if (strcmp(menuItems[currentIndex], "Drive") == 0) {
        view.gotoDriveScreen();
    } else if (strcmp(menuItems[currentIndex], "Start Up") == 0) {
        view.gotoStartUpScreen();
    } else {
        view.gotoSectionScreen();
    }
}

void MenuScreenPresenter::handleButtonBack()
{
    
}

void MenuScreenPresenter::adaptIndexes()
{
    if (!nMenuItems) {
        firstTileIndex = 0;
        lastTileIndex = 0;
        return;
    }

    if (currentIndex < firstTileIndex) {
        firstTileIndex = currentIndex;
        lastTileIndex = firstTileIndex + NUM_TILES_TO_SHOW - 1;
    } else if (currentIndex > lastTileIndex) {
        firstTileIndex = currentIndex - (NUM_TILES_TO_SHOW - 1);
        lastTileIndex = currentIndex;
    }

    if (lastTileIndex >= nMenuItems) {
        lastTileIndex = nMenuItems - 1;
        firstTileIndex = std::max(0, lastTileIndex - (NUM_TILES_TO_SHOW - 1));
    }
    if (firstTileIndex < 0) {
        firstTileIndex = 0;
        lastTileIndex = std::min(nMenuItems - 1, NUM_TILES_TO_SHOW - 1);
    }
}

void MenuScreenPresenter::updateMenuTilesInView()
{
    int actualFirst = std::max(0, firstTileIndex);
    int actualLast = std::min(nMenuItems - 1, lastTileIndex);

    char* vectorToPass[actualLast - actualFirst + 1];
    if (actualFirst <= actualLast && nMenuItems > 0) {
        for (int i = actualFirst; i <= actualLast; ++i) {
            vectorToPass[i - actualFirst] = menuItems[i];
        }
    }

    view.setMenuTiles(vectorToPass, actualLast - actualFirst + 1);
}

void MenuScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
