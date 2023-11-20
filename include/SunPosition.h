// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include <TaskSchedulerDeclarations.h>
#include <atomic>
#include <sunset.h>

class SunPositionClass {
public:
    SunPositionClass();
    void init(Scheduler* scheduler);

    bool isDayPeriod();
    bool isSunsetAvailable();
    bool sunsetTime(struct tm* info);
    bool sunriseTime(struct tm* info);
    void setDoRecalc(bool doRecalc);

private:
    void loop();
    void updateSunData();
    bool checkRecalcDayChanged();
    bool getSunTime(struct tm* info, uint32_t offset);

    Task _loopTask;

    bool _isSunsetAvailable = true;
    uint32_t _sunriseMinutes = 0;
    uint32_t _sunsetMinutes = 0;

    bool _isValidInfo = false;
    std::atomic_bool _doRecalc = true;
    uint32_t _lastSunPositionCalculatedYMD = 0;
};

extern SunPositionClass SunPosition;
