#include <string.h>
#include <stdio.h>

enum State {q0,q1,q2,q3};
enum Sigma {a=97,b};
int Delta[4][2]={q1,q0,q1,q2,q1,q3,q1,q0};
char str[100];
int i;
enum Sigma c;

void check(){
	enum State q;
	q = q0;
	while (c == 32) c = str[++i];
		if(c == a || c == b){
			do{
				printf("%c",c);
				q = Delta[q][c-97];
				i++;
				c = str[i];
			}while (c == a || c == b);
			if (q == q3) printf("   YES\n");
			else printf("   NO\n");
		}else if (c != '\0'){
		printf("%-5c    ERROR", c);
		}
}
void main(){
	printf("Nhap xau : ");  fflush(stdin);   gets(str);
	i = 0; c = str[i];
	while (c != '\0'){
		check();
	}
	getch();
}
