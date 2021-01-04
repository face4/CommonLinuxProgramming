#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void do_cat(int fd);
static void die(const char *s);

int main(int argc, char *argv[]){
    if(argc < 2){
        // fprintf(stderr, "%s: file name not given\n", argv[0]);
        // exit(1);
        do_cat(0);
    }
    for(int i = 1; i < argc; i++){
        int fd = open(argv[i], O_RDONLY);
        if(fd < 0)  die(argv[i]);
        do_cat(fd);
        if(close(fd) < 0)   die(argv[i]);
    }
    exit(0);
}

#define BUF_SIZE 2048

static void do_cat(int fd){
    unsigned char buf[BUF_SIZE];
    int n;

    for(;;){
        n = read(fd, buf, sizeof buf);
        if(n < 0)   exit(1);
        if(n == 0)  break;
        if(write(STDOUT_FILENO, buf, n) < 0)    exit(1);
    }
}

static void die(const char *s){
    perror(s);
    exit(1);
}