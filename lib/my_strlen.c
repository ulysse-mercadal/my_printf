/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** longeur d une string
*/
/*
void my_putchar(char c)
{
    write(1, &c, 1);
}
*/

int my_strlen(const char *str)
{
    int position = 0;

    while (str[position] != '\0') {
        position ++ ;
    }
    return (position);
}

/*
int main(void)
{
    const char *str = "hello";
    my_strlen(str);
}
*/
