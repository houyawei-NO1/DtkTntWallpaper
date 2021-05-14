#ifndef DTKTNTWALLPAPER_H
#define DTKTNTWALLPAPER_H

#include <QWidget>
#include <DMainWindow>
#include <DGuiApplicationHelper>
#include <DLabel>
DWIDGET_USE_NAMESPACE

class DtkTntWallpaper : public DMainWindow
{
    Q_OBJECT

public:
    DtkTntWallpaper(DMainWindow *parent = nullptr);
    ~DtkTntWallpaper();
private:
    QWidget *w=new QWidget;
    void setTheme(DGuiApplicationHelper::ColorType);
};
#endif // DTKTNTWALLPAPER_H
