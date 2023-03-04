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

int main( int argc, char **argv)
{
	std::map<std::string, double> maps;
	std::string line;
	if (argc != 2)
	{
		std::cout << "Error: incorrect number of arguments. Please insert a file" << std::endl;
		return (1);
	}
	std::ifstream fexrate("exchange_rate.txt");
	if(!fexrate.is_open())
	{
		std::cout << "Please insert a correct file" << std::endl;
		return (1);
	}
	while (getline(fexrate, line))
	{
		std::string dateStr = line.substr(0, line.find("|") - 1);
        std::string valueStr = line.substr(line.find("|") + 2);
		
		try
		{
			double value = std::stod(valueStr);
			std::cout << dateStr << " => " << value << " = " << valueStr << std::endl;
			if (value < 0 || value > 1000)
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
	std::cout << "----------------------------------" << std::endl;
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
			double value = std::stod(valueStr);
			if (value < 0 || value > 1000)
				throw std::out_of_range("not in valid range");
			if (!isValidDate(dateStr))
				throw std::invalid_argument("❌ Date is not valid.");
			maps[dateStr] = value;
			std::map<std::string, double>::iterator it = maps.find(dateStr);
			if (it == maps.end())
				throw std::invalid_argument("❌ Date has not been found.");
			double rate = maps[dateStr];
            double convertedValue = value * rate;
            std::cout << dateStr << " => " << value << " * rate(" << rate <<") = " << convertedValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error : " <<e.what() << " => " << line << std::endl;
		}
	}
	return 0;
	// try
	// {
	// 	double value = std::stod(valueStr);
	// 	if (value < 0 || value > 1000)
	// 		throw std::out_of_range("not in valid range");
	// 	if (!isValidDate(dateStr))
	// 		throw std::invalid_argument("❌ Date is not valid.");
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}