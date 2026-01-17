/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:54:56 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/13 10:23:50 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

/*
	Keeps looking for s1 in line as long as find() returns non-NULL value
	and replaces it using substr(). 
	Upon replacement, it updates start_pos to avoid backtracking indefinitely
	in case s2 contains s1 for example.
*/
void replaceAll(std::string &str, const std::string &s1, const std::string &s2) {
    if (s1.empty()) {
        return;
    }

    size_t start_pos = 0;
    while ((start_pos = str.find(s1, start_pos)) != std::string::npos) {
        str = str.substr(0, start_pos) + s2 + str.substr(start_pos + s1.length());
        start_pos += s2.length();
    }
}

int	main(int ac, char **av) {
	
	if (ac != 4) {
		std::cout << "Usage: ./SedIsForLosers <filename> <s1> <s2>" << std::endl;
		return (1);
	}

    std::string infile = av[1];
	std::string outfile = infile + ".replace";
	std::string s1 = av[2];
	std::string s2 = av[3];

    std::ifstream inputFile(infile.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open infile " << infile << std::endl;
        return (1);
    }


    std::ofstream outputFile(outfile.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create outfile " << outfile << std::endl;
        return (1);
    }

    std::string line;
    while (std::getline(inputFile, line)) {

		replaceAll(line, s1, s2);
        outputFile << line;
		if (!inputFile.eof()) {
            outputFile << '\n';
        }
    }

	outputFile.close();
    inputFile.close();
    return (0);
}
