/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "UnitTest.h"
#include "MockLink.h"
#include "Vehicle.h"

class InitialConnectTest : public UnitTest
{
    Q_OBJECT

signals:
    void resultHandlerCalled(void);
    
private slots:
    void _test(void);

private:
    void _performTestCases(void);
    typedef struct {
        MockLink::RequestMessageFailureMode_t               failureMode;
        MAV_RESULT                                          expectedCommandResult;
        Vehicle::RequestMessageResultHandlerFailureCode_t   expectedFailureCode;
        bool                                                resultHandlerCalled;
    } TestCase_t;

    void _testCaseWorker(TestCase_t& testCase);

    static void _requestMessageResultHandler(void* resultHandlerData, MAV_RESULT commandResult, Vehicle::RequestMessageResultHandlerFailureCode_t failureCode, const mavlink_message_t& message);

    bool _resultHandlerCalled;

    static TestCase_t _rgTestCases[];
};
