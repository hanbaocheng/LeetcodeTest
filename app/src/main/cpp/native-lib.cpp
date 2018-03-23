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
    vector<int> list = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
    solution.trap(list);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_hanbaocheng_medionfileexplorer_MainActivity_addTwoNumbers(
        JNIEnv *env,
        jobject instance) {

}