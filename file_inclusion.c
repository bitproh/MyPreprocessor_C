#include "header.h"

void file_inclusion(FILE *input, FILE *output)
{
    char line[1024];

    rewind(input);
    while (fgets(line, sizeof(line), input) != NULL) {
        char *p = line;
        while (*p == ' ' || *p == '\t') {
            p++;
        }

        if (strncmp(p, "#include", 8) == 0 && (p[8] == ' ' || p[8] == '\t' || p[8] == '"' || p[8] == '<')) { // finding the name of the file
            p += 8;
            while (*p == ' ' || *p == '\t') {
                p++;
            }

            char end = (*p == '"') ? '"' : ((*p == '<') ? '>' : 0); //checking whether it is " " or < >
            if (end != 0) {
                p++;
                char fname[256];
                int i = 0;
                while (*p != '\0' && *p != end && *p != '\n' && i < 255) {
                    fname[i++] = *p++;
                }
                fname[i] = '\0';

                FILE *inc = fopen(fname, "r");
                if (inc != NULL) {
                    char inc_line[1024];
                    while (fgets(inc_line, sizeof(inc_line), inc) != NULL) {
                        fputs(inc_line, output);
                    }
                    fclose(inc);
                    continue;
                } else {
                    printf("Cannot open %s\n", fname);
                }
            }
        }

        fputs(line, output);
    }
}