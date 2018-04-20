#!/bin/bash

# debug
# java -jar jFuzzyLogic.jar -e nikolas.fcl 1000 1000 1000 1000

#java -jar jFuzzyLogic.jar -e nikolas.fcl $1 $2 $3 $4

# create C++ source code
java -jar jFuzzyLogic_core.jar -c nikolas.fcl > nikolas.cpp
