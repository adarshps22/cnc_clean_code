class Cnc_data_validator
{

private:
	// temperature in Celcius
	float _temp_upperlimit = 35;

	// variation in mm
	float _variation_lowerlimit = 0;
	float _variation_upperlimit = 0.05;

	//time in minutes
	unsigned int _operation_time_upperlimit = 360;

public:

	bool is_temp_within_limit(float temperature)
	{
		return temperature < _temp_upperlimit;
	}

	bool is_part_variation_within_limits(float variation)
	{
		return variation > _variation_lowerlimit && variation <= _variation_upperlimit;
	}

	bool is_contineous_operation_within_limits(unsigned int time)
	{
		return time < _operation_time_upperlimit;
	}

	bool is_startup_success(unsigned int error_code)
	{
		return (int)Cnc_error_message::error_code::ALL_OK == error_code;
	}
};