#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv)
{
 
	int pid=0;
 
	int add[2];
	int sous[2];
	int mult[2];
 
	char commande[500]="";
	int nb1=0;
	int nb2=0;
 
	pipe(add);
	pipe(sous);
	pipe(mult);
 
 
 
 
	pid=fork();
    if(pid==0)
    {
 
		dup2(add[0],0);
		close(add[1]);
		execvp("add",NULL);
		printf("Si add, a raté \n");
		return -1;
    }
 
 
	pid=fork();
    if(pid==0)
    {
		dup2(sous[0],0);
		close(sous[1]);
		execvp("sous",NULL);
		printf("Si sous, a raté \n");
		return -1;
    }
 
 
	pid=fork();
    if(pid==0)
    {
		dup2(mult[0],0);
		close(mult[1]);
		execvp("mult",NULL);
		return -1;  
    }
 
 
	puts("");
	while(1){
 
 
		close (add[0]);
		close (sous[0]);
		close (mult[0]);
 
		scanf("%s %d %d",commande,&nb1,&nb2);
 
		if(strcmp(commande,"add")==0){
			dup2(add[1],1);
			printf("%d\n",nb1);
			printf("%d\n",nb2);
         
             
		}
 
		else if(strcmp(commande,"sous")==0){
			dup2(sous[1],1);
			printf("%d\n",nb1);
			printf("%d\n",nb2);
 
		}
 
		else if(strcmp(commande,"mult")==0){
			dup2(mult[1],1);
			printf("%d\n",nb1);
			printf("%d\n",nb2);
         
		}
 
	}
 
 
	return 0;
 
}