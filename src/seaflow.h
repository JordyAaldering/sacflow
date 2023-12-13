#ifndef _SEAFLOW_H_
#define _SEAFLOW_H_

#include <stdio.h>

extern void open_feature_file(char *feature_name);
extern void write_feature_file(char *contents);
extern void close_feature_file(void);

#define AS_A(_)
#define I_WANT(_)
#define SO_THAT(_)

#define FEATURE(...)                                                    \
    int main(int argc, char* argv[])                                    \
    {                                                                   \
        int choice;                                                     \
        if (argc != 2) {                                                \
            fprintf(stderr, "Usage: %s <number>\n", argv[0]);           \
            return 1;                                                   \
        }                                                               \
        if (sscanf(argv[1], "%d", &choice) != 1) {                      \
            fprintf(stderr, "Expected a number, got '%s'\n", argv[1]);  \
            return 1;                                                   \
        }                                                               \
        open_feature_file(#__VA_ARGS__);

#define BACKGROUND(_)

#define SCENARIO(name)                                                  \
        } /* Close previous scenario */                                 \
        if (choice-- == 0) {                                            \
            printf("Scenario: " #name "\n");

#define GIVEN(func, ...) write_feature_file("Given: " #func " " #__VA_ARGS__); func(__VA_ARGS__);
#define WHEN(func, ...)  write_feature_file("When: " #func " " #__VA_ARGS__);  func(__VA_ARGS__);
#define THEN(func, ...)  write_feature_file("Then: " #func " " #__VA_ARGS__);  func(__VA_ARGS__);
#define AND(func, ...)   write_feature_file("And: " #func " " #__VA_ARGS__);   func(__VA_ARGS__);

#define ENDFEATURE(...)                                                 \
        close_feature_file();                                           \
        if (choice >= 0) {                                              \
            printf("Choice %s does not exist\n", argv[1]);              \
            return 1;                                                   \
        }                                                               \
        return 0;                                                       \
    }

#endif /* _SEAFLOW_H_ */
