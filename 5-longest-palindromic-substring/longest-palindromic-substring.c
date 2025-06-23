void reverse(char* dest, const char* src, int length) {
    for (int i = 0; i < length; ++i) {
        dest[i] = src[length - 1 - i];
    }
    dest[length] = '\0';
}

bool isPalindrome(const char* str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) return false;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);

    char* reversed = (char*)malloc(len + 1);
    reverse(reversed, s, len);
    if (strcmp(reversed, s) == 0) {
        return reversed; 
    }
    free(reversed);

    char* result = (char*)malloc(len + 1);
    result[0] = '\0'; 

    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            if (s[i] != s[j]) {
                if (strlen(result) == 0) {
                    result[0] = s[i];
                    result[1] = '\0';
                }
                continue;
            }

            if (isPalindrome(s, i, j)) {
                int sub_len = j - i + 1;
                if (sub_len > strlen(result)) {
                    strncpy(result, s + i, sub_len);
                    result[sub_len] = '\0';
                }
            }
        }
    }

    return result;
}

