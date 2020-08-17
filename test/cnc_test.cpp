#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Temperature_monitor.h"
#include "Drill_bit.h"
#include "Cnc_on_time.h"
#include "Cnc_monitoring.h"
#include "Cnc_start_up.h"

Cnc_alerating* alert = new Cnc_alerating();
Cnc_monitoring* monitor;

void clear_status()
{
    alert->set_environment_indicator(false);
    alert->set_machine_indicator(false);
}

void registering()
{
    monitor->registor_indicators(Monitor_indicator::TEMP_INDICATOR, new Temperature_monitor());
    monitor->registor_indicators(Monitor_indicator::DRILL_BIT_INDICATOR, new Drill_bit());
    monitor->registor_indicators(Monitor_indicator::STARTUP_INDICATOR, new Cnc_start_up());
    monitor->registor_indicators(Monitor_indicator::ON_TIME_INDICATOR, new Cnc_on_time());
}

void setup_gtest()
{
    monitor = new Cnc_monitoring(alert);
    registering();
}

TEST(MONITOR_INDICATOR, Temperature_monitor_inlimits)
{    
    clear_status();
    auto temp_indicator = monitor->get_monitor_indicator(Monitor_indicator::TEMP_INDICATOR);
    ((Temperature_monitor*)temp_indicator)->set_temperature(15.0);
    
    monitor->diagnoise(temp_indicator);
    ASSERT_FALSE(alert->get_environment_indicator());
}

TEST(MONITOR_INDICATOR, Temperature_monitor_not_inlimits)
{
    clear_status();
    auto temp_indicator = monitor->get_monitor_indicator(Monitor_indicator::TEMP_INDICATOR);
    ((Temperature_monitor*)temp_indicator)->set_temperature(45.0);

    monitor->diagnoise(temp_indicator);
    ASSERT_TRUE(alert->get_environment_indicator());
}

TEST(MONITOR_INDICATOR, DrillBit_monitor_inlimits)
{
    clear_status();
    auto drillbit_indicator = monitor->get_monitor_indicator(Monitor_indicator::DRILL_BIT_INDICATOR);
    ((Drill_bit*)drillbit_indicator)->set_drill_bit_variation(0.001);

    monitor->diagnoise(drillbit_indicator);
    ASSERT_FALSE(alert->get_machine_indicator());
}

TEST(MONITOR_INDICATOR, DrillBit_monitor_not_inlimits)
{
    clear_status();
    auto drillbit_indicator = monitor->get_monitor_indicator(Monitor_indicator::DRILL_BIT_INDICATOR);
    ((Drill_bit*)drillbit_indicator)->set_drill_bit_variation(0.1);

    monitor->diagnoise(drillbit_indicator);
    ASSERT_TRUE(alert->get_machine_indicator());
}

TEST(MONITOR_INDICATOR, OnTime_monitor_inlimits)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::ON_TIME_INDICATOR);
    ((Cnc_on_time*)ontime_indicator)->set_on_time(100);

    monitor->diagnoise(ontime_indicator);
    ASSERT_FALSE(alert->get_machine_indicator());
}

TEST(MONITOR_INDICATOR, OnTime_monitor_not_inlimits)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::ON_TIME_INDICATOR);
    ((Cnc_on_time*)ontime_indicator)->set_on_time(1000);

    monitor->diagnoise(ontime_indicator);
    ASSERT_TRUE(alert->get_machine_indicator());
}

TEST(MONITOR_INDICATOR, Startup_monitor_allok)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::STARTUP_INDICATOR);
    ((Cnc_start_up*)ontime_indicator)->set_startup_status(0xff);

    monitor->diagnoise(ontime_indicator);
    ASSERT_FALSE(alert->get_machine_indicator());
    ASSERT_FALSE(alert->get_environment_indicator());
}

TEST(MONITOR_INDICATOR, Startup_monitor_no_data)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::STARTUP_INDICATOR);
    ((Cnc_start_up*)ontime_indicator)->set_startup_status(0x00);

    monitor->diagnoise(ontime_indicator);
    ASSERT_TRUE(alert->get_machine_indicator());
    ASSERT_FALSE(alert->get_environment_indicator());
}

TEST(MONITOR_INDICATOR, Startup_monitor_cb_error)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::STARTUP_INDICATOR);
    ((Cnc_start_up*)ontime_indicator)->set_startup_status(0x01);

    monitor->diagnoise(ontime_indicator);
    ASSERT_FALSE(alert->get_machine_indicator());
    ASSERT_TRUE(alert->get_environment_indicator());
}

TEST(MONITOR_INDICATOR, Startup_monitor_data_corrupt)
{
    clear_status();
    auto ontime_indicator = monitor->get_monitor_indicator(Monitor_indicator::STARTUP_INDICATOR);
    ((Cnc_start_up*)ontime_indicator)->set_startup_status(0x02);

    monitor->diagnoise(ontime_indicator);
    ASSERT_TRUE(alert->get_machine_indicator());
    ASSERT_FALSE(alert->get_environment_indicator());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    setup_gtest();
    return RUN_ALL_TESTS();
}