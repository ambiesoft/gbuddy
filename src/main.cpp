#include <QApplication>
#include "../../lsMisc/stdQt/ambapp.h"

#include "mainwindow.h"
#include "consts.h"
#include "globals.h"
#include "optiondialog.h"

using namespace AmbiesoftQt;
using namespace Consts;

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName(ORGANIZATION);
    QCoreApplication::setOrganizationDomain(APPDOMAIN);
    QCoreApplication::setApplicationName(APPNAME);
    QCoreApplication::setApplicationVersion(APPVERSION);

    AmbApp::AmbAppArgs args;
    args.keyLanguage = KEY_LANGUAGE;
    args.keyStyle = KEY_STYLE;
    AmbApp app(argc, argv, args);

    QScopedPointer<IniSettings> settings;
    app.InitApplication(&settings);
    gSettings = settings.get();
    Q_ASSERT(gSettings);

    OptionDialog optionDialog;
    gpOptionDialog = &optionDialog;
    MainWindow w;
    w.show();
    return app.exec();
}
