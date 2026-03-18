#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int dollar=0;
int number=0;
int check=0;



void mycat(int descriptor){
    char buf;
    int bytes_read;
    int count=1;

    int save=check;
    check=1;

    int i=1;
    
    while ((bytes_read= read(descriptor,&buf,count))>0){
        

        if (buf=='\n' && check && save){
            continue;
        }

        if (check==1 && buf != '\n'){
            if(number){
                dprintf(STDOUT_FILENO, "%d\t", i++);
            }
            check=0;
        }

        if (buf == '\n'){
            if (number && check == 1) {
               dprintf(STDOUT_FILENO, "%d\t", i++);
            }
             if (dollar){
                write(STDOUT_FILENO,"$",count);
                
             }
             check=1;
        }
        else{
            check=0;
        }

        write(STDOUT_FILENO, &buf, count);

        
    }

    if (check == 0) {
        if (dollar) {
            write(STDOUT_FILENO, "$", 1);
        }
    write(STDOUT_FILENO, "\n", 1);
}
    
}

int main(int argc, char* argv[]){

    int descriptor;
    int dest;
    

    if (argc==1)
    {
        printf("no argument\n"); 
    
    }
    else {

        for (int i = 1; i < argc; i++) {
                if (argv[i][0] == '-') 
                {
                    for (int j = 1; argv[i][j] != '\0'; j++) 
                    {
                        if      (argv[i][j] == 'e') dollar = 1;
                        else if (argv[i][j] == 'n') number = 1;
                        else if (argv[i][j] == 's') check= 1;
                        else {
                            printf("error");
                            return 1;
                        }
                    }
                }
            }


        while(argc !=1){

            --argc;
            if (argv[argc][0] == '-') { 
            continue;
            }

            descriptor=open(argv[argc],O_RDONLY);

            if(descriptor<0){
                printf("%s:No such File or directory\n", argv[argc]);
            }
            else{
                    //=argv[argc];
                    mycat(descriptor);
                    
                }

        }
    }
    
    

    close(descriptor);
    
}