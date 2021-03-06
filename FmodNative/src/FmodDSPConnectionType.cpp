#include "FmodDSPConnectionType.h"

namespace {
	bool _initialized = false;
	jclass _class;
	jmethodID _method_getenumvalue;
	jmethodID _method_getvalue;

	void _init(JNIEnv* env) {
		if (_initialized) {
			return;
		}
		_initialized = true;

		_class = env->FindClass("de/silveryard/basesystem/sound/FmodDSPConnectionType");
		_method_getenumvalue = env->GetStaticMethodID(_class, "getEnumValue", "(I)Lde/silveryard/basesystem/sound/FmodDSPConnectionType;");
		_method_getvalue = env->GetMethodID(_class, "getValue", "()I");
	}
}

jobject fmoddspconnectiontype_get_enum_value(JNIEnv* env, int value) {
	_init(env);
	return env->CallStaticObjectMethod(_class, _method_getenumvalue, value);
}
int fmoddspconnectiontype_get_value(JNIEnv* env, jobject obj) {
	_init(env);
	return env->CallIntMethod(obj, _method_getvalue);
}