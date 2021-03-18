#include <stdio.h>
int main()
{
   FILE *fp;
   char str[80];
   if((fp=fopen("test.txt","at"))==NULL)
   {
      printf("Cannot open file!\n");
	  exit(1);
   }
   printf("ÇëÊäÈë×Ö·û´®:\n");
   do
   {
       gets(str);
	   fputs(str,fp);
	   fputc('\n',fp);
   }while(*str!=NULL);
   fclose(fp);
   return 0;
}