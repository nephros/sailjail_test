# sailjail_test

Small demo / testing app for [SailJail](https://github.com/sailfishos/sailjail).

It shows the variaous paths that are influenced by the OrganizationName and ApplicationName.

## How to use

Basically, launch the application(s), and observe their output at the console (in the Info channel).

### C++ part

See (https://github.com/nephros/sailjail_test/blob/master/src/sailjailtest.cpp).

The very basic c++ application starts up the SailfishApp, logs the default
paths/locations to console (using `qInfo()`), then sets orga and app names, and again prints the paths/locations.

So:

    SailfishApp::application(argc, argv)
    SailfishApp::createView()
    view->setSource("qml/sailjailtest.qml")

    print_paths()

    setOrganizationName("OrgaNameFromCpp")
    setApplicationName("AppNameFromCpp")

    print_paths()

    exec()

### QML app

Three .desktop files are installed, one without a [Sailjail] section, 
one with the keys `Permissions`, `OrganizationName`, and `ApplicationName` configured, 
and one with `Sandboxing=disabled`.

It shows all the paths present in `Silica.StandardPaths`. (Note that this is NOT `Qt.labs.platform.StandardPaths`!!).
Using a Button you can set/reset `Qt.application.name` and `Qt.application.organization` to new values and see how they affect the paths displayed.

### Observations

With at least four sources for `OrganizationName` and `ApplicationName` (CPP, QML, the .desktop files, 
plus defaults set by of SailJail when these settings are missing (i.e. defaulting to application binary name), 
getting everything right can be quite confusing.

I.e. using `QStandardPaths::AppDataLocation` or `QStandardPaths::AppLocalDataLocation` 
will show different things depending on what has been initialized from where.

Or the fact that the QML page will show one set of OrgaName/AppName pair, in
the Title, while `Sailfish::Silica::StandardPaths.cache` will show another.

Also, `QQMLEngine::offlineStoragePath` seems to be somewhat independent from
the others, probably because comes from the Engine and not the QGUIApplication.

#### ExampleOutput snippets:

Launching binary from command line:
Note that setting the names in CPP makes `StandardPaths` follow, but not `offlineStoragePath`

    [I] unknown:0 - ~~~~~ Defaults BEFORE setting appname and organame ~~~~~
    
    [I] unknown:0 - "AppDataLocation" ("/home/defaultuser/.local/share/OrgaNameFromDesktop/AppNameFromDesktop", "/usr/local/share/OrgaNameFromDesktop/AppNameFromDesktop", "/usr/share/OrgaNameFromDesktop/AppNameFromDesktop")
    [I] unknown:0 - "AppLocalDataLocation" ("/home/defaultuser/.local/share/OrgaNameFromDesktop/AppNameFromDesktop", "/usr/local/share/OrgaNameFromDesktop/AppNameFromDesktop", "/usr/share/OrgaNameFromDesktop/AppNameFromDesktop")
    [I] unknown:0 - "AppConfigLocation" ("/home/defaultuser/.config/OrgaNameFromDesktop/AppNameFromDesktop", "/etc/xdg/OrgaNameFromDesktop/AppNameFromDesktop")
    [I] unknown:0 - ---- LocalStorage ----
    [I] unknown:0 - "offlineStoragePath" "/home/defaultuser/.local/share/OrgaNameFromDesktop/AppNameFromDesktop/QML/OfflineStorage"
    [I] unknown:0 - ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    [I] unknown:0 -
    [I] unknown:0 - ~~~~~ Defaults AFTER setting appname and organame ~~~~~
    
    [I] unknown:0 - "AppDataLocation" ("/home/defaultuser/.local/share/OrgaNameFromCpp/AppNameFromCpp", "/usr/local/share/OrgaNameFromCpp/AppNameFromCpp", "/usr/share/OrgaNameFromCpp/AppNameFromCpp")
    [I] unknown:0 - "AppLocalDataLocation" ("/home/defaultuser/.local/share/OrgaNameFromCpp/AppNameFromCpp", "/usr/local/share/OrgaNameFromCpp/AppNameFromCpp", "/usr/share/OrgaNameFromCpp/AppNameFromCpp")
    [I] unknown:0 - "AppConfigLocation" ("/home/defaultuser/.config/OrgaNameFromCpp/AppNameFromCpp", "/etc/xdg/OrgaNameFromCpp/AppNameFromCpp")
    [I] unknown:0 - ---- LocalStorage ----
    [I] unknown:0 - "offlineStoragePath" "/home/defaultuser/.local/share/OrgaNameFromDesktop/AppNameFromDesktop/QML/OfflineStorage"


