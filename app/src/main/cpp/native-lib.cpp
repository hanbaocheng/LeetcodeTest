#include <jni.h>
#include <string>
#include "Solution.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_hanbaocheng_medionfileexplorer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    Solution solution;
    vector<int> list = {1,2,3};
    solution.permute(list);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_hanbaocheng_medionfileexplorer_MainActivity_addTwoNumbers(
        JNIEnv *env,
        jobject instance) {

}