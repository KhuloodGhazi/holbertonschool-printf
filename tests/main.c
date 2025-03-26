#include "../main.h"  /* Include the header file from the root directory */
#include <stddef.h>    /* Add this to define NULL */

int main(void)
{
    /* Running some simple tests with _printf */
    _printf("Let's print a simple sentence.\n");
    _printf("%c", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let's see if the cast is correctly done: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("%%");
    _printf("Should print a single percent sign: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', ".", " 99", " Please wait", '\n');
    _printf("css%ccs%scscscs", 'T', "Test");
    
    /* Testing a larger string */
    char *str = "This is a big string to test!";
    _printf(str);

    /* Testing 'man gcc:' with a big string */
    _printf("man gcc:\n%s", str);

    // Testing with NULL (this should not cause a crash)
    _printf(NULL);

    /* Testing special characters */
    _printf("%c", '\0');
    _printf("%");
    _printf("%!\n");
    _printf("%K\n");

    return 0;
}

