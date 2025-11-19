#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pass[100];
    int hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';   
    
    
    if(strlen(pass) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    
    for(int i = 0; i < strlen(pass); i++) {
        if(isupper(pass[i]))
            hasUpper = 1;
        else if(isdigit(pass[i]))
            hasDigit = 1;
        else if(pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%')
            hasSpecial = 1;
    }

    
    if(hasUpper && hasDigit && hasSpecial)
        printf("Strong Password!\n");
    else
        printf("Weak Password!\n");

    return 0;
}

