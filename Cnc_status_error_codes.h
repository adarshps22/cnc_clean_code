#include <map>
#include <string>

class Cnc_error_message
{
private:

	std::map<unsigned int, std::string> _error_codes;

public:

	enum class error_code 
	{
		ALL_OK = 0xFF,
		NO_DATA = 0x00, // No Connection to the data-collector
		CB_ERROR = 0x01, // Controller Board Error
		DATA_CORRUPT = 0x02	
	};

	Cnc_error_message()
	{
		_error_codes.emplace((unsigned int)error_code::ALL_OK, "All OK");
		_error_codes.emplace((unsigned int)error_code::NO_DATA, "No Data to Controller");
		_error_codes.emplace((unsigned int)error_code::CB_ERROR, "Controller Board is not OK");
		_error_codes.emplace((unsigned int)error_code::DATA_CORRUPT, "Configuration data in the mahcine is corupted");
	}

	std::string get_error_message(unsigned int error_code)
	{
		auto error = _error_codes.find(error_code);
		if (error != _error_codes.end())
		{
			return error->second;
		}
		else			
		{
			return "Invalid Error Code";
		}
	}
};