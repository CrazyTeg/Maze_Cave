TEMPLATE = app
TARGET = Maze
INCLUDEPATH += .

QT += gui core widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += ../src/controller/controller.h \
           ../src/model/cave.h \
           ../src/model/matrix.h \
           ../src/model/maze.h \
           ../src/model/pacman.h \
           ../src/view/cavearea.h \
           ../src/view/cavewindow.h \
           ../src/view/mainwindow.h \
           ../src/view/mazearea.h \
           ../src/view/ui_cavewindow.h \
           ../src/view/ui_mainwindow.h
SOURCES += ../src/main.cpp \
           ../src/model/cave.cc \
           ../src/model/maze_gegerator.cc \
           ../src/model/matrix.cc \
           ../src/model/maze.cc \
           ../src/model/pacman.cc \
           ../src/view/cavearea.cc \
           ../src/view/cavewindow.cc \
           ../src/view/mainwindow.cpp \
           ../src/view/mazearea.cc \

DEFINES += USER_APP=\\\"$(HOME)/Applications/Maze/\\\"

ICON = ../src/icon.icns
