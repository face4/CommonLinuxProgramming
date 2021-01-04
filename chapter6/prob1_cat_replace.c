#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        FILE *f;
        int c;

        f = fopen(argv[i], "r");
        
        if(!f){
            perror(argv[i]);
            exit(1);
        }
        
        while((c = fgetc(f)) != EOF){
            switch(c){
                case '\t':
                    if(fputs("\\t", stdout) < 0)    exit(1);
                    break;
                case '\n':
                    if(fputs("$\n", stdout) < 0)    exit(1);
                    break;    
                default:
                    if(putchar(c) < 0)  exit(1);
            }
        }

        fclose(f);
    }
}