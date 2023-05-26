#ifndef DEV_UTILS_H
#define DEV_UTILS_H

#include <stdlib.h>

#define PANIC(msg, stream)                                              \
  fprintf(stream, "PANIC: %s in [%s:%d] %s()\n",                        \
          msg, __FILE__, __LINE__, __FUNCTION__);                       \
  exit(1);                                                              \

#define TODO(msg, stream)                                               \
  fprintf(stream, "TODO: %s in [%s:%d] %s()\n",                         \
          msg, __FILE__, __LINE__, __FUNCTION__);                       \
  exit(1);                                                              \

#define UNIMPLEMENTED(msg, stream)                                      \
  fprintf(stream, "UNIMPLEMENTED: %s in [%s:%d] %s()\n",                \
          msg, __FILE__, __LINE__, __FUNCTION__);                       \
  exit(1);                                                              \

#define LOG(message) \
    printf("[%s:%d] %s\n", __FILE__, __LINE__, message)

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define SWAP(a, b) do {                         \
    typeof(a) tmp = (a);                        \
    (a) = (b);                                  \
    (b) = tmp;                                  \
  } while (0)

#define UNUSED(x) ((void)(x))

#if defined(__GNUC__)
#define DEPRECATED(msg) __attribute__((deprecated(msg)))
#define INF (__builtin_inf())
#elif defined(_MSC_VER)
#define INF (_Inf)
#define DEPRECATED(msg) __declspec(deprecated(msg))
#else
#define DEPRECATED(msg)
#endif

#define LIKELY(x)   __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

#define COMPOUND_LITERAL_INT_VOIDPTR(x)          ((void *)&(int){(x)})
#define COMPOUND_LITERAL_CHAR_VOIDPTR(x)         ((void *)&(char){(x)})
#define COMPOUND_LITERAL_FLOAT_VOIDPTR(x)        ((void *)&(float){(x)})
#define COMPOUND_LITERAL_DOUBLE_VOIDPTR(x)       ((void *)&(double){(x)})
#define COMPOUND_LITERAL_LONG_VOIDPTR(x)         ((void *)&(long){(x)})
#define COMPOUND_LITERAL_LONGLONG_VOIDPTR(x)     ((void *)&(long long){(x)})
#define COMPOUND_LITERAL_UNSIGNEDCHAR_VOIDPTR(x) ((void *)&(unsigned char){(x)})
#define COMPOUND_LITERAL_UNSIGNEDINT_VOIDPTR(x)  ((void *)&(unsigned int){(x)})
#define COMPOUND_LITERAL_UNSIGNEDLONG_VOIDPTR(x) ((void *)&(unsigned long){(x)})
#define COMPOUND_LITERAL_SIZET_VOIDPTR(x)        ((void *)&(size_t){(x)})

#endif // DEV_UTILS_H
