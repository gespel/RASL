/*
  ==============================================================================

    RASLParser.cpp
    Created: 19 Jul 2022 3:49:07pm
    Author:  Sten Heimbrodt

  ==============================================================================
*/

#include "RASLParser.h"
#include <stdlib.h>

RASLParser::RASLParser(RASLProcessor *proc) {
    p = proc;
}
//=====================================
//Ugly Parser Code
//=====================================
void RASLParser::parse(juce::String input) {
    if(input.indexOf("sineSynth(") != -1) {
        std::vector<std::string> args = split(input.substring(10, input.lastIndexOf(");")).toStdString(), ",");
        int channelNumber = std::stoi(args[0]);
        int freq = std::stoi(args[1]);
    }
    else if(input.indexOf("squareSynth(") != -1) {
        std::vector<std::string> args = split(input.substring(11, input.lastIndexOf(");")).toStdString(), ",");
    }
    else if(input.indexOf("distort(") != -1) {
        std::vector<std::string> args = split(input.substring(8, input.lastIndexOf(");")).toStdString(), ",");
    }
    else if(input.indexOf("gain(") != -1) {
        std::vector<std::string> args = split(input.substring(5, input.lastIndexOf(");")).toStdString(), ",");
    }
    else {
        //TODO: Fehlerbehandlung Keyword Error
    }
}

std::vector<std::string> RASLParser::split(std::string input, std::string teiler) {
    std::vector<std::string> out;
    size_t pos = 0;
    std::string token;
    
    while ((pos = input.find(teiler)) != std::string::npos) {
        token = input.substr(0, pos);
        out.push_back(token);
        input.erase(0, pos + teiler.length());
    }
    return out;
}
