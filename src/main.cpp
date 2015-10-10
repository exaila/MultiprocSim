#include <QApplication>
#include "Mainwindow.h"
#include "helper.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    RandomInitialize();

    MainWindow mw(NULL);
    app.setActiveWindow(&mw);
    mw.show();

    return app.exec();
}
