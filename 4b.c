#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
    pid_t pid=fork();
    if(pid<0){
        printf("error\n");
    }
    else if(pid==0){
        if(execl("4btextinterpreter","test","myarg1","myarg2","myarg4",(char *)0)<0)
            printf("error\n");
        if(waitpid(pid,NULL,0)<0)
            printf("error\n");
    }
    return 0;
}