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
        
        int count = 0;
        int prev = '\n';

        while((c = fgetc(f)) != EOF){
            if(c == '\n')   count++;
            prev = c;
        }
        
        if(prev != '\n')    count++;

        printf("%s : %d lines\n", argv[i], count);

        fclose(f);
    }
}