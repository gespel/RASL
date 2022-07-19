/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "RASLParser.h"

//==============================================================================
/**
*/
class RASLAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Button::Listener
{
public:
    RASLAudioProcessorEditor (RASLAudioProcessor&);
    ~RASLAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RASLAudioProcessor& audioProcessor;
    RASLParser *parser = new RASLParser(&audioProcessor.p);
    juce::TextEditor mainEditor;
    juce::TextButton executeButton;
    void buttonClicked (juce::Button* button) override;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RASLAudioProcessorEditor)
};
