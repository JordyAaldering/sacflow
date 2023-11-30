#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <assert.h>
#include <errno.h>
#include <stdio.h>

#define LOG_ERROR(fmt, ...) fprintf(stderr, "%s:%d " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define ASSERT(cond, fmt, ...) if(!(cond)) { LOG_ERROR(fmt, ##__VA_ARGS__); assert(cond); }

#endif /* _DEBUG_H_ */
