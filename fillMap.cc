/*
 * Filename      fillMap.cc
 * Date          2/13/2020
 * Author        Noah Sims
 * Email         ngs170000@utdallas.edu
 * Course        CS 3377.501 Spring 2020
 * Version       1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     This file provides the fillMap function for program2, which makes use of the TCLAP package to parse command line information and
 *     inserts it into a map
 */

#include <iostream>
#include <map>
#include <tclap/CmdLine.h>
#include "prog2Header.h"

using namespace std;

void fillMap(std::map<int, std::string> &optionMap, int argc, char** argv)
{
  TCLAP::CmdLine cmd("CS3377.501 Program 2: copies a file with options to change all text to upper or lower case. -u and -l are mutually exclusive", ' ', "1.0");

  TCLAP::SwitchArg upperSwitch("u", "upper", "Convert all text to uppercase.", cmd, false);

  TCLAP::SwitchArg lowerSwitch("l", "lower", "Convert all text to lowercase.", cmd, false);

  TCLAP::ValueArg<std::string> outfileArg("o", "outfile", "The name of the output file", false, "output.txt", "output filename");
  cmd.add(outfileArg);

  TCLAP::UnlabeledValueArg<std::string> infileArg("infile", "The input file name.", true, "infile.txt", "input filename", false);
  cmd.add(infileArg);

  try {
    cmd.parse(argc, argv);
    if(upperSwitch.getValue())
      optionMap[UPPER] = "true";
    else
      optionMap[UPPER] = "false";

    if(lowerSwitch.getValue())
      optionMap[LOWER] = "true";
    else
      optionMap[LOWER] = "false";

    optionMap[OUTFILE] = outfileArg.getValue();
    optionMap[INFILE] = infileArg.getValue();

    if(optionMap[UPPER] == "true" && optionMap[LOWER] == "true")
    {
      throw(TCLAP::ArgParseException("-u and -l are mutually exclusive", "-u, -l"));
    }

  } catch(TCLAP::ArgException &e) {
    cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
    cmd.getOutput()->usage(cmd);
    exit(EXIT_FAILURE);
  }

}
