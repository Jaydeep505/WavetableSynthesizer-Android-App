#pragma once

#include <memory>
#include "Wavetable.h"
#include <mutex>
#include "WavetableFactory.h"

namespace wavetablesynthesizer {
    class AudioSource;
    class AudioPlayer;

    constexpr auto sampleRate = 48000;

    class WavetableSynthesizer {
    public:
        WavetableSynthesizer();
        ~WavetableSynthesizer();
        void play();
        void stop();
        bool isPlaying() const;
        void setFrequency(float frequencyInHz);
        void setVolume(float volumeInDb);
        void setWavetable(Wavetable wavetable);

    private:
        std::atomic<bool> _isPlaying{false};
        std::mutex _mutex;
        WavetableFactory _wavetableFactory;
        Wavetable _currentWavetable{Wavetable::SINE};
        std::shared_ptr<AudioSource> _oscillator;
        std::unique_ptr<AudioPlayer> _audioPlayer;

    };
}
