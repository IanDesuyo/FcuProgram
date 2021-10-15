#include <stdio.h>
#include <string.h>

int main() {
    char hello[][13] = {
        "HELLO",
        "HOLA",
        "HALLO",
        "BONJOUR",
        "CIAO",
        "ZDRAVSTVUJTE"
    };

    char Lang[][] = {
        "ENGLISH",  "SPANISH", "GERMAN",
    }

    char text[13];

    while (1)
    {
        scanf("%s", text);
    
        for (int i = 0; i < 6; i++)
        {
            if (!strncmp(text, hello[i], sizeof(hello[i]))) {
                printf("")
            }
        }
        
    }
    


    return 0;
}