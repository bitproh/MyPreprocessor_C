#include "header.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./my_preprocessor input_file.c\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *stage1 = tmpfile();
    FILE *stage2 = tmpfile();
    FILE *output = fopen("output.i", "w");

    if (!input || !stage1 || !stage2 || !output) {
        printf("Error opening files\n");
        if (input) fclose(input);
        if (stage1) fclose(stage1);
        if (stage2) fclose(stage2);
        if (output) fclose(output);
        return 1;
    }

    comment_removal(input, stage1);
    rewind(stage1);

    file_inclusion(stage1, stage2);
    rewind(stage2);

    macro_handler(stage2, output);

    fclose(input);
    fclose(stage1);
    fclose(stage2);
    fclose(output);
    return 0;
}