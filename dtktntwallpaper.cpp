#include "dtktntwallpaper.h"
#include <DWidgetUtil> //加入此头文件方可使用moveToCenter
#include <DSearchEdit>
#include <DTitlebar>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <DFloatingButton>
#include <DPushButton>

DtkTntWallpaper::DtkTntWallpaper(DMainWindow *parent)
    : DMainWindow(parent)
{
    //初始化主窗口 Initialize the main window
       setCentralWidget(w);//将w作为窗口的用户部分（整个窗口除了标题栏的部分）
       moveToCenter(this); //把窗口移动到屏幕中间

       DLabel *pic_label=new DLabel;
       pic_label->setText("Hello World");
       QImage *pic = new QImage;
       pic->load(":/wallpaper/wallpaper/1.jpg");
       QPixmap p1 = QPixmap::fromImage(*pic);
       QSize s1 = p1.size();
       QSize s2(s1.width() * 0.5, s1.height() * 0.5);
       DtkTntWallpaper::setMinimumSize(s2);
       DtkTntWallpaper::setMaximumSize(s2);
       pic_label->setPixmap(p1.scaled(s2, Qt::KeepAspectRatio));

       QVBoxLayout *backlayout = new QVBoxLayout(w);
       backlayout->setMargin(0);
       backlayout->addWidget(pic_label);

       DFloatingButton *up_page = new DFloatingButton(DStyle::SP_ArrowLeft, this);
       DFloatingButton *down_page = new DFloatingButton(DStyle::SP_ArrowRight, this);
       DPushButton *ok_set = new DPushButton("设置壁纸");
//       ok_set->setStyleSheet("background-color:blue;color:white");
       QVBoxLayout *frontlayout = new QVBoxLayout(pic_label);
       QHBoxLayout *upview = new QHBoxLayout;
       QHBoxLayout *downview = new QHBoxLayout;
       frontlayout->addStretch(1);
       frontlayout->addLayout(upview);
       upview->addWidget(up_page);
       upview->addStretch(1);
       upview->addWidget(down_page);
       frontlayout->addStretch(1);
       frontlayout->addLayout(downview);
       downview->addStretch(70);
       downview->addWidget(ok_set,Qt::AlignBottom);
       downview->addStretch(70);

       //在标题栏上添加一个菜单/菜单项 Add a menu/menu item to the title bar
       QMenu *menu=new QMenu;
       QAction *action=new QAction("action");
       menu->addAction(action);
       titlebar()->setMenu(menu);

       //设置标题栏上的图标 Set the icon on the title bar
       titlebar()->setIcon(QIcon::fromTheme("deepin-launcher"));

       //让程序适配浅色模式和深色模式 Adapt the program to light and dark model
       connect(DGuiApplicationHelper::instance(), &DGuiApplicationHelper::themeTypeChanged,this,&DtkTntWallpaper::setTheme);
}

DtkTntWallpaper::~DtkTntWallpaper()
{
       delete w;
}

void DtkTntWallpaper::setTheme(DGuiApplicationHelper::ColorType theme)
{
    //这个函数在程序运行之初就会被调用一次，而后每次更换主题颜色时被调用。 This function is called at the beginning of the program and then every time the theme color is changed.
    if(theme==DGuiApplicationHelper::LightType){ //在这个位置设置两种不同的样式 Set two different styles at this location
        //浅色模式 Light Mode
        qDebug()<<"Lighe";
    }else {
        //深色模式 Dark Mode
        qDebug()<<"Dark";
    }
}
