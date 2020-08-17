#include "IMonitor.h"

class Drill_bit : public IMonitor
{
	float _part_variation_mm;
	float _ref_part_variation_mm = 0.05;

public:

	void set_drill_bit_variation(float variation)
	{
		_part_variation_mm = variation;
	}

	float get_drill_bit_variation()
	{
		return _part_variation_mm;
	}

	bool diagnosis() override
	{
		auto status = _part_variation_mm > _ref_part_variation_mm;
		set_machine_indicator(status);
		return status;
	}
};