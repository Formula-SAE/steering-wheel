#ifndef MENUSCREENVIEW_HPP
#define MENUSCREENVIEW_HPP

#include <gui_generated/menuscreen_screen/MenuScreenViewBase.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

class MenuScreenView : public MenuScreenViewBase
{
public:
    MenuScreenView();
    virtual ~MenuScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setMenuTiles(char *menuTiles[], int nMenuTiles);
    void setSelected(int index);
private:
    void reset();
    void hideUnusedTiles(int nUsedTiles);
};

#endif // MENUSCREENVIEW_HPP
