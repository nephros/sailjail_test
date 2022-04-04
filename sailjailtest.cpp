#include <QtQuick>
#include <QDebug>
#include <sailfishapp.h>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    view->setSource(SailfishApp::pathTo(QString("qml/sailjailtest.qml")));
    view->show();

    qInfo() << "~~~~~ Documentation DEFAULTS ~~~~~";
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

    qInfo() << "~~~~~ DEFAULTS ~~~~~";
    qInfo() << QStringLiteral("DesktopLocation")	<< QStandardPaths::DesktopLocation;
    qInfo() << QStringLiteral("DocumentsLocation")	<< QStandardPaths::DocumentsLocation;
    qInfo() << QStringLiteral("FontsLocation")		<< QStandardPaths::FontsLocation;
    qInfo() << QStringLiteral("ApplicationsLocation")	<< QStandardPaths::ApplicationsLocation;
    qInfo() << QStringLiteral("MusicLocation")		<< QStandardPaths::MusicLocation;
    qInfo() << QStringLiteral("MoviesLocation")		<< QStandardPaths::MoviesLocation;
    qInfo() << QStringLiteral("PicturesLocation")	<< QStandardPaths::PicturesLocation;
    qInfo() << QStringLiteral("TempLocation")		<< QStandardPaths::TempLocation;
    qInfo() << QStringLiteral("HomeLocation")		<< QStandardPaths::HomeLocation;
    qInfo() << QStringLiteral("DataLocation")		<< QStandardPaths::DataLocation;
    qInfo() << QStringLiteral("CacheLocation")		<< QStandardPaths::CacheLocation;
    qInfo() << QStringLiteral("GenericDataLocation")	<< QStandardPaths::GenericDataLocation;
    qInfo() << QStringLiteral("RuntimeLocation")	<< QStandardPaths::RuntimeLocation;
    qInfo() << QStringLiteral("ConfigLocation")		<< QStandardPaths::ConfigLocation;
    qInfo() << QStringLiteral("GenericConfigLocation")	<< QStandardPaths::GenericConfigLocation;
    qInfo() << QStringLiteral("DownloadLocation")	<< QStandardPaths::DownloadLocation;
    qInfo() << QStringLiteral("GenericCacheLocation")	<< QStandardPaths::GenericCacheLocation;
    qInfo() << QStringLiteral("AppDataLocation")	<< QStandardPaths::AppDataLocation;
    qInfo() << QStringLiteral("AppLocalDataLocation")	<< QStandardPaths::AppLocalDataLocation;
    qInfo() << QStringLiteral("AppConfigLocation")	<< QStandardPaths::AppConfigLocation;

    app->setOrganizationName("org.nephros.sailfish"); // needed for Sailjail
    app->setApplicationName("SailJailTest");
    app->setApplicationVersion("0.9");

    qInfo() << "~~~~~ OrgaName and AppName set DEFAULTS ~~~~~";
    qInfo() << QStringLiteral("DesktopLocation")	<< QStandardPaths::DesktopLocation;
    qInfo() << QStringLiteral("DocumentsLocation")	<< QStandardPaths::DocumentsLocation;
    qInfo() << QStringLiteral("FontsLocation")		<< QStandardPaths::FontsLocation;
    qInfo() << QStringLiteral("ApplicationsLocation")	<< QStandardPaths::ApplicationsLocation;
    qInfo() << QStringLiteral("MusicLocation")		<< QStandardPaths::MusicLocation;
    qInfo() << QStringLiteral("MoviesLocation")		<< QStandardPaths::MoviesLocation;
    qInfo() << QStringLiteral("PicturesLocation")	<< QStandardPaths::PicturesLocation;
    qInfo() << QStringLiteral("TempLocation")		<< QStandardPaths::TempLocation;
    qInfo() << QStringLiteral("HomeLocation")		<< QStandardPaths::HomeLocation;
    qInfo() << QStringLiteral("DataLocation")		<< QStandardPaths::DataLocation;
    qInfo() << QStringLiteral("CacheLocation")		<< QStandardPaths::CacheLocation;
    qInfo() << QStringLiteral("GenericDataLocation")	<< QStandardPaths::GenericDataLocation;
    qInfo() << QStringLiteral("RuntimeLocation")	<< QStandardPaths::RuntimeLocation;
    qInfo() << QStringLiteral("ConfigLocation")		<< QStandardPaths::ConfigLocation;
    qInfo() << QStringLiteral("GenericConfigLocation")	<< QStandardPaths::GenericConfigLocation;
    qInfo() << QStringLiteral("DownloadLocation")	<< QStandardPaths::DownloadLocation;
    qInfo() << QStringLiteral("GenericCacheLocation")	<< QStandardPaths::GenericCacheLocation;
    qInfo() << QStringLiteral("AppDataLocation")	<< QStandardPaths::AppDataLocation;
    qInfo() << QStringLiteral("AppLocalDataLocation")	<< QStandardPaths::AppLocalDataLocation;
    qInfo() << QStringLiteral("AppConfigLocation")	<< QStandardPaths::AppConfigLocation;

    //return app->exec();
    app->quit();
    return 0;
}

// vim: ts=8 st=4 sw=4
