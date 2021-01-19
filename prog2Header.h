/*
 * Filename      prog2Header.h
 * Date          2/13/2020
 * Author        Noah Sims
 * Email         ngs170000@utdallas.edu
 * Course        CS 3377.501 Spring 2020
 * Version       1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     The header file for program2
 */

// constants
enum cmdFlags{UPPER, LOWER, OUTFILE, INFILE};

// function prototypes
void fillMap(std::map<int, std::string> &optionMap, int argc, char** argv);
