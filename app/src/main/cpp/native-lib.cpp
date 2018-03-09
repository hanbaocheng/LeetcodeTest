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
    vector<int> words = {3,2,1};
    string s = ")";
    vector<vector<char>> board = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
                                  {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
                                  {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
                                  {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
                                  {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
                                  {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
                                  {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};
    solution.solveSudoku(board);
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_hanbaocheng_medionfileexplorer_MainActivity_addTwoNumbers(
        JNIEnv *env,
        jobject instance) {

}