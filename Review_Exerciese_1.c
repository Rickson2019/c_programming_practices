#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include<assert.h>

#define CHECK(PRED) printf("%s...%s\n",(PRED)?"passed":"FAILED",#PRED);

/*Written by JUDAO ZHONG*/
size_t find_first(const char s[], int c){
	size_t i = 0;
	while(s[i] != '\0'){
		if(s[i]==c){
			return i;

		}
		
		i++;
		
	}
	return (size_t) -1;
}

void replace_first(int a[], size_t n, int oldint, int newint){
		n = 0;
		/*Not Sure if the last index is a null*/
		while(a[n] != '\0'){
			if((a[n] == oldint)){
				a[n] = newint;
				break;
			}
			n++;
		}
		
}

void replace_last(char s[], int oldc, int newc){
	size_t i=0;
	size_t j=0;
	for(i=0; s[i]!= '\0'; i++){
		if(s[i] == oldc){
			j=i;
		}
	}
	s[j]=newc;
}

size_t count(const int a[], size_t n, int x){
	/*c stands for 'counter'*/
	size_t c=0;
	size_t i=0;
	for(i=0; i<n;i++ ){
		if(a[i] == x){
			c++;
		}
	}
	return c;
}

/*Tested by JUDAO ZHONG*/
int main(void){
	
	char test_s[] = "we are struggling every day!\0";
	int test_a[] = {1,3,5,3,3,4,0,7,5,8,5};
	int test_a_2[] = {1,3,5,3,3,4,0,7,5,8,5};
	/*
	size_t find_first_result = 0;
	find_first_result=;
	printf("%ld",find_first_result);
	*/
	CHECK(find_first(test_s,'w') == 0);
	CHECK(find_first(test_s,'a') == 3);
	CHECK(find_first(test_s,'g') == 11);
	CHECK(find_first(test_s,' ') == 2);
	
	
	replace_first(test_a,11,5,9);
	replace_first(test_a,11,3,9);
	CHECK(test_a[2]==9);
	CHECK(test_a[1]==9);
	
	replace_last(test_s,'y','z');
	CHECK(test_s[26]== 'z');
	
	
	CHECK(count(test_a_2,11,3)==3);
	CHECK(count(test_a_2,11,1)==1);
	
	
	return 0;
}