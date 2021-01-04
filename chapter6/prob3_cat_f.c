#include<stdlib.h>
#include<stdio.h>

#define BUF_SIZE 2048

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        FILE *f;
        int c;

        f = fopen(argv[i], "r");
        
        if(!f){
            perror(argv[i]);
            exit(1);
        }

        char *buf[BUF_SIZE];
        for(;;){
            int nread = fread(buf, 1, sizeof buf, f);
            if(ferror(f))   exit(1);
            int nwrote = fwrite(buf, 1, nread, stdout);
            if(nwrote < nread)  exit(1);
            if(nread < BUF_SIZE)    break;
        }

        if(fclose(f) != 0)  exit(1);
    }
}