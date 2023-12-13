#include <stdio.h>
#include <stdlib.h>

#include "seaflow.h"

static char *feature_path;
static FILE *feature_pipe;

void open_feature_file(char *feature_name)
{
    // TODO: feature_path = feature_name with spaces replaced with underscored
    // and with .md appended at end
    feature_path = "featurefile.md";

    feature_pipe = fopen(feature_path, "w");
    if (feature_pipe == NULL) {
        fprintf(stderr, "Could not open feature file: %s\n", feature_path);
        exit(1);
    }
}

void write_feature_file(char *contents)
{
    int status = fprintf(feature_pipe, "%s\n", contents);
    if (status < 0) {
        fprintf(stderr, "Could not write to feature file: %s\n", feature_path);
        exit(1);
    }
}

void close_feature_file(void)
{
    int status = fclose(feature_pipe);
    if (status < 0) {
        fprintf(stderr, "Could not close feature file: %s\n", feature_path);
        exit(1);
    }
}
