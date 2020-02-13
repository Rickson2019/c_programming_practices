#include <stdio.h>
#include <ctype.h>

int count_alpha(FILE *fp){
	int ch=0;
	size_t c=0;
	while((ch = fgetc(fp)) != EOF){
		if(isalpha(ch))
			c++;
	}
	return c;
}

int main(int argc, char *argv[]) {
	int alphaNum;
	FILE *fp;
	fp = fopen(argv[1], "r");
	printf("argc...%d\n",argc);
	alphaNum=count_alpha(fp);
	printf("%d alphabets are in the file\n",alphaNum);

	return 0;
}