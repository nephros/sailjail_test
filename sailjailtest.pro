TEMPLATE = app
TARGET = sailjailtest
VERSION = 0.9.0
INCLUDEPATH += .
CONFIG += sailfishapp
#QT -= gui core

SOURCES += sailjailtest.cpp

extra_desktop.path += /usr/share/applications
extra_desktop.files +=  $((TARGET)).desktop $((TARGET))_default.desktop  $((TARGET))_nojail.desktop

INSTALLS += extra_desktop

OTHER_FILES += $$files(rpm/*)
