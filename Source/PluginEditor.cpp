#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
RASLAudioProcessorEditor::RASLAudioProcessorEditor (RASLAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 325);
    mainEditor.setMultiLine(true);
    mainEditor.setReturnKeyStartsNewLine(true);
    executeButton.setButtonText("Execute!");
    addAndMakeVisible(&mainEditor);
    addAndMakeVisible(&executeButton);
}

RASLAudioProcessorEditor::~RASLAudioProcessorEditor()
{
}

//==============================================================================
void RASLAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void RASLAudioProcessorEditor::resized()
{
    mainEditor.setBounds(5, 5, 390, 290);
    executeButton.setBounds(5, 300, 100, 20);
}

void RASLAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    parser->parse(mainEditor.getText());
}
