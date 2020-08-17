#include "IMonitor.h"

class Temperature_monitor : public IMonitor
{
	float _temp_celcius;
	float _ref_temp_celcius = 35.0;

public:

	void set_temperature(float temp)
	{
		_temp_celcius = temp;
	}

	float get_temperature()
	{
		return _temp_celcius;
	}

	bool diagnosis()
	{
		auto status = _temp_celcius > _ref_temp_celcius;
		
		set_environment_indicator(status);
		return status;
	}
};