#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <shadow.h>
#include <unistd.h>
#include <crypt.h>

int main(int argc, char *argv[])
{
    if ( argc != 3 ) {
        printf("Usage: %s user plain_passwd\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *user = argv[1];
    char *plain_passwd = argv[2];
    
    #ifdef DEBUG
    fprintf(stdout, "Debug:%d: user[%s] plain_passwd[%s]\n", __LINE__, user, 
            plain_passwd);
    #endif

    // Obtain the user record from the password database
    struct spwd *shadow_entry;
    if ( (shadow_entry = getspnam(user)) == NULL ) {
        fprintf(stderr, "Error: Unknown user `%s'\n", user);
        exit(EXIT_FAILURE);
    }

    // Encrypt the supplied password
    char *enc_passwd;
    if ( (enc_passwd = crypt(plain_passwd, shadow_entry->sp_pwdp)) == NULL ) {
        fprintf(stderr, "Error: \n");
        exit(EXIT_FAILURE);
    }
    #ifdef DEBUG
    fprintf(stdout, "Debug:%d: enc_passwd[%s]\n", __LINE__, enc_passwd);
    #endif
    
    // Compare our encrypted password with the shadow entry
    if ( strcmp(enc_passwd, shadow_entry->sp_pwdp) != 0 ) {
        #ifdef DEBUG
        fprintf(stdout, "Debug:%d: Failed authentication\n", __LINE__);
        #endif
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
