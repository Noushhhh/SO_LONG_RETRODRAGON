
int ft_strlen(char *str){
	for(int i = 0; str[i]; i++);
	return (i);
}