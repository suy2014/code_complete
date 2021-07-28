bool wordPattern(char * pattern, char * str){
    char* pattern_in_str[26];
    int patten_num;
    char *p;
    int index = 0;

    while(index < 26) {
        pattern_in_str[index] = (char *)calloc(1, 100 * sizeof(char));
        index++;
    }
    patten_num = strlen(pattern);
    for (int i = 0; i < patten_num; i++) {
        p = str;
        while ( (*p !=' ') && (*p != '\0')) {
            printf(" %p %c \n", p, *p);
            p++;
        }
        if (*p == ' ') {
            *p++ = '\0';
        }
        if (strlen(str) == 0) {
            return false;
        }

        if (strlen(pattern_in_str[pattern[i] - 'a']) == 0) {
            for (int j = 0; j < 26; j++) {
                if ((j != pattern[i] - 'a') && (strlen(pattern_in_str[j]) != 0)) {
                    if (strcmp(pattern_in_str[j], str) == 0) {
                        return false;
                    }

                }
            }
            strcpy(pattern_in_str[pattern[i] - 'a'], str);
        } else {
            if (strcmp(pattern_in_str[pattern[i] - 'a'], str) != 0) {
                return false;
            }
        }
        str = p;
    }
    if (strlen (str) > 0) {return false;}
    return true;

}
