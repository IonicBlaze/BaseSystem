/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class de_awesome_smarthome_td_sound_FmodSystem */

#ifndef _Included_de_awesome_smarthome_td_sound_FmodSystem
#define _Included_de_awesome_smarthome_td_sound_FmodSystem
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    createSystem
 * Signature: ()Lde/awesome/smarthome/td/sound/FmodSystem;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_createSystem
  (JNIEnv *, jclass);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    init
 * Signature: (II)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_init
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    update
 * Signature: ()Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_update
  (JNIEnv *, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    dispose
 * Signature: ()Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_dispose
  (JNIEnv *, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    setOutput
 * Signature: (Lde/awesome/smarthome/td/sound/FmodOutputType;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_setOutput
  (JNIEnv *, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getOutput
 * Signature: (Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getOutput
  (JNIEnv *, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getNumDrivers
 * Signature: (Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getNumDrivers
  (JNIEnv *, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getDriverInfo
 * Signature: (ILde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getDriverInfo
  (JNIEnv *, jobject, jint, jobject, jobject, jobject, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    setDriver
 * Signature: (I)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_setDriver
  (JNIEnv *, jobject, jint);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getDriver
 * Signature: (Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getDriver
  (JNIEnv *, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    createSound
 * Signature: (Ljava/lang/String;ILde/awesome/smarthome/td/sound/FmodCreateSoundExInfo;Lde/awesome/smarthome/td/sound/FmodSound;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_createSound
  (JNIEnv *, jobject, jstring, jint, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    createStream
 * Signature: (Ljava/lang/String;ILde/awesome/smarthome/td/sound/FmodCreateSoundExInfo;Lde/awesome/smarthome/td/sound/FmodSound;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_createStream
  (JNIEnv *, jobject, jstring, jint, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    playSound
 * Signature: (Lde/awesome/smarthome/td/sound/FmodSound;ZLde/awesome/smarthome/td/sound/FmodChannel;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_playSound
  (JNIEnv *, jobject, jobject, jboolean, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getRecordNumDrivers
 * Signature: (Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getRecordNumDrivers
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getRectordDriverInfo
 * Signature: (ILde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;Lde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getRectordDriverInfo
  (JNIEnv *, jobject, jint, jobject, jobject, jobject, jobject, jobject, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    getRecordPosition
 * Signature: (ILde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_getRecordPosition
  (JNIEnv *, jobject, jint, jobject);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    recordStart
 * Signature: (ILde/awesome/smarthome/td/sound/FmodSound;Z)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_recordStart
  (JNIEnv *, jobject, jint, jobject, jboolean);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    recordStop
 * Signature: (I)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_recordStop
  (JNIEnv *, jobject, jint);

/*
 * Class:     de_awesome_smarthome_td_sound_FmodSystem
 * Method:    isRecording
 * Signature: (ILde/awesome/smarthome/td/util/Wrapper;)Lde/awesome/smarthome/td/sound/FmodResult;
 */
JNIEXPORT jobject JNICALL Java_de_awesome_smarthome_td_sound_FmodSystem_isRecording
  (JNIEnv *, jobject, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
