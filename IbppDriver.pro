CONFIG += qt \
    plugin
QT += core \
    sql
DEFINES	-= UNICODE
QT -= gui # -=   GUI
TEMPLATE = lib
TARGET = qsqlfb

DEFINES += QT_NO_CAST_TO_ASCII \
    QT_NO_CAST_FROM_ASCII
HEADERS += src/qsql_ibpp.h \
    src/qsqlcachedresult_p.h
SOURCES += src/main.cpp \
    src/qsql_ibpp.cpp
include(./ibpp2531/ibpp.pri) # +=   IBPP
contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols  # +=   hide_symbols

target.path     += $$[QT_INSTALL_PLUGINS]/sqldrivers
INSTALLS        += target

PLUGIN_CLASS_NAME = QFBDriverPlugin

OTHER_FILES += \
    ChangeLog.txt \
    LICENSE \
    LICENSE.GPL3 \
    LICENSE.LGPL \
    README.md \
    README.txt \
	sqlfb.json
