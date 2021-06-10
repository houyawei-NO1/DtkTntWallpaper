#include "dtktntwallpaper.h"

#include <DApplication>
DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication a(argc, argv);

    a.loadTranslator(); //加载翻译
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setOrganizationName("deepin"); //设置组织名称
    a.setApplicationVersion(DApplication::buildVersion("0.1"));//设置程序版本
    a.setProductIcon(QIcon::fromTheme("deepin-launcher"));  //设置程序Logo
    a.setProductName("DtkDemo"); //设置项目名称
    a.setApplicationDescription("Programs developed using DTK");//设置程序介绍
    a.setApplicationName("DtkDemo"); //只有在这儿修改窗口标题才有效


    DtkTntWallpaper w;
    w.show();

    return a.exec();
}
