/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCE-1-1-minishell1-quentin.briand
** File description:
** my_str_to_word_array
*/

int is_valid(char c)
{
    if (c == '\n' || c == '\t' || c == ':') return 0;
    return 1;
}

int count_str_split(char const *str)
{
    int word_len = 0;
    int space = 1;
    int str_in_str = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 39 || str[i] == 34) str_in_str = !str_in_str;
        if (is_valid(str[i]) && space) {
            word_len++;
            space = 0;
        }
        if (!is_valid(str[i]) && !space && !str_in_str) {
            space++;
        }
    }
    return word_len;
}

int my_word_length(char const *str, int x)
{
    int length = 0;
    int quote = 0;
    for ( ; str[x] != '\0' && (is_valid(str[x]) || quote); x++, length++) {
        if (str[x] == 39 || str[x] == 34) quote = 1;
    }
    return quote ? length - 2 : length;
}

int my_count_non_alpha(int x, char const *str)
{
    int	length = 0;
    for ( ; !is_valid(str[x]); x++, length++);
    return length;
}

char **my_str_to_word_array(char const *str)
{
    int word_array_length = count_str_split(str);
    int last_word = my_count_non_alpha(0, str);
    char **my_array = malloc(sizeof(char*) * (word_array_length + 1));
    if (!my_array) exit(84);
    for (int i = 0; i < word_array_length; i++) {
        int word_len = my_word_length(str, last_word);
        my_array[i] = malloc(sizeof(char) * (word_len + 1));
        if (!my_array[i]) exit(84);
        for (int local = 0; local < word_len; local++) {
            int cond = (str[last_word] == 39 || str[last_word] == 34) ? 1 : 0;
            my_array[i][local] = str[last_word + local + cond];
        }
        my_array[i][word_len] = '\0';
        last_word += word_len;
        last_word += my_count_non_alpha(last_word, str);
    }
    my_array[word_array_length] = 0;
    return my_array;
}
