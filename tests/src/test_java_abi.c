#include "unit_tests.h"
#include <jni.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int test_java_abi(void) {
  JavaVM *vm;
  JNIEnv *env;
  JavaVMInitArgs vm_args;
  JavaVMOption options[1];
  jint res;
  jclass class;
  jmethodID method_increment, method_peek;

  options[0].optionString = "-Djava.class.path=./bridge_test.jar";

  vm_args.version = JNI_VERSION_1_8;
  vm_args.nOptions = 1;
  vm_args.options = options;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
  if (res != JNI_OK) {
    printf("Failed to create Java VM\n");
    return -1;
  }

  class = (*env)->FindClass(env, "Test");
  if (class == NULL) {
    printf("Failed to find Test class\n");
    return -1;
  }

  method_increment = (*env)->GetStaticMethodID(env, class, "increment", "()V");
  if (method_increment == NULL) {
    printf("Failed to find increment function\n");
    return -1;
  }
  method_peek = (*env)->GetStaticMethodID(env, class, "peek", "()J");
  if (method_peek == NULL) {
    printf("Failed to find peek function\n");
    return -1;
  }
  (*env)->CallStaticVoidMethod(env, class, method_increment);
  (*env)->CallStaticVoidMethod(env, class, method_increment);

  jlong result = (*env)->CallStaticLongMethod(env, class, method_peek);
  printf("Result: %ld\n", (long)result);

  (*vm)->DestroyJavaVM(vm);
  return 0;
}
