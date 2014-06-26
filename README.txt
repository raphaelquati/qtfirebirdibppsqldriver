    QtFirebirdIBPPSQLDriver - Qt SQL driver for Firebird with IBPP library

    (C) 2006-2010 Alex Wencel <alex.wencel@gmail.com>

Installation
~~~~~~~~~~~

Download is available from http://code.google.com/p/qtfirebirdibppsqldriver/, the official website.

You need :
- Qt (from Nokia) at least version 4.* to be able to compile QtFirebirdIBPPSQLDriver.
- IBPP, a C++ Client Interface to Firebird Server. http://www.ibpp.org
- Firebird  at least version 1.5.*. http://firebirdsql.org

The simplest way to compile (QtFirebirdIBPPSQLDriver) package is:

1. Extract the source zip.
2. Copy IBPP source code to project/ibpp* dir, 
   or copy ibpp.pri file to IBPP dir and change IbppDriver.pro project file 
   in line contains "include(./ibpp2531/ibpp.pri)" 
3. Copy Firebird library file (fbclient.lib for Win) to project/lib dir, 
   and change ibpp.pri project file.
4. qmake in project directory.
3. Type `make' on Linux or `mingw32-make` on Windows to compile the package.
4. Copy drivers to Qt Sql plugins dir.


Documentation
~~~~~~~~~~~~~

The format of the options string is a semicolon separated list of option=value pairs.
	CHARSET - character set
	ROLE - role name

// QFIREBIRD connection
	db.setConnectOptions("CHARSET=WIN1251;ROLE=ROOT");
.........

License
~~~~~~~~~~~~~

Copyright (C) 2006-2010 Alex Wencel

Contact e-mail: Alex Wencel <alex.wencel@gmail.com>
Program URL   : http://code.google.com/p/qtfirebirdibppsqldriver

GNU Lesser General Public License Usage
This file may be used under the terms of the GNU Lesser
General Public License version 2.1 as published by the Free Software
Foundation and appearing in the file LICENSE.LGPL included in the
packaging of this file.  Please review the following information to
ensure the GNU Lesser General Public License version 2.1 requirements
will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.

GNU General Public License Usage
Alternatively, this file may be used under the terms of the GNU
General Public License version 3.0 as published by the Free Software
Foundation and appearing in the file LICENSE.GPL included in the
packaging of this file.  Please review the following information to
ensure the GNU General Public License version 3.0 requirements will be
met: http://www.gnu.org/copyleft/gpl.html.
