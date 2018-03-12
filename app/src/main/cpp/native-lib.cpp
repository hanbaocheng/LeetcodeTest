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
    vector<int> list = {4,858,4,5,6,8,4,5,4,1,2,3,7,96,1,6};
    solution.quick_sort(list);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_hanbaocheng_medionfileexplorer_MainActivity_addTwoNumbers(
        JNIEnv *env,
        jobject instance) {

}