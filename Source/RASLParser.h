/*
  ==============================================================================

    RASLParser.h
    Created: 19 Jul 2022 3:49:07pm
    Author:  Sten Heimbrodt

  ==============================================================================
*/
#include "RASLProcessor.h"
#pragma once

class RASLParser {
public:
    RASLParser(RASLProcessor *proc);
    
private:
    RASLProcessor *p;
};
