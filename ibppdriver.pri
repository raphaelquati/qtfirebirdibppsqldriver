DEPENDPATH += $$PWD
INCLUDEPATH += $$PWD
HEADERS		+= $$PWD/src/qsql_ibpp.h \
		$$PWD/src/qsqlcachedresult_p.h
SOURCES		+= $$PWD/src/qsql_ibpp.cpp
DEFINES +=   QT_NO_CAST_TO_ASCII \
  QT_NO_CAST_FROM_ASCII
include(../COMMON/ibpp-2-5-2-0/ibpp.pri) # +=   IBPP
contains(QT_CONFIG, reduce_exports):CONFIG+=hide_symbols  # +=   hide_symbols
