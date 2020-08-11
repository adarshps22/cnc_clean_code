class Cnc_diagnosis
{
	Cnc_data_monitor _data_monitor;
	Cnc_data_validator _data_validator;
	Cnc_error_message _cnc_error_message;
	Cnc_health_idicator _health_indicator;

public:

	void temperature_diagnosis()
	{
		auto temperature = _data_monitor.get_operating_tempature();
		auto status = _data_validator.is_temp_within_limit(temperature);
		_health_indicator.set_temp_status(status);

		std::string diag_log = "Current temperature : " + std::to_string(temperature);
		_health_indicator.update_log(diag_log);
	}

	void part_variation_diagnosis()
	{
		auto variation = _data_monitor.get_part_dimension_variation();
		auto status = _data_validator.is_part_variation_within_limits(variation);
		_health_indicator.set_part_variation_status(status);

		std::string diag_log = "part variation : " + std::to_string(variation);
		_health_indicator.update_log(diag_log);
	}

	void continuous_operation_diagnosis()
	{
		auto continuous_operation = _data_monitor.get_contineous_operation();
		auto status = _data_validator.is_contineous_operation_within_limits(continuous_operation);
		_health_indicator.set_contineos_operation_status(status);

		std::string diag_log = "continuous operation time : " + std::to_string(continuous_operation);
		_health_indicator.update_log(diag_log);
	}

	void startup_diagnosis()
	{
		auto error_code = _data_monitor.get_status_code();

		auto status = _data_validator.is_part_variation_within_limits(error_code);
		_health_indicator.set_starup_status(status);

		std::string diag_log = " temperature : " + _cnc_error_message.get_error_message(error_code);
		_health_indicator.update_log(diag_log);
	}

	void update_all_status()
	{
		_health_indicator.update_indication_flag();
	}

};