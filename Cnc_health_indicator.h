#include <string>

class Cnc_health_idicator
{
	bool _is_temp_within_limits;
	bool _is_part_variation_within_limits;
	bool _is_continuous_operation_within_limits;
	bool _is_startup_successful;

	bool _environment_attention;
	bool _cnc_attentiion;

public:

	void set_temp_status(bool temp_status)
	{
		_is_temp_within_limits = temp_status;
	}

	void set_part_variation_status(bool part_variation_status)
	{
		_is_part_variation_within_limits = part_variation_status;
	}

	void set_contineos_operation_status(bool operation_time_status)
	{
		_is_continuous_operation_within_limits = operation_time_status;
	}

	void set_starup_status(bool startup_status)
	{
		_is_startup_successful = startup_status;
	}

	void update_indication_flag()
	{
		_environment_attention = false;
		_cnc_attentiion = false;

		if (!_is_temp_within_limits)
			_environment_attention = true;

		/*if (!_is_part_variation_within_limits || !_is_continuous_operation_within_limits || !_is_startup_successful)
			_cnc_attentiion = true;*/
	}

	void update_log(std::string log_message)
	{
		//Write to file or Console
	}
};