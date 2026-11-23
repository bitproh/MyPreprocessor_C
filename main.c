//develop  a preprocessor tool named my preprocessor that processes a c source file by
//removing all comments, file inclusion and macro substitutions. The tool should take a C source file as input and produce a new C source file as output with all comments, file inclusions, and macro substitutions removed..
// the preprocessor should generate an extended source file with a .i extension.

#include "header.h"

int main(int argc, char **argv)
{
    if(argc!=2)
    {
        printf("Usage: ./a.out input_file.c\n");
        return 1;
    }
    FILE *input=fopen(argv[1],"r");
    FILE *output=fopen("output.i","w");
    if(input == NULL){
        printf("cannot open input file\n");
        return 1;
    }
    if(output == NULL){
        printf("cannot open ouptu file\n");
        return 1;
    }
    comment_removal(input,output);

    fclose(input);
    fclose(output);
    return 0;
}