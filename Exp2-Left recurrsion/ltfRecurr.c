//findingleft recursion and removing it

#include<stdio.h>
#include<string.h>
#define SIZE 10

int main(){
	char nt, beta, alpha;
	int num, i;
	char production[10][SIZE];
	int idx=3;
	printf("Enter number of production : ");
	scanf("%d",&num);
	printf("Enter the grammer (make sure u have '->' and '|' for multiple outputs) : \n");
	for(i=0; i<num; i++){
		scanf("%s",production[i]);
	}
	
	for(i=0;i<num; i++){
		printf("\nGrammer :- %s", production[i]);
		nt = production[i][0];
		if(nt == production[i][idx]){
			alpha = production[i][idx+1];
			printf(" is left recursive.\n");
			while(production[i][idx]!=0 && production[i][idx]!='|'){ idx++; }
			if(production[i][idx]!=0){
				beta = production[i][idx+1];
				printf("Grammer without left recursion : \n");
				printf("%c->%c%c\'",nt,beta,nt);
				printf("\n%c\'->%c%c\'|%c\n",nt,alpha,nt,nt);
			}
			else{
				printf(" can't be reduced.\n");
			}
		}
		else{
			printf(" is not left recursive.\n");
		}
	}
	return(0);
}