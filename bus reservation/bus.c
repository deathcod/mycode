#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char detail[11][100]={"name:\t\t\t\t\t","passenger Identification number:\t","Passanger Address:\t\t\t",
"Passanger contact number:\t\t","total no. luggage:\t\t\t","luggage weight:\t\t\t\t","destination:\t\t\t\t","travel start date:\t\t\t",
"travel return date:\t\t\t","booking id:\t\t\t\t"};
void passenger_Details()
{
	getchar();
	static int fuk=1;
	int x,i;
	char s[10][100];
	for(i=0;i<=8;i++)
	{
		printf("%s",detail[i]);
		scanf("%[^\n]%*c",s[i]);
	}
	int booking_id=fuk;
	fuk++;
	FILE *fp=fopen("code.txt","a");
	i=0;
	while(i<=8)
		if (i==1)
			fprintf(fp, "<%s>|",s[i++]);
		else
			fprintf(fp, "%s|",s[i++]);
	fprintf(fp, "$%d$|",booking_id);
	putc('\n',fp);
	fclose(fp);
}
int Search_Passenger(int id)
{
	FILE *fp=fopen("code.txt","r");
	char s[100];
	while(fscanf(fp,"%[^\n]%*c",s)!=EOF)
	{
		int i=0,ss=0;
		while(s[i++]!='$');
		while(s[i]!='$')
			ss=ss*10+s[i++]-'0';
		if(ss==id)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
void Search_PassengerID(int id)
{
	FILE *fp=fopen("code.txt","r");
	char s[100];
	int flag=0;
	printf("*******************************************************************************\n\n");
	while(fscanf(fp,"%[^\n]%*c",s)!=EOF)
	{
		int i=0,ss=0;
		while(s[i++]!='<');
		while(s[i]!='>')
			ss=ss*10+s[i++]-'0';
		
		if(ss==id)
		{
			int j=0;
			for( i=0;i<=9;i++)
			{
				printf("\t%s",detail[i]);
				while(isalpha(s[j]) || s[j]==' ' || isdigit(s[j]))
					putchar(s[j++]);
				while(!(isalpha(s[j]) || s[j]==' ' || isdigit(s[j])))j++;
				printf("\n");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("NO FOUND\n");
	printf("\n*******************************************************************************\n\n");
}
int main(int argc, char const *argv[])
{
	while(1)
	{
		int x;
		printf("choose from below:\n1)Passanger Details\n2)Passanger Queue\n3)Search Passanger\n4)Exit\n");
		while(scanf("%d",&x) && (x<1 || x>4))
		{
			printf(" invalid input\n");
		}
		switch (x)
		{
			case 1:
			{
				int flag=0;
				while(1)
				{
					printf("choose from below:\n1)add Passanger Details\n2)search Psssanger using passengerid\n3)show all passanger details\n4)Exit\n");
					while(scanf("%d",&x) && (x<1||x>4))
					printf("invalid input\n");
					switch (x)
					{
						case 1:
						{
							passenger_Details();
							break;
						}
						case 2:
						{
							printf("enter the passanger id\n");
							scanf("%d",&x);
							Search_PassengerID(x);
							break;
						}
						case 3:
						{
							char s[100];
							FILE *fp=fopen("code.txt","r");
							printf("*******************************************************************************\n\n");
							while(fscanf(fp,"%[^\n]%*c",s)!=EOF)
								printf("%s\n",s );
							fclose(fp);
							printf("\n*******************************************************************************\n\n");
							break;
						}
						default:
							flag=1;
					}
					if (flag==1)
						break;
				}
			}
			case 2:
			{
				printf("get the passanger in the queue\n");
				//Passanger_Queue();
				break;
			}
			case 3:
			{
				printf("enter the search booking id \n");
				int x;
				scanf("%d",&x);
				printf("%s",Search_Passenger(x)?"--->FOUND<---\n":"--->NOT FOUND<---\n");
				break;
			}
			default:
			{
				printf("exit\n");
				exit(0);
			}
		}
	}
	return 0;
}
/*int main(int argc, char const *argv[])
{
	int x,ret=0;
	do{
		ret=scanf("%d",&x);
		if(ret==0)
		printf("invalid input\n");
	}while(ret==0);

	return 0;
}*/