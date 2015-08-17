// Code developed by Zed A. Shaw
// Appropriated from http://c.learncodethehardway.org/book/ex20.html

//#define NDEBUG // if defined; no debug()

#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG //if NO DEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

//M is the formatted string, ... and __VA_ARGS__ are the arguments for the f-string
//## ensures that you can have 0 argruments for the f-string
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s: %s: %d: errno: %s) " M "\n", __FILE__, __func__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s: %s: %d: errno: %s) " M "\n", __FILE__, __func__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s: %s: %d) " M "\n", __FILE__, __func__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) {log_err(M, ##__VA_ARGS__); errno=0; goto error; }
#define check_mem(A) check((A), "Out of memory")

#define sentinel(M, ...) {log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_debug(A, M, ...) if(!(A)) {debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
