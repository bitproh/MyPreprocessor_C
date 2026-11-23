#include "header.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./my_preprocessor input_file.c\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *temp = tmpfile();
    FILE *output = fopen("output.i", "w");
    if (!input || !temp || !output) {
        printf("Error opening files\n");
        if (input) fclose(input);
        if (temp) fclose(temp);
        if (output) fclose(output);
        return 1;
    }

    comment_removal(input, temp);
    rewind(temp);
    macro_handler(temp, output);

    fclose(input);
    fclose(temp);
    fclose(output);
    return 0;
}