#include <fabric/loader.h>
#include <jni.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#if _WIN32
#include <windows.h>
#else

#endif

static int test(void) {
  JavaVM *vm;
  JNIEnv *env;
  JavaVMInitArgs vm_args;
  JavaVMOption options[1];
  jint res;
  jclass class;
  jmethodID method_increment, method_peek;

  options[0].optionString = "-Djava.class.path=./fabric/bridge.jar";

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

static int init(void) {
  if (test() != 0) {
    exit(EXIT_FAILURE);
  }
  return 0;
}

static int deinit(void) {
  //
  return 0;
}

Loader loader = {
    .init = init,
    .deinit = deinit,
};
