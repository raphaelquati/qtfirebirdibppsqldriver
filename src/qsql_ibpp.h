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

#ifndef QSQL_FB_H
#define QSQL_FB_H

#include <QtSql/qsqlresult.h>
#include <QtSql/qsqldriver.h>
#include "qsqlcachedresult_p.h"

QT_BEGIN_HEADER
class QFBDriverPrivate;
class QFBResultPrivate;
class QFBDriver;
class QTextCodec;

class QFBResult : public QSqlCachedResult
{
    friend class QFBResultPrivate;

public:
    explicit QFBResult(const QFBDriver *db, QTextCodec *tc);
    virtual ~QFBResult();

    bool prepare(const QString& query);
    bool exec();
    QVariant handle() const;

protected:
    bool gotoNext(QSqlCachedResult::ValueCache& row, int rowIdx);
    bool reset (const QString& query);
    int size();
    int numRowsAffected();
    QSqlRecord record() const;

private:
    QFBResultPrivate* rp;
};

class QFBDriver : public QSqlDriver
{
    friend class QFBDriverPrivate;
    friend class QFBResultPrivate;
public:
    explicit QFBDriver(QObject *parent = 0);
    explicit QFBDriver(void *connection, QObject *parent = 0);
    virtual ~QFBDriver();
    bool hasFeature(DriverFeature f) const;
    bool open(const QString & db,
                   const QString & user,
                   const QString & password,
                   const QString & host,
                   int port,
                   const QString & connOpts);
    bool open(const QString & db,
            const QString & user,
            const QString & password,
            const QString & host,
            int port)
        { return open (db, user, password, host, port, QString()); }
    void close();
    QSqlResult *createResult() const;
    bool beginTransaction();
    bool commitTransaction();
    bool rollbackTransaction();
    QStringList tables(QSql::TableType) const;

    QSqlRecord record(const QString& tablename) const;
    QSqlIndex primaryIndex(const QString &table) const;

    QString formatValue(const QSqlField &field, bool trimStrings) const;
    QVariant handle() const;

private:
    QFBDriverPrivate* dp;
};

QT_END_HEADER
#endif // QSQL_FB_H
