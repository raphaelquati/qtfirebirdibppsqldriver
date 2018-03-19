
DEPENDPATH += $$PWD/core
INCLUDEPATH += $$PWD/core
HEADERS		+= $$PWD/core/ibpp.h
SOURCES		+= $$PWD/core/all_in_one.cpp

unix{
  LIBS += -lfbclient -L./lib
  DEFINES += IBPP_LINUX \
  IBPP_GCC
}
win32{
#  LIBS += -L$$PWD/../lib -lfbclient_ms -ladvapi32
  DEFINES += IBPP_WINDOWS
}

