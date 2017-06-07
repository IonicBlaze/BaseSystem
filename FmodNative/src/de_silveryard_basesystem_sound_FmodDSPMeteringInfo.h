/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class de_silveryard_basesystem_sound_FmodDSPMeteringInfo */

#ifndef _Included_de_silveryard_basesystem_sound_FmodDSPMeteringInfo
#define _Included_de_silveryard_basesystem_sound_FmodDSPMeteringInfo
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_init
  (JNIEnv *, jobject);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    getHandle
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_getHandle
  (JNIEnv *, jobject);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    getNumSamples
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_getNumSamples
  (JNIEnv *, jobject);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    getPeakLevel
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_getPeakLevel
  (JNIEnv *, jobject, jint);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    getRmsLevel
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_getRmsLevel
  (JNIEnv *, jobject, jint);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    getNumChannels
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_getNumChannels
  (JNIEnv *, jobject);

/*
 * Class:     de_silveryard_basesystem_sound_FmodDSPMeteringInfo
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_de_silveryard_basesystem_sound_FmodDSPMeteringInfo_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
