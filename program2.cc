/*
 * Filename      program2.cc
 * Date          2/13/2020
 * Author        Noah Sims
 * Email         ngs170000@utdallas.edu
 * Course        CS 3377.501 Spring 2020
 * Version       1.0
 * Copyright 2019, All Rights Reserved
 *
 * Description
 *
 *     This program takes in a file and copies it's contents to an output file, with options to convert text to upper or lower case
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "prog2Header.h"

using namespace std;

int main(int argc, char** argv)
{
  map<int, string> optionMap;

  fillMap(optionMap, argc, argv);

  ifstream infile;
  infile.open(optionMap[INFILE].c_str(), ios::in);
  if(infile.is_open())
  {
    cout << "Writing to " << optionMap[OUTFILE] << endl;

    ofstream outfile;
    outfile.open(optionMap[OUTFILE].c_str(), ios::out);

    char c;
    while(infile.get(c))
    {
      if(optionMap[UPPER] == "true")
	c = toupper(c);
      if(optionMap[LOWER] == "true")
	c = tolower(c);

      outfile << c;
    }

    infile.close();
    outfile.close();

    cout << "Done" << endl;
  }
  else
  {
    cout << "error: file '" << optionMap[INFILE] << "' not found" << endl;
    return -1;
  }
  
  return 0;
}
