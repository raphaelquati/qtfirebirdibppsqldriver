/*
* This file is part of QtFirebirdIBPPSQLDriver - Qt SQL driver for Firebird with IBPP library
* Copyright (C) 2006-2010 Alex Wencel
*
* Contact e-mail: Alex Wencel <alex.wencel@gmail.com>
* Program URL   : http://code.google.com/p/qtfirebirdibppsqldriver
*
* GNU Lesser General Public License Usage
* This file may be used under the terms of the GNU Lesser
* General Public License version 2.1 as published by the Free Software
* Foundation and appearing in the file LICENSE.LGPL included in the
* packaging of this file.  Please review the following information to
* ensure the GNU Lesser General Public License version 2.1 requirements
* will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
*
* GNU General Public License Usage
* Alternatively, this file may be used under the terms of the GNU
* General Public License version 3.0 as published by the Free Software
* Foundation and appearing in the file LICENSE.GPL included in the
* packaging of this file.  Please review the following information to
* ensure the GNU General Public License version 3.0 requirements will be
* met: http://www.gnu.org/copyleft/gpl.html.
*
*/

#include <qstringlist.h>
#include "qsql_ibpp.h"

QT_BEGIN_NAMESPACE
QFBDriverPlugin::QFBDriverPlugin()
    : QSqlDriverPlugin()
{
}

QSqlDriver* QFBDriverPlugin::create(const QString &name)
{
    if (name == QLatin1String("QFIREBIRD")) {
        QFBDriver* driver = new QFBDriver();
        return driver;
    }
    return 0;
}

QStringList QFBDriverPlugin::keys() const
{
    QStringList l;
    l  << QLatin1String("QFIREBIRD");
    return l;
}
QT_END_NAMESPACE
//Q_EXPORT_STATIC_PLUGIN(QFBDriverPlugin)
//Q_EXPORT_PLUGIN2(qsqlfb, QFBDriverPlugin)

