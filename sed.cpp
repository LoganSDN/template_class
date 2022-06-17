#include <iostream>
#include <fstream>
#include <sstream>

void	ft_replace( const std::string s1, const std::string s2, std::string &input, std::ofstream &ofs)
{
	int i = 0;
	while (input.find(s1) != std::string::npos)
	{
		i = input.find(s1);
		input.erase(i , s1.length());
		input.insert(i, s2);
	}
	ofs << input;
	ofs.close();
}

int	main(int ac , char  **av)
{
	std::stringstream input;

	if (ac != 4)
	{
		std::cout<< "Wrong arguments" <<std::endl;
		return 1 ;
	}
	std::string argv[2] = {av[2], av[3]};
	if (argv[0].length() == 0 || argv[1].find(argv[0]) != std::string::npos)
	{
		std::cout<< "Wrong arguments" <<std::endl;
		return 1 ;
	}
	std::ifstream ifs(av[1]);
	if (ifs.is_open() == 0)
	{
		std::cout << "failed to open " << av[1] << std::endl;
		return 1;
	}
	std::ofstream ofs((std::string)av[1] + ".replace");
	if (ofs.is_open() == 0)
	{
		std::cout << "failed to open  output" << std::endl;
		ifs.close();
		return (1);
	}
	input << ifs.rdbuf();
	std::string tmp = input.str();
	ft_replace(av[2], av[3], tmp, ofs);
	return (0);
}