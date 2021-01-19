#!/bin/bash

# Filename      compile.sh
# Date          2/13/2020
# Author        Noah Sims
# Email         ngs170000@utdallas.edu
# Course        CS 3377.501 Spring 2020
# Version       1.0
# Copyright 2019, All Rights Reserved
#
# Description
#
#     This shell script compiles program2
#

echo Compiling program2.cc
g++ -c program2.cc

echo Compiling fillMap.cc
g++ -c fillMap.cc -I ~/CS3377/assignments/hw2/include

echo Linking files to create executable program2
g++ program2.o fillMap.o -o program2

echo Done
