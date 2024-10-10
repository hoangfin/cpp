/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:29:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/10 14:43:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <system_error>
#include <fstream>

std::string replace(const std::string& line, const std::string& s1, const std::string& s2) {
	std::string result;
	std::size_t curPos = 0;
	std::size_t nextPos = line.find(s1, 0);
	while (nextPos != std::string::npos) {
		result.append(line, curPos, nextPos - curPos);
		result.append(s2);
		curPos = nextPos + s1.length();
		nextPos = line.find(s1, curPos);
	}
	result.append(line, curPos, line.length() - curPos);
	return result;
}

void transfer(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream file = std::ifstream(filename);
	if (!file.is_open()) {
		throw std::system_error(errno, std::generic_category());
	}

	std::ofstream outfile = std::ofstream(filename + ".replace");
	if (!outfile.is_open()) {
		throw std::system_error(errno, std::generic_category());
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (!file.eof())
			outfile << replace(line, s1, s2) << std::endl;
		else
			outfile << replace(line, s1, s2);
	}
	file.close();
	outfile.close();
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Invalid number of arguments!" << std::endl;
		return 1;
	}

	try {
		transfer(argv[1], argv[2], argv[3]);
    } catch (const std::system_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

	return 0;
}
