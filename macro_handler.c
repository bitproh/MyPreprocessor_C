//Action plan
//find #define from each line. 
//move pointer to the name of macro and save macro same to macro struct and add count+1
// move pointer to the value of macro and save to struct.
// now rewind the pointer to starting
//after it search for the macro name in the lines of the code, if found strcpy with the value. and print to output file

#include <ctype.h>
#include <string.h>
#include "header.h"

//making a struct to save the name of the macro and its values.

typedef struct{
    char name[64];
    char value[128];
}Macro;


void macro_handler(FILE *input, FILE *output)
{
    Macro macros[100]; //making static memory to store 100 macros.
    int count=0; //for counting macros
    char line[1024]; //max number if lines in code
    
    rewind(input);
    while(fgets(line, sizeof(line),input))
    {//saving each line of code to 'line'
        char *p = line; //giving the base address of each line to a pointer
        while(*p==' ' || *p=='\t')p++; // skipping blank spaces

        if(strncmp(p,"#define",7)!= 0 || (p[7] != ' '&& p[7]!='\t') || count>=100){
             continue;
        }
            p+=7; // skipping define
            while(*p==' '||*p=='\t')p++; //skipping blank spaces

            int n=0;
            while(*p != '\0' && !isspace((unsigned char)*p) && n<63){
                macros[count].name[n++] = *p++; // here we are saving the name of macro to macro.name by letter by letter
            }
            macros[count].name[n]='\0'; // putting last char of name with '\0'

            if(n==0){
                continue; // if no macro name is read, skip to the next line. 
            }

            while(*p == ' ' || *p == '\t') p++; // skipping the space between the name and value

            //reading the macro value and saving it to macro.value

            int v=0;
            while(*p != '\0' && *p != '\n' && *p !='\r' && v<127){ //here we are copying the value to struct until a space, next 
                //line or anything interrupting the value reaches
                macros[count].value[v++] = *p++;

            }
            //we made 128 byte space for a macro, removing unnecesary space here

            while(v>0 && (macros[count].value[v-1] == ' ' || macros[count].value[v-1] == '\t'))
            v--;

            macros[count].value[v]='\0';

            count++;
            // finding #define, saving macro name and value to struct completed

    }
    //replacing the macros with the words inside.
    rewind(input);
    while(fgets(line,sizeof(line),input) != NULL){// running loop from starting to EOF
        char *p = line;
        while(*p == ' ' || *p == '\t'){
            p++; // skipping blank spaces
        }
        if(strncmp(p,"#define",7)==0 && (p[7]==' '|| p[7]=='\t')){
            continue;
        }
        int i=0;
        while(line[i] != '\0'){
            if(isalpha((unsigned char)line[i]) || line[i] == '_'){// checking whether the value is starting with a character or underscore
                char word[64];
                int w = 0;

                while (line[i] != '\0' && (isalnum((unsigned char)line[i]) || line[i] == '_') && w<63){
                    word[w++] = line[i++]; // saving the words to word array.
                }
                word[w]='\0';

                const char *replacement = word;
                for(int m=0; m< count ;m++){
                    if(strcmp(macros[m].name,word)==0){// checking for words to replace with macro and replacing them
                         replacement = macros[m].value;
                         break;
                    }
                }
                fputs(replacement, output);
            }else{
                fputc(line[i++],output);
            }
        }
    }

}