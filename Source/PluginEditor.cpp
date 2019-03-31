/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/


#include "PluginProcessor.h"
#include "PluginEditor.h"
//global

std::list<GUI*> GUI::fGuiList;

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor (CompressorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),mygui(false)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
 
    addAndMakeVisible(mygui);
    p.getDspInstance()->buildUserInterface(&mygui);
    juce::Rectangle<int> recommendedSize = mygui.getSize();
    setSize (recommendedSize.getWidth(), recommendedSize.getHeight());
}

CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor()
{
}

//==============================================================================
void CompressorAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void CompressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mygui.setBounds(getLocalBounds());
}
