#ifndef TEST_H
#define TEST_H 1

#if defined(WIN32) || defined(_WIN32)
    #define API __declspec(dllexport)
#else
    #define API __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

API long fibonacci(long n);

#ifdef __cplusplus
}
#endif

#endif /* TEST_H */
