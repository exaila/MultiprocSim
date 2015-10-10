# Add more folders to ship with the application, here
folder_01.source = qml/SingleProc
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xED884A66

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# Add dependency to Symbian components
# CONFIG += qt-components

OTHER_FILES += \
    resources/c.png \
    resources/b.png \
    resources/a.png

RESOURCES += \
    images.qrc

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += src/main.cpp \
    src/Mainwindow.cpp \
    src/cachemapper.cpp \
    src/ram.cpp \
    src/resetdialog.cpp \
    src/instruction.cpp \
    src/codelist.cpp \
    src/instructionprogressdelegate.cpp \
    src/ramdelegate.cpp \
    src/parser.cpp \
    src/cache.cpp \
    src/concreteInstructions.cpp \
    src/coreState.cpp \
    src/helper.cpp \
    src/instructionState.cpp \
    src/simulatedSystem.cpp \
    src/parsererror.cpp \
    src/aboutdialog.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    src/Mainwindow.h \
    src/cachemapper.h \
    src/ram.h \
    src/resetdialog.h \
    src/instruction.h \
    src/codelist.h \
    src/instructionprogressdelegate.h \
    src/ramdelegate.h \
    src/parser.h \
    src/cache.h \
    src/concreteInstructions.h \
    src/coreState.h \
    src/enums.h \
    src/helper.h \
    src/instructionState.h \
    src/simulatedSystem.h \
    src/parsererror.h \
    src/aboutdialog.h

FORMS += \
    forms/Mainwindow.ui \
    forms/resetdialog.ui \
    forms/aboutdialog.ui

