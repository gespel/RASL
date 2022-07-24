/*
  ==============================================================================

    RASLParser.h
    Created: 19 Jul 2022 3:49:07pm
    Author:  Sten Heimbrodt

  ==============================================================================
*/
#include "RASLProcessor.h"
#include "JuceHeader.h"
#include <iostream>
#pragma once

class RASLParser {
public:
    RASLParser(RASLProcessor *proc);
    void parse(juce::String input);
    std::vector<std::string> split(std::string input, std::string teiler);
    
private:
    RASLProcessor *p;
};
