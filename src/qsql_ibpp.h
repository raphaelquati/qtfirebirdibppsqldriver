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
#include <qsqldriverplugin.h>
#include <QtSql/private/qsqlcachedresult_p.h>

QT_BEGIN_HEADER
class QFBDriverPrivate;
class QFBResultPrivate;
class QFBDriver;
class QTextCodec;

class QFBDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QSqlDriverFactoryInterface" FILE "sqlfb.json")

public:
    QFBDriverPlugin();

    QSqlDriver* create(const QString &);
    QStringList keys() const;
};

class QFBResult : public QSqlCachedResult
{
    Q_DECLARE_PRIVATE(QFBResult)

public:
    explicit QFBResult(const QFBDriver *db, QTextCodec *tc);
    virtual ~QFBResult();

    bool prepare(const QString& query) Q_DECL_OVERRIDE;
    bool exec() Q_DECL_OVERRIDE;
    QVariant handle() const Q_DECL_OVERRIDE;

protected:
    bool gotoNext(QSqlCachedResult::ValueCache& row, int rowIdx) Q_DECL_OVERRIDE;
    bool reset (const QString& query) Q_DECL_OVERRIDE;
    int size() Q_DECL_OVERRIDE;
    bool isNull(int field) Q_DECL_OVERRIDE;
    int numRowsAffected() Q_DECL_OVERRIDE;
    QSqlRecord record() const Q_DECL_OVERRIDE;
};

class QSqlResult;

class QFBDriver : public QSqlDriver
{
    friend class QFBResultPrivate;
    Q_DECLARE_PRIVATE(QFBDriver)
    Q_OBJECT
public:
    explicit QFBDriver(QObject *parent = nullptr);
    explicit QFBDriver(void *connection, QObject *parent = nullptr);
    virtual ~QFBDriver();
    bool hasFeature(DriverFeature f) const Q_DECL_OVERRIDE;
    bool open(const QString & db,
                   const QString & user,
                   const QString & password,
                   const QString & host,
                   int port,
                   const QString & connOpts);
    bool open(const QString &db,
            const QString &user,
            const QString &password,
            const QString &host,
            int port) { return open(db, user, password, host, port, QString()); }
    void close() Q_DECL_OVERRIDE;
    QSqlResult *createResult() const Q_DECL_OVERRIDE;
    bool beginTransaction() Q_DECL_OVERRIDE;
    bool commitTransaction() Q_DECL_OVERRIDE;
    bool rollbackTransaction() Q_DECL_OVERRIDE;
    QStringList tables(QSql::TableType) const Q_DECL_OVERRIDE;

    QSqlRecord record(const QString& tablename) const Q_DECL_OVERRIDE;
    QSqlIndex primaryIndex(const QString &table) const Q_DECL_OVERRIDE;

    QString formatValue(const QSqlField &field, bool trimStrings) const Q_DECL_OVERRIDE;
    QVariant handle() const Q_DECL_OVERRIDE;

//TODO
//    QString escapeIdentifier(const QString &identifier, IdentifierType type) const Q_DECL_OVERRIDE;

//    bool subscribeToNotification(const QString &name) Q_DECL_OVERRIDE;
//    bool unsubscribeFromNotification(const QString &name) Q_DECL_OVERRIDE;
//    QStringList subscribedToNotifications() const Q_DECL_OVERRIDE;

//private Q_SLOTS:
//    void qHandleEventNotification(void* updatedResultBuffer);
//OLD
//private:
//    QFBDriverPrivate* dp;
};

QT_END_HEADER
#endif // QSQL_FB_H
