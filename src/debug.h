#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define LOG_ERROR(M, ...) fprintf(stderr, "%s:%d " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define ASSERT(A, M, ...) if(!(A)) { LOG_ERROR(M, ##__VA_ARGS__); assert(A); }

#endif /* _DEBUG_H_ */
