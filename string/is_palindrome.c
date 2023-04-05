#include <string.h>
#include <ctype.h>

bool isPalindrome(char * s){
    int left, right;

    left = 0, right = strlen(s) - 1;
    while (left < right)
    {
        while (left < right && !(isalpha(s[right]) | isdigit(s[right])))
            right--;

        while (left < right && !(isalpha(s[left]) | isdigit(s[left])))
            left++;


        if (tolower(s[left]) != tolower(s[right]))
            return (false);
        left++, right--;
    }

    return (true);
}
