/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/* ************************************************************************** */
/* *****************************  FUNCTIONS  ******************************** */
/* ************************************************************************** */

static void	compare_replace( std::ifstream &in_file, std::ofstream &out_file, \
	std::string &s1, std::string &s2 )
{
	std::string		temp_s1;
	size_t			i = 0;
	char 			c = 0;

	while (in_file.get(c))
	{
		if (c != s1[i] || s1.empty())
		{
			if (!temp_s1.empty())
				out_file << temp_s1;
			out_file << c;
			temp_s1.clear();
			i = 0;
		}
		else if (c == s1[i])
		{
			temp_s1.push_back(c);
			++i;
		}
		if (!temp_s1.empty() && temp_s1.length() == s1.length())
		{
			if (s1.compare(temp_s1) == 0)
				out_file << s2;
			else
				out_file << temp_s1;
			temp_s1.clear();
			i = 0;
		}
	}
}

/* ************************************************************************** */
/* ********************************  MAIN  ********************************** */
/* ************************************************************************** */

int	main( const int argc, const char **argv )
{
	if (argc != 4)
	{
		std::cerr << "ERROR: Invalid arguments count" << std::endl;
		return (1);
	}

	std::string		in_filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	in_file;

	in_file.open(in_filename, std::ios_base::in);
	if (in_file.is_open() == false)
	{
		std::cout << in_filename << ": failed to open input file" << std::endl;
		return (1);
	}

	std::string		out_filename = in_filename + ".replace";
	std::ofstream	out_file;

	out_file.open(out_filename, std::ios_base::out);
	if (out_file.is_open() == false)
	{
		in_file.close();
		std::cout << in_filename << ": failed to open output file" << std::endl;
		return (1);
	}
	compare_replace( in_file, out_file, s1, s2 );
	out_file.close();
	in_file.close();
	return (0);
}
