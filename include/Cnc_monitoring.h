#pragma once

#include "Cnc_alerating.h"
#include <map>

enum class Monitor_indicator{
	TEMP_INDICATOR,
	DRILL_BIT_INDICATOR,
	ON_TIME_INDICATOR,
	STARTUP_INDICATOR
};

class Cnc_monitoring
{
	Cnc_alerating* _alerating;
	std::map<Monitor_indicator, IMonitor*> _indicators;

public:
	
	Cnc_monitoring(Cnc_alerating*);

	void diagnoise(IMonitor* indicator);

	IMonitor* get_monitor_indicator(Monitor_indicator indicator);

	void registor_indicators(Monitor_indicator indicator ,IMonitor* monitor_indicator);

};