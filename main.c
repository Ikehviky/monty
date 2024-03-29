#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define MAX_LINE_LENGTH 1024

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[]) {
    char content[MAX_LINE_LENGTH];
    FILE *file;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(content, MAX_LINE_LENGTH, file) != NULL) {
        bus.content = content;
        counter++;
        execute(content, &stack, counter, file);
    }

    free_stack(stack);
    fclose(file);

    return 0;
}
