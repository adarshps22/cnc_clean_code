#pragma once 

class IMonitor
{
	bool _machine_indicator = false;
	bool _environment_indicator = false;

public:
	virtual bool diagnosis() = 0;

	void set_machine_indicator(bool machine_indicator)
	{
		_machine_indicator = machine_indicator;
	}

	bool get_machine_indicator()
	{
		return _machine_indicator;
	}

	void set_environment_indicator(bool environment_indicator)
	{
		_environment_indicator = environment_indicator;
	}

	bool get_environment_indicator()
	{
		return _environment_indicator;
	}
};