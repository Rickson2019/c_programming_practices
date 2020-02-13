#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#define CHECK(PRED) printf("%s...%s\n",(PRED)?"passed":"FAILED",#PRED);

/*Written by JUDAO ZHONG*/
size_t count_alpha(const char s[]){
	size_t i = 0;
	size_t c = 0;
	while(s[i] != '\0'){
		if(isalpha(s[i])){
			c++;

		}
		i++;
	}
	return c;
}

int all_digits(const char s[]){
		size_t i = 0;

	while(s[i] != '\0'){
		if(isdigit(s[i])){
			i++;
		}
		if(!isdigit(s[i]))
			break;
		
	}
	return 0;
		
}

void lowercase_copy(char dest[], const char src[]){
	size_t i = 0;
	for(i=0;src[i] != '\0';i++){
		dest[i]=tolower(src[i]);
	}
	dest[i]='\0';
}

void reverse_copy(char dest[], const char src[]){
	/*dest[strlen(src)+1];*/
	size_t i = strlen(src);
	size_t j = 0;
	for(i = strlen(src)-1; i != 0; i--){
		dest[j]=src[i];
		j++;
	}
}

void ltrim_copy(char dest[], const char src[]){
	
	size_t i = 0;
	size_t j = 0;
	size_t temp = 0;
	/*for(i = 0; i != '\0'; i++)*/
	/*for(i = 0; i < strlen(src); i++)*/
	while(src[i] != '\0'){
			
		while(isspace(src[temp]) || temp!=(size_t)(-1)){
			temp++;
			if(!isspace(src[temp])){
				i=temp;
				temp =(size_t)(-1);
				
			}
		}
			dest[j]=src[i];
			i++;
			j++;
		
	}
}

int is_valid_id(const char s[]){
	size_t i = 0;
	size_t c = 0;
	while(s[i] != '\0'){
		if(!isspace(s[i])){
			c++;
		}
		
		if(s[0] != 'A' && s[0] != 'a')
			return 0;

		if(i>0 && !isdigit(s[i]))
			return 0;
		i++;
	}
	if(c!=9)
		return 0;
	return 1;
}

int is_valid(const char s[]){
	size_t i = 0;
	size_t c = 0;
	while(s[i] != '\0' && s[0] != '-'){
		if(isalpha(s[i]))
			c++;
		else if(s[i] == '-')
			c++;
		else
			return 0;
		i++;
	}
	if(c < 2 || c > 19 || s[i-1]=='-')
		return 0;
	return 1;
}

/*Tested by JUDAO ZHONG*/
int main(void){
	
	char test_s[] = "StRuGG1iNg\0";
	char test_s_2[] = "13533407585\0";
	char test_s_3[] = "         Leading Spaces shaLL not Live";
	char out_test_s[20]; 
	char out_test_s_2[1024];
	char out_test_s_3[30];
	
	
	/*
	int test_a[] = {1,3,5,3,3,4,0,7,5,8,5};
	int test_a_2[] = {1,3,5,3,3,4,0,7,5,8,5};
	replace_last(test_s,'y','z');
	CHECK(test_s[26]== 'z');
	
	
	CHECK(count(test_a_2,11,3)==3);
	CHECK(count(test_a_2,11,1)==1);
	*/
	CHECK(count_alpha(test_s) == 10);
	CHECK(count_alpha(test_s) == 9);
	
	CHECK(all_digits(test_s)==0);
	CHECK(all_digits(test_s_2)==1);
	
	lowercase_copy(out_test_s,test_s);
	
	printf("ORIGINAL...%s\n",test_s);
	/*Where did the [] come from*/
	printf("tolower....%s\n",out_test_s);
	
	
	reverse_copy(out_test_s_2,test_s);
	printf("Original...%s\n",test_s);
	printf("Reversed...%s\n",out_test_s_2);
	
	
	printf("Original...%s\n",test_s_3);
	ltrim_copy(out_test_s_3,test_s_3);
	printf("Original...%s\n",test_s_3);
	printf("Trimmed...%s\n",out_test_s_3);
	
	CHECK(is_valid_id("A01177493")==1);
	CHECK(is_valid_id("A0117749AB")==1);
	CHECK(is_valid_id("A011774934")==1);
	CHECK(is_valid_id("A0117A749")==1);
	
	CHECK(is_valid("-lol")==1);
	CHECK(is_valid("lol-")==1);
	CHECK(is_valid("A011")==1);
	CHECK(is_valid("I-would-Say-I-am-Good-At-C-now")==1);
	CHECK(is_valid("I-am-Good-At-C-now")==1);
	return 0;
}