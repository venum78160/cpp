#include <fstream>
#include <iostream>
#include <string>


std::string	replace(std::string buffer, std::string strtoreplace, std::string replace_str)
{
	size_t	pos_find = 0;
	buffer.find(strtoreplace);

	while((pos_find = buffer.find(strtoreplace, pos_find)) != std::string::npos)
	{
		buffer.erase(pos_find, strtoreplace.length());
		buffer.insert(pos_find, replace_str);
		pos_find += replace_str.length();
	}
	return (buffer);
}

int main(int argc, char **argv)
{	
	if (argc != 4)
		std::cout << "Use : \"Name of the file\", \"line to be replaced\", \"Sentence by which it is replaced\" " << std::endl;
	else
	{
		std::string		filename = argv[1];
		std::string		strtoreplace = argv[2];
		std::string		replace_str = argv[3];
		std::string		line;
		std::ifstream	infile(filename);

		if (infile.is_open() == false)
		{
			std::cout << "Error while opening the file \" "<< filename << " \"" << std::endl;
			exit(1);
		}
		std::ofstream	outfile(filename + ".replace");
		if (outfile.is_open() == false)
		{
			std::cout << "Error while opening the file \" "<< filename << " .replace\"" << std::endl;
			exit(1);
		}
		while (std::getline(infile, line))
		{
			line = replace(line, strtoreplace, replace_str);
			outfile << line;
			if (infile.peek() != EOF)
			{
				outfile << std::endl;
			}
		}
		infile.close();
		outfile.close();
	}
		return (0);
}