TEMPLATE = app
TARGET = sailjailtest
CONFIG += sailfishapp

# run 'qmake CONFIG+=on_device' to test things
on_device {
	message("On Device: skipping Qt module deps, compiling will probably not work.")
	QT -= core gui
	INCLUDEPATH += ${HOME}/devel/fakeinclude/
}

SOURCES += src/$${TARGET}.cpp

desktop.files += $${TARGET}_default.desktop  $${TARGET}_nojail.desktop

OTHER_FILES += $$files(rpm/*) $${TARGET}.qml)
