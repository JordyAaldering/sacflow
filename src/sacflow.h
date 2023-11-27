#ifndef _SACFLOW_H_
#define _SACFLOW_H_

#include <stdio.h>

#define STR(...) #__VA_ARGS__

#define _NUM_ARGS(X,X64,X63,X62,X61,X60,X59,X58,X57,X56,X55,X54,X53,X52,X51,X50,X49,X48,X47,X46,X45,X44,X43,X42,X41,X40,X39,X38,X37,X36,X35,X34,X33,X32,X31,X30,X29,X28,X27,X26,X25,X24,X23,X22,X21,X20,X19,X18,X17,X16,X15,X14,X13,X12,X11,X10,X9,X8,X7,X6,X5,X4,X3,X2,X1,N,...) N
#define NUM_ARGS(...) _NUM_ARGS(0, __VA_ARGS__, 64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)

#define FORWARD_DECL_1(name)      static void name(void);
#define FORWARD_DECL_2(name, ...) static void name(void); FORWARD_DECL_1(__VA_ARGS__)
#define FORWARD_DECL_3(name, ...) static void name(void); FORWARD_DECL_2(__VA_ARGS__)
#define FORWARD_DECL_4(name, ...) static void name(void); FORWARD_DECL_3(__VA_ARGS__)
#define FORWARD_DECL_5(name, ...) static void name(void); FORWARD_DECL_4(__VA_ARGS__)
#define FORWARD_DECL_6(name, ...) static void name(void); FORWARD_DECL_5(__VA_ARGS__)

#define _FORWARD_DECL(N, ...) FORWARD_DECL_ ## N(__VA_ARGS__)
#define FORWARD_DECL(N, ...) _FORWARD_DECL(N, __VA_ARGS__)

#define FEATURE(name, ...)                                          \
    FORWARD_DECL(NUM_ARGS(__VA_ARGS__), __VA_ARGS__)                \
                                                                    \
    void (*scenarios[])(void) = { __VA_ARGS__ };                    \
                                                                    \
    int main(int argc, char* argv[])                                \
    {                                                               \
        if (argc == 1) {                                            \
            return NUM_ARGS(__VA_ARGS__);                           \
        } else {                                                    \
            int choice;                                             \
            if(sscanf(argv[1], "%d", &choice) != 1) {               \
                printf("Expected a number, got '%s'\n", argv[1]);   \
                return 1;                                           \
            }                                                       \
            if (choice < 0 || choice > NUM_ARGS(__VA_ARGS__) - 1) { \
                printf("Choice %d out of bounds", choice);          \
                return 1;                                           \
            }                                                       \
            printf("Running test %d\n", choice);                    \
            scenarios[choice]();                                    \
            return 0;                                               \
        }                                                           \
    }                                                               \
                                                                    \
    void background(void)

#define BACKGROUND

#define SCENARIO(name)                                              \
    } /* Close background, or previous scenario */                  \
                                                                    \
    static void name(void) {                                        \
        printf("Running scenario %s\n", __FUNCTION__);              \
        background();

#define GIVEN(func, ...) func(__VA_ARGS__);
#define WHEN(func, ...) func(__VA_ARGS__);
#define THEN(func, ...) func(__VA_ARGS__);

#endif /* _SACFLOW_H_ */
