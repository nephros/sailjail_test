# sailjail_test

Small demo / testing app for [SailJail](https://github.com/sailfishos/sailjail).

It shows the variaous paths that are influenced by the OrganizationName and ApplicationName.

## How to use

### QML app

Three .desktop files are installed, one without a [Sailjail] section, 
one with the keys `Permissions`, `OrganizationName`, and `ApplicationName` configured, 
and one with `Sandboxing=disabled`.

It shows all the paths present in `Silica.StandardPaths`. (Note that this is NOT `Qt.labs.platform.StandardPaths`!!).
Using a Button you can set/reset `Qt.application.name` and `Qt.application.organization` to new values and see how they affect the paths displayed.

### C++ part

The very basic c++ application starts up the SailfishApp, logs the default paths/locations to console (using `qInfo()`), then calls

    app->setOrganizationName("OrgaNameFromCpp");
    app->setApplicationName("AppNameFromCpp");
    
and again prints the paths/locations.

### Observations

With at least four sources for `OrganizationName` and `setApplicationName` (CPP, QML, the .desktop files), 
plus defaults set by of SailJail when these settings are missing (i.e. defaulting to application binary name), 
getting everything right can be quite confusing.

I.e. using `QStandardPaths::AppDataLocation` or `QStandardPaths::AppLocalDataLocation` 
will show different things depending on what has been initialized from where.

Also, `QQMLEngine::offlineStoragePath` seems to be somewhat independent from the others, probably because comes from the Engine and not the QGUIApplication..
