#pragma once

#include <cstdint>

namespace wavetablesynthesizer {
    class AudioSource {
    public:
        virtual ~AudioSource() = default;
        virtual float getSample() = 0;
        virtual void onPlaybackStopped() = 0;

        virtual void setFrequency(float) {}
        virtual void setAmplitude(float) {}
        virtual void setWavetable(const std::vector<float>&) {}
    };
}