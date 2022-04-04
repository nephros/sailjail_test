#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    QQmlEngine* engine = view->engine();

    // Note: QML is loaded before we have set appname and organame
    // so they will contain the defaults
    view->setSource(SailfishApp::pathTo(QString("qml/sailjailtest.qml")));
    view->show();

    qInfo() << QStringLiteral("~~~~~ Documentation DEFAULTS ~~~~~");
    qInfo();
    qInfo() << QStringLiteral("DesktopLocation")	<< QStringLiteral("~/Desktop");
    qInfo() << QStringLiteral("DocumentsLocation")	<< QStringLiteral("~/Documents");
    qInfo() << QStringLiteral("FontsLocation")		<< QStringLiteral("~/.fonts, ~/.local/share/fonts, /usr/local/share/fonts, /usr/share/fonts");
    qInfo() << QStringLiteral("ApplicationsLocation")	<< QStringLiteral("~/.local/share/applications, /usr/local/share/applications, /usr/share/applications");
    qInfo() << QStringLiteral("MusicLocation")		<< QStringLiteral("~/Music");
    qInfo() << QStringLiteral("MoviesLocation")		<< QStringLiteral("~/Videos");
    qInfo() << QStringLiteral("PicturesLocation")	<< QStringLiteral("~/Pictures");
    qInfo() << QStringLiteral("TempLocation")		<< QStringLiteral("/tmp");
    qInfo() << QStringLiteral("HomeLocation")		<< QStringLiteral("~");
    qInfo() << QStringLiteral("DataLocation")		<< QStringLiteral("~/.local/share/<APPNAME>, /usr/local/share/<APPNAME>, /usr/share/<APPNAME>");
    qInfo() << QStringLiteral("CacheLocation")		<< QStringLiteral("~/.cache/<APPNAME>");
    qInfo() << QStringLiteral("GenericDataLocation")	<< QStringLiteral("~/.local/share, /usr/local/share, /usr/share");
    qInfo() << QStringLiteral("RuntimeLocation")	<< QStringLiteral("/run/user/<USER>");
    qInfo() << QStringLiteral("ConfigLocation")		<< QStringLiteral("~/.config, /etc/xdg");
    qInfo() << QStringLiteral("GenericConfigLocation")	<< QStringLiteral("~/.config, /etc/xdg");
    qInfo() << QStringLiteral("DownloadLocation")	<< QStringLiteral("~/Downloads");
    qInfo() << QStringLiteral("GenericCacheLocation")	<< QStringLiteral("~/.cache");
    qInfo() << QStringLiteral("AppDataLocation")	<< QStringLiteral("~/.local/share/<APPNAME>, /usr/local/share/<APPNAME>, /usr/share/<APPNAME>");
    qInfo() << QStringLiteral("AppLocalDataLocation")	<< QStringLiteral("~/.local/share/<APPNAME>, /usr/local/share/<APPNAME>, /usr/share/<APPNAME>");
    qInfo() << QStringLiteral("AppConfigLocation")	<< QStringLiteral("~/.config/<APPNAME>, /etc/xdg/<APPNAME>");
    qInfo() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    qInfo();
    qInfo() << "~~~~~ Defaults BEFORE setting appname and organame ~~~~~";
    qInfo();
    qInfo() << QStringLiteral("DesktopLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    qInfo() << QStringLiteral("DocumentsLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    qInfo() << QStringLiteral("FontsLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::FontsLocation);
    qInfo() << QStringLiteral("ApplicationsLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
    qInfo() << QStringLiteral("MusicLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    qInfo() << QStringLiteral("MoviesLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);
    qInfo() << QStringLiteral("PicturesLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    qInfo() << QStringLiteral("TempLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    qInfo() << QStringLiteral("HomeLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    qInfo() << QStringLiteral("DataLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    qInfo() << QStringLiteral("CacheLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::CacheLocation);
    qInfo() << QStringLiteral("GenericDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    qInfo() << QStringLiteral("RuntimeLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::RuntimeLocation);
    qInfo() << QStringLiteral("ConfigLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::ConfigLocation);
    qInfo() << QStringLiteral("GenericConfigLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation);
    qInfo() << QStringLiteral("DownloadLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);
    qInfo() << QStringLiteral("GenericCacheLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericCacheLocation);
    qInfo() << QStringLiteral("AppDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    qInfo() << QStringLiteral("AppLocalDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation);
    qInfo() << QStringLiteral("AppConfigLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);
    qInfo() << "---- LocalStorage ----";
    qInfo() << QStringLiteral("offlineStoragePath")	<<  engine->offlineStoragePath();
    // not in Qt 5.6
    //qInfo() << QStringLiteral("offlineStorageDatabaseFilePath")	<<  engine->offlineStorageDatabaseFilePath(QStringLiteral("SailJailTest"));
    qInfo() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    app->setOrganizationName("OrgaNameFromCpp");
    app->setApplicationName("AppNameFromCpp");
    app->setApplicationVersion("0.9");

    qInfo();
    qInfo() << "~~~~~ Defaults AFTER setting appname and organame ~~~~~";
    qInfo();
    qInfo() << QStringLiteral("DesktopLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    qInfo() << QStringLiteral("DocumentsLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    qInfo() << QStringLiteral("FontsLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::FontsLocation);
    qInfo() << QStringLiteral("ApplicationsLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation);
    qInfo() << QStringLiteral("MusicLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::MusicLocation);
    qInfo() << QStringLiteral("MoviesLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);
    qInfo() << QStringLiteral("PicturesLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    qInfo() << QStringLiteral("TempLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    qInfo() << QStringLiteral("HomeLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    qInfo() << QStringLiteral("DataLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::DataLocation);
    qInfo() << QStringLiteral("CacheLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::CacheLocation);
    qInfo() << QStringLiteral("GenericDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    qInfo() << QStringLiteral("RuntimeLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::RuntimeLocation);
    qInfo() << QStringLiteral("ConfigLocation")		<<  QStandardPaths::standardLocations(QStandardPaths::ConfigLocation);
    qInfo() << QStringLiteral("GenericConfigLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericConfigLocation);
    qInfo() << QStringLiteral("DownloadLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);
    qInfo() << QStringLiteral("GenericCacheLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::GenericCacheLocation);
    qInfo() << QStringLiteral("AppDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    qInfo() << QStringLiteral("AppLocalDataLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation);
    qInfo() << QStringLiteral("AppConfigLocation")	<<  QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation);
    qInfo() << "---- LocalStorage ----";
    qInfo() << QStringLiteral("offlineStoragePath")	<<  engine->offlineStoragePath();
    // not in Qt 5.6
    //qInfo() << QStringLiteral("offlineStorageDatabaseFilePath")	<<  engine->offlineStorageDatabaseFilePath(QStringLiteral("SailJailTest"));
    qInfo() << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    return app->exec();
}

// vim: ts=8 st=4 sw=4
