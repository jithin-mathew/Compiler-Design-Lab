#include<stdio.h>
#include<string.h>

void pm();
void plus();
void div();

int i, ch, j, l,addr=100;
char ex[10], exp0[10], exp1[10], exp22[10], id1[5], op[5], id2[5];

char *strrevv(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void main() {

	while(1) {
		printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch) {

		case 1:
			printf("\nEnter the expression with assignment operator:");
			scanf("%s",exp0);
			l=strlen(exp0);
			exp22[0]='\0';
			i=0;
			while(exp0[i]!='=')
				i++;

			strncat(exp22,exp0,i);
			strrevv(exp0);
			exp1[0]='\0';
			strncat(exp1,exp0,l-(i+1));
			strrevv(exp1);
			printf("Three address code:\ntemp=%s\n%s=temp\n",exp1,exp22);
			break;

		case 2:
			printf("\nEnter the expression with arithmetic operator:");
			scanf("%s",ex);
			strcpy(exp0,ex);
			l=strlen(exp0);
			exp1[0]='\0';

			for(i=0;i<l;i++) {
				if(exp0[i]=='+'||exp0[i]=='-') {
					if(exp0[i+2]=='/'||exp0[i+2]=='*') {
						pm();
						break;
					}
					else {
						plus();
						break;
					}
				}
				else if(exp0[i]=='/'||exp0[i]=='*') {
					div();
					break;
				}
			}
			break;

		case 3:
			printf("Enter the expression with relational operator");
			scanf("%s%s%s",&id1,&op,&id2);
			if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||(strcmp(op,"==")==0)||(strcmp(op,"!=")==0))==0)
			printf("Expression is error");

			else {
				printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
				addr++;
				printf("\n%d\t T:=0",addr);
				addr++;
				printf("\n%d\t goto %d",addr,addr+2);
				addr++;
				printf("\n%d\t T:=1",addr);
			}

			break;
		case 4:
			exit(0);
			break;
		}
	}
}

void pm() {
	strrevv(exp0);
	j=l-i-1;
	strncat(exp1,exp0,j);
	strrevv(exp1);
	printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,exp0[j+1],exp0[j]);
}

void div() {
	strncat(exp1,exp0,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp0[i+2],exp0[i+3]);
}

void plus() {
	strncat(exp1,exp0,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp0[i+2],exp0[i+3]);
}


/*

Example Generation of Three Address Project Output Result

1. assignment
2. arithmetic
3. relational
4. Exit
Enter the choice:1
Enter the expression with assignment operator:
a=b
Three address code:
temp=b
a=temp

1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:2
Enter the expression with arithmetic operator:
a+b-c
Three address code:
temp=a+b
temp1=temp-c

1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:2
Enter the expression with arithmetic operator:
a-b/c
Three address code:
temp=b/c
temp1=a-temp

1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:2
Enter the expression with arithmetic operator:
a*b-c
Three address code:
temp=a*b
temp1=temp-c

1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:2
Enter the expression with arithmetic operator:a/b*c
Three address code:
temp=a/b
temp1=temp*c
1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:3
Enter the expression with relational operator
a
<=
b

100 if a<=b goto 103
101 T:=0
102 goto 104
103 T:=1

1.assignment
2.arithmetic
3.relational
4.Exit
Enter the choice:4


*/



