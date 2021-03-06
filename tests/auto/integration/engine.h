/****************************************************************************
**
** Copyright (C) 2014 Ford Motor Company
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtRemoteObjects module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TESTS_ENGINE_H
#define TESTS_ENGINE_H

#include "rep_engine_source.h"

class Engine : public EngineSimpleSource
{
    Q_OBJECT
    Q_PROPERTY(bool purchasedPart READ purchasedPart WRITE setpurchasedPart)

public:
    Engine(QObject *parent=Q_NULLPTR);
    virtual ~Engine();

    bool start() Q_DECL_OVERRIDE;
    void increaseRpm(int deltaRpm) Q_DECL_OVERRIDE;

    void unnormalizedSignature(int, int) Q_DECL_OVERRIDE {}

    Temperature temperature() Q_DECL_OVERRIDE;
    void setTemperature(const Temperature &value);

    void setSharedTemperature(const Temperature::Ptr &) Q_DECL_OVERRIDE {}

    bool purchasedPart() {return _purchasedPart;}

public Q_SLOTS:
    void setpurchasedPart(bool value);

    QString myTestString() Q_DECL_OVERRIDE { return _myTestString; }
    void setMyTestString(QString value) Q_DECL_OVERRIDE { _myTestString = value; }

private:
    bool _purchasedPart;
    QString _myTestString;
    Temperature _temperature;
};

#endif
