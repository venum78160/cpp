#include "../includes/BitcoinExchange.hpp"

bool	isValidDate(const std::string& dateStr)
{
    if (dateStr.size() != 10)
        return false;

    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    int year = atoi(dateStr.substr(0, 4).c_str());
    int month = atoi(dateStr.substr(5, 2).c_str());
    int day = atoi(dateStr.substr(8, 2).c_str());

    if (year < 1900 || year > 2100)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    return true;
}

double days_between_dates(const std::string& target_day, const std::string& date2)
{
    std::tm tm1 = { 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, nullptr };
	std::tm tm2 = { 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, nullptr };

    // parse target_day
    tm1.tm_year = atoi(target_day.substr(0, 4).c_str()) - 1900;
    tm1.tm_mon = atoi(target_day.substr(5, 2).c_str()) - 1;
    tm1.tm_mday = atoi(target_day.substr(8, 2).c_str());

    // parse date2
    tm2.tm_year = atoi(date2.substr(0, 4).c_str()) - 1900;
    tm2.tm_mon = atoi(date2.substr(5, 2).c_str()) - 1;
    tm2.tm_mday = atoi(date2.substr(8, 2).c_str());

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    if (time1 == -1 || time2 == -1) {
        // handle error
        return -1.0;
    }

    double seconds_between = std::difftime(time1, time2);
    double days_between = std::abs(seconds_between / 86400.0);

    return days_between;
}

std::string find_closest_lower_date(const std::map<std::string, double>& dates, const std::string& target_date)
{
    int target_year = atoi(target_date.substr(0, 4).c_str());
    int target_month = atoi(target_date.substr(5, 2).c_str());
    int target_day = atoi(target_date.substr(8, 2).c_str());

    std::string closest_date = "";
    double closest_distance = std::numeric_limits<double>::infinity();

    std::map<std::string, double>::const_iterator it;
    for (it = dates.begin(); it != dates.end(); ++it)
    {
        int year = atoi(it->first.substr(0, 4).c_str());
        int month = atoi(it->first.substr(5, 2).c_str());
        int day = atoi(it->first.substr(8, 2).c_str());

        if ((year < target_year) || (year == target_year && ((month < target_month) || (month == target_month && day < target_day))))
        {
            double current_distance = days_between_dates(target_date, it->first);
            if (current_distance < closest_distance)
            {
                closest_date = it->first;
                closest_distance = current_distance;
            }
        }
    }

    return closest_date;
}


int main( int argc, char **argv)
{
	std::map<std::string, double> maps;
	std::string line;
	if (argc != 2)
	{
		std::cout << "Error: incorrect number of arguments. Please insert a file" << std::endl;
		return (1);
	}
	std::ifstream fexrate("data.csv");
	if(!fexrate.is_open())
	{
		std::cout << "Please insert a correct file" << std::endl;
		return (1);
	}
	while (getline(fexrate, line))
	{
		if(line == "date,exchange_rate")
			continue;
		std::string dateStr = line.substr(0, line.find(","));
        std::string valueStr = line.substr(line.find(",") + 1);
		try
		{
			double value = std::stod(valueStr);
			// std::cout << dateStr << " => " << value << " = " << valueStr << std::endl;
			if (value < 0)
				throw std::out_of_range("not in valid range");
			if (!isValidDate(dateStr))
				throw std::invalid_argument("❌ Date is not valid.");
			maps[dateStr] = value;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
		}
	}
	// std::cout << "---------------------------------- End first" << std::endl;
	line.clear();
	std::ifstream file(argv[1]);
	std::cout << std::fixed;
    std::cout.precision(2);
	if(!file.is_open())
	{
		std::cout << "Please insert a correct file" << std::endl;
		return (1);
	}
	while (getline(file, line))
	{
		std::string dateStr = line.substr(0, line.find("|") - 1);
        std::string valueStr = line.substr(line.find("|") + 2);
		
		try
		{
			double rate;
			double value = std::stod(valueStr);
			if (value < 0 || value > 1000)
				throw std::out_of_range("not in valid range");
			if (!isValidDate(dateStr))
				throw std::invalid_argument("❌ Date is not valid.");
			// maps[dateStr] = value;
			std::map<std::string, double>::iterator it = maps.find(dateStr);
			if (it == maps.end())
			{
				// throw std::invalid_argument("❌ Date has not been found.");
				// find_lowest_date(Vdates, dateStr, value, maps);
				std::string nearest_date = find_closest_lower_date(maps, dateStr);
				std::cout << "Date " << dateStr << " not found. The nearest previous date in the file is " << nearest_date << "." << std::endl;
				rate = maps[nearest_date];
			}
			else
				rate = maps[dateStr];
            double convertedValue = value * rate;
            std::cout << dateStr << " => " << value << " * rate(" << rate <<") = " << convertedValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " <<e.what() << " => " << line << std::endl;
		}
	}
	return 0;
}