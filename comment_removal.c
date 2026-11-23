#include "header.h"

void comment_removal(FILE *input, FILE *output){
    int ch, next;

    while((ch=fgetc(input))!= -1){
        if(ch=='/'){
            next=fgetc(input);
            //for single line comments.. searching for next '/'
            if(next =='/'){ //the  second char next to / determines whether it is single line or multi line comment.
                // if it is / next, it is a single line comment. If it is *, then it is a multi line comment.
                while((ch=fgetc(input)) != -1 && ch != '\n'); // skipping everything till comment closes.

                if(ch=='\n'){
                    fputc('\n',output);
                }

            }
            else if(next == '*'){
                //multiline comment, searching for next '*/'
                while((ch=getc(input)) != -1){
                    if(ch=='\n'){
                        fputc('\n',output);
                    }
                    if(ch == '*'){
                        next = fgetc(input);
                        if(next == '/'){
                                 break;
                        }
                        if(next!=-1){
                            fseek(input,-1,SEEK_CUR);
                        }
                    }
                }
            }else{
                fputc('/',output);
                if(next!= -1){
                    fseek(input,-1,SEEK_CUR);
                }
            }
        }
        else{
            fputc(ch,output);
        }
    }
}