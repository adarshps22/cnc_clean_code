#include "Cnc_startup_error_codes.h"
#include "IMonitor.h"

class Cnc_start_up : public IMonitor
{
	Cnc_startup_error_codes _starup_error_codes;
	Cnc_startup_error_codes::error_code _starup_status;

public:

	void set_startup_status(uint64_t status)
	{
		_starup_status = Cnc_startup_error_codes::error_code(status);
	}

	uint64_t get_startup_status()
	{
		return (uint64_t)_starup_status;
	}

	bool diagnosis()
	{
		bool status = false;
		set_machine_indicator(false);
		set_environment_indicator(false);

		switch (_starup_status)
		{
			case Cnc_startup_error_codes::error_code::ALL_OK : 
				status = false;
				break;
			case Cnc_startup_error_codes::error_code::CB_ERROR:
				status = true;
				set_environment_indicator(true);
				break;
			case Cnc_startup_error_codes::error_code::DATA_CORRUPT:
				status = true;
				set_machine_indicator(true);
				break;
			case Cnc_startup_error_codes::error_code::NO_DATA:
				status = true;
				set_machine_indicator(true);
				break;
		}

		return status;
	}
};