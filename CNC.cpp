#include "Cnc_data_monitor.h"
#include "Cnc_status_error_codes.h"
#include "Cnc_data_validator.h"
#include "Cnc_health_indicator.h"
#include "Cnc_diagnosis.h"

class Cnc
{
	Cnc_diagnosis diagnosis;
	
public:
	void run_all_diagnosis()
	{
		diagnosis.temperature_diagnosis();
		diagnosis.part_variation_diagnosis();
		diagnosis.continuous_operation_diagnosis();
		diagnosis.startup_diagnosis();

		diagnosis.update_all_status();
	}
};

int main()
{
	return 0;
}
