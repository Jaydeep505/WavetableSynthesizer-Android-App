#include <jni.h>
#include <memory>
#include "Log.h"
#include "WavetableSynthesizer.h"

extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_create(JNIEnv *env,
                                                                         jobject thiz) {
    auto synthesizer = std::make_unique<wavetablesynthesizer::WavetableSynthesizer>();

    if (not synthesizer) {
        LOGD("Failed to create synthesizer.");
        synthesizer.reset(nullptr);
    }

    return reinterpret_cast<jlong>(synthesizer.release());

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_delete(JNIEnv *env, jobject thiz,
                                                                         jlong synthesizerHandle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizerHandle);

    if (not synthesizer) {
        LOGD("Attempt to destroy an initialized synthesizer.");
        return;
    }

    delete synthesizer;

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_play(JNIEnv *env, jobject thiz,
                                                                       jlong synthesizer_handle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);

    if (not synthesizer) {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");
        return;
    }

    synthesizer->play();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_stop(JNIEnv *env, jobject thiz,
                                                                       jlong synthesizer_handle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);

    if (not synthesizer) {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");
        return;
    }

    synthesizer->stop();
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_isPlaying(JNIEnv *env,
                                                                            jobject thiz,
                                                                            jlong synthesizer_handle) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);

    if (synthesizer) {
        return synthesizer->isPlaying();
    } else {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");

    }

    return false;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_setFrequency(JNIEnv *env,
                                                                               jobject thiz,
                                                                               jlong synthesizer_handle,
                                                                               jfloat frequency_in_hz) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);

    if (not synthesizer) {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");
        return;
    }

    synthesizer->setFrequency(static_cast<float>(frequency_in_hz));
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_setVolume(JNIEnv *env,
                                                                            jobject thiz,
                                                                            jlong synthesizer_handle,
                                                                            jfloat volume_in_db) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);

    if (not synthesizer) {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");
        return;
    }

    synthesizer->setVolume(static_cast<float>(volume_in_db));
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_wavetablesynthesizer2_NativeWavetableSynthesizer_setWavetable(JNIEnv *env,
                                                                               jobject thiz,
                                                                               jlong synthesizer_handle,
                                                                               jint wavetable) {
    auto* synthesizer = reinterpret_cast<wavetablesynthesizer::WavetableSynthesizer*>(synthesizer_handle);
    const auto nativeWavetable = static_cast<wavetablesynthesizer::Wavetable>(wavetable);

    if (not synthesizer) {
        LOGD("Synthesizer not created. Please, create synthesizer first by calling create().");
        return;
    }

    synthesizer->setWavetable(nativeWavetable);
}