#include <stdio.h>
void encrypt()
{
	int flag;
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	int ch1;
	int ch2;
	fp=fopen("file1.txt","r");
	fp1=fopen("file2.txt","r");
	fp2=fopen("steg.txt","w");
	if(fp==NULL)
	{
		printf("error in opening file 1");
	}
	if(fp1==NULL)
	{
		printf("error in opening file 2");
	}
	if(fp2==NULL)
	{
		printf("error in opening file 3");
	}
	/*	
	while(!feof(fp) || !feof(fp1))
		{
			fgetc(fp,"%c", ch1);
			fgetc(fp1,"%c", ch2);
			fprintf(fp2, ch1);
			fprintf(fp2, ch2);
			fp++;
			fp1++;
		} 
	*/
	do
	{
		ch1=fgetc(fp);
		ch2=fgetc(fp1);
		if(feof(fp))
		{
			flag=1;
			break;
		}
		if(feof(fp1))
		{
			flag=2;
			break;
		}	
		fputc(ch1,fp2);
		fputc(ch2,fp2);
	} while(1);
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
}

void decrypt()
{
	int flag;
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	int ch1;
	int ch2;
	fp=fopen("file1.txt","w+");
	fp1=fopen("file2.txt","w+");
	fp2=fopen("steg.txt","r+");
	if(fp==NULL)
	{
		printf("error in opening file 1");
	}
	if(fp1==NULL)
	{
		printf("error in opening file 2");
	}
	if(fp2==NULL)
	{
		printf("error in opening file 3");
	}
	/*	
	while(!feof(fp) || !feof(fp1))
		{
			fgetc(fp,"%c", ch1);
			fgetc(fp1,"%c", ch2);
			fprintf(fp2, ch1);
			fprintf(fp2, ch2);
			fp++;
			fp1++;
		} 
	*/
	do
	{
		ch1=fgetc(fp2);
		ch2=fgetc(fp2);
		if(feof(fp2))
		{
			break;
		}
		if(fp)
		fputc(ch1, fp);
		fputc(ch2, fp1);
	} while(1);
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
}

int main()
{
	int choice;
	printf("Make a choice:\n1. Encode \n2. Decode");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		encrypt();
		break;

		case 2:
		decrypt();
		break;

		default:
		printf("invalid case");
	}

}
