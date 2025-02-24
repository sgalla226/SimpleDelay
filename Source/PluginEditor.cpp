/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleDelayAudioProcessorEditor::SimpleDelayAudioProcessorEditor (SimpleDelayAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), treeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 280);

    // Delay time
    delayTimeValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(treeState, "delayTime", delayTimeSlider);
    delayTimeSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    delayTimeSlider.setRange(10.0f, 5000.0f, 1.0f);
    delayTimeSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, true, 75, 25);
    addAndMakeVisible(&delayTimeSlider);

    addAndMakeVisible(delayTimeLabel);
    delayTimeLabel.setText("Delay time (samples)", juce::dontSendNotification);
    delayTimeLabel.attachToComponent(&delayTimeSlider, false);

    // Feedback
    feedbackValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(treeState, "feedback", feedbackSlider);
    feedbackSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    feedbackSlider.setRange(0.0f, 0.99f, 0.01f);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, true, 75, 25);
    addAndMakeVisible(&feedbackSlider);

    addAndMakeVisible(feedbackLabel);
    feedbackLabel.setText("Feedback", juce::dontSendNotification);
    feedbackLabel.attachToComponent(&feedbackSlider, false);

    // Wet Mixing

    wetMixValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(treeState, "wetMix", wetMixSlider);
    wetMixSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    wetMixSlider.setRange(0.0f, 1.0f, 0.01f);
    wetMixSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, true, 75, 25);
    addAndMakeVisible(&wetMixSlider);

    addAndMakeVisible(wetMixLabel);
    wetMixLabel.setText("Wet Mix", juce::dontSendNotification);
    wetMixLabel.attachToComponent(&wetMixSlider, false);

    // Dry Mixing 
    dryMixValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(treeState, "dryMix", dryMixSlider);
    dryMixSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    dryMixSlider.setRange(0.0f, 1.0f, 0.01f);
    dryMixSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, true, 75, 25);
    addAndMakeVisible(&dryMixSlider);

    addAndMakeVisible(dryMixLabel);
    dryMixLabel.setText("Dry Mix", juce::dontSendNotification);
    dryMixLabel.attachToComponent(&dryMixSlider, false);
}


SimpleDelayAudioProcessorEditor::~SimpleDelayAudioProcessorEditor()
{
}

//==============================================================================
void SimpleDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::grey);
    g.setColour(juce::Colours::white);
    g.setFont(20);
    g.drawFittedText("Simple Delay", 150, 5, 130, 30, juce::Justification::centred, 1, 0.0f);
}

void SimpleDelayAudioProcessorEditor::resized()
{
    delayTimeSlider.setBounds(50, 50, 320, 50);
    feedbackSlider.setBounds(50, 110, 320, 50);

    //Wet Mix Slider

    wetMixSlider.setBounds(50, 170, 320, 50);

    //Dry Mix slider

    dryMixSlider.setBounds(50, 230, 320, 50);
}
 