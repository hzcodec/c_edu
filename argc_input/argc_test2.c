/*
   Auther:       Heinz Samuelsson
   Date:         2014-03-18
   File:         argc_test2.c
   Reference:    -
   Description:  getpwuid - Get user information for user ID.
                 The function shall return a pointer to a 'struct passwd'.
                 getuid - Returns the real user ID.
 */


#include <pwd.h>      // getpwuid
#include <unistd.h>   // getuid
#include <stdio.h>


int main(int argc, char** argv) {

    struct passwd *pw;
    int    uid;

    if (pw != NULL) {
        printf("NULL\n");
    }

    pw = getpwuid(getuid());
    printf("pw_name:  %s\n",  pw->pw_name);
    printf("pw_gecos: %s\n",  pw->pw_gecos);
    printf("pw_dir:   %s\n",  pw->pw_dir);
    printf("pw_gid:   %d\n",  pw->pw_gid);
    printf("pw_shell: %s\n",  pw->pw_shell);
    printf("pw_uid:   %d\n\n",pw->pw_uid);

    if (-1 == (uid = getuid()))
        printf("Error\n");
    else
        printf("UID: %d\n",getuid());

    char* username;
    username = getlogin();
    printf("Username: %s\n",username);

    return 0;
}

