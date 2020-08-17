#include "IMonitor.h"

class Cnc_alerating
{
	bool _cnc_machine_alert;
	bool _cnc_environment_alert;

public:

	void set_machine_indicator(bool machine_indicator)
	{
		_cnc_machine_alert = machine_indicator;
	}

	bool get_machine_indicator()
	{
		return _cnc_machine_alert;
	}

	void set_environment_indicator(bool environment_indicator)
	{
		_cnc_environment_alert = environment_indicator;
	}

	bool get_environment_indicator()
	{
		return _cnc_environment_alert;
	}
};