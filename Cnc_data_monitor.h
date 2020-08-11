class Cnc_data_monitor
{

private:

	float _operating_tempature;
	float _part_dimension_variation;
	unsigned int _contineous_opration;
	unsigned int _status_code;

public:

	void set_operating_tempature(float temparature)
	{
		_operating_tempature = temparature;
	}

	void set_part_dimension_variation(float variation)
	{
		_part_dimension_variation = variation;
	}

	void set_contineous_operation(unsigned int contineous_operation)
	{
		_contineous_opration = contineous_operation;
	}

	void set_status_code(unsigned int status_code)
	{
		_status_code = status_code;
	}

	float get_operating_tempature()
	{
		return _operating_tempature;
	}

	float get_part_dimension_variation()
	{
		return _part_dimension_variation;
	}

	unsigned int get_contineous_operation()
	{
		return _contineous_opration;
	}

	unsigned int get_status_code()
	{
		return _status_code;
	}

};