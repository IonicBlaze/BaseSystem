/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class de_silveryard_basesystem_libdisplayjava_Display */

#ifndef _Included_de_silveryard_basesystem_libdisplayjava_Display
#define _Included_de_silveryard_basesystem_libdisplayjava_Display
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     de_silveryard_basesystem_libdisplayjava_Display
 * Method:    compareHandlesNative
 * Signature: (Lde/silveryard/basesystem/libdisplayjava/Handle;Lde/silveryard/basesystem/libdisplayjava/Handle;)Z
 */
JNIEXPORT jboolean JNICALL Java_de_silveryard_basesystem_libdisplayjava_Display_compareHandlesNative
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     de_silveryard_basesystem_libdisplayjava_Display
 * Method:    getHandleNative
 * Signature: (Lde/silveryard/basesystem/libdisplayjava/Handle;)I
 */
JNIEXPORT jint JNICALL Java_de_silveryard_basesystem_libdisplayjava_Display_getHandleNative
  (JNIEnv *, jclass, jobject);

/*
 * Class:     de_silveryard_basesystem_libdisplayjava_Display
 * Method:    isSuccessNative
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_de_silveryard_basesystem_libdisplayjava_Display_isSuccessNative
  (JNIEnv *, jclass, jint);

/*
 * Class:     de_silveryard_basesystem_libdisplayjava_Display
 * Method:    isErrorNative
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_de_silveryard_basesystem_libdisplayjava_Display_isErrorNative
  (JNIEnv *, jclass, jint);

#ifdef __cplusplus
}
#endif
#endif