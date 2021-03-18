#include <stdio.h>
int main()
{
   FILE *fp;
   char ch;
   if((fp=fopen("test.txt","rt"))==NULL)
   {
       printf("Cannot open the file!\n");
	   exit(1);
   }
   while((ch=fgetc(fp))!=EOF)
     putchar(ch);
   fclose(fp);
   return 0;
}