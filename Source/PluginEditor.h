/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class SimpleDelayAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleDelayAudioProcessorEditor (SimpleDelayAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~SimpleDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleDelayAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& treeState;

    juce::Slider delayTimeSlider;
    juce::Slider feedbackSlider;

    juce::Label delayTimeLabel;
    juce::Label feedbackLabel;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeValue;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> feedbackValue;

    //Wet mix stuff
    juce::Slider wetMixSlider;
    juce::Label wetMixLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> wetMixValue;

    // Dry Mix stuff
    juce::Slider dryMixSlider;
    juce::Label dryMixLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dryMixValue;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleDelayAudioProcessorEditor)
};
