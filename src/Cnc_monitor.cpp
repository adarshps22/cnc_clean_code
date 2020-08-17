#include "Cnc_monitoring.h"

Cnc_monitoring::Cnc_monitoring(Cnc_alerating* cnc_alert)
{
	this->_alerating = cnc_alert;
}

void Cnc_monitoring::diagnoise(IMonitor* monitor)
{
	monitor->diagnosis();
	_alerating->set_environment_indicator(monitor->get_environment_indicator());
	_alerating->set_machine_indicator(monitor->get_machine_indicator());
}

void Cnc_monitoring::registor_indicators(Monitor_indicator indicator, IMonitor* monitor_indicator)
{
	if (_indicators.find(indicator) == _indicators.end())
	{
		_indicators.emplace(indicator, monitor_indicator);
	}
}

IMonitor* Cnc_monitoring::get_monitor_indicator(Monitor_indicator indicator)
{
	auto monitor_indicator = _indicators.find(indicator);
	if (monitor_indicator == _indicators.end())
	{
		return nullptr;
	}
	else
	{
		return monitor_indicator->second;
	}
}