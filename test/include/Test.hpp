#include <assert.h>

#define RET_IF_CMP_FAIL(x,y) \
if (x == y ){}else{\
    Log::error("Failed to == on line:"); \
    Log::error(String::convertToString(__LINE__)); \
    return false; \
}

#define RET_IF_NOT_CMP_FAIL(x,y) \
if (x != y ){}else {\
    Log::error("Failed to != on line:"); \
    Log::error(String::convertToString(__LINE__)); \
    return false; \
}
