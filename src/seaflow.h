#ifndef _SEAFLOW_H_
#define _SEAFLOW_H_

#include <stdio.h>

#define AS_A(_)
#define I_WANT(_)
#define SO_THAT(_)

#define FEATURE(...)                                                \
    int main(int argc, char* argv[])                                \
    {                                                               \
        int choice;                                                 \
        if (argc != 2) {                                            \
            printf("Usage: %s <number>\n", argv[0]);                \
            return 1;                                               \
        }                                                           \
        if (sscanf(argv[1], "%d", &choice) != 1) {                  \
            printf("Expected a number, got '%s'\n", argv[1]);       \
            return 1;                                               \
        }

#define BACKGROUND(_)

#define SCENARIO(name)                                              \
    } /* Close previous scenario */                                 \
                                                                    \
    if (choice-- == 0) {                                            \
        printf("Scenario: " #name "\n");

#define GIVEN(func, ...) func(__VA_ARGS__);
#define WHEN(func, ...) func(__VA_ARGS__);
#define THEN(func, ...) func(__VA_ARGS__);

#define ENDFEATURE(...)                                             \
        if (choice >= 0) {                                          \
            printf("Choice %d does not exist\n", choice);           \
            return 1;                                               \
        }                                                           \
        return 0;                                                   \
    }

#endif /* _SEAFLOW_H_ */
