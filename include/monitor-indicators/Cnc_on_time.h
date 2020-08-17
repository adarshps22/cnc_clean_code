#include <inttypes.h>
#include "IMonitor.h"

class Cnc_on_time : public IMonitor
{
	uint64_t _time_min;
	uint64_t _ref_time_min = 360;

public:

	void set_on_time(uint64_t time)
	{
		_time_min = time;
	}

	float get_on_time()
	{
		return _time_min;
	}

	bool diagnosis()
	{
		auto status = _time_min > _ref_time_min;
		set_machine_indicator(status);
		return status;
	}
};