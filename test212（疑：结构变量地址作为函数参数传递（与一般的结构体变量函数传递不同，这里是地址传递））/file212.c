#include<stdio.h>
#include<stdlib.h>
struct st
{
	char name[10];
	char age[5];
	char sex[6];
	float score;
};
void out(st stu)
{
   printf("����:%s\n",stu.name);
   printf("�Ա�:%s\n",stu.sex);
   printf("����:%s\n",stu.age);
   printf("����:%f\n",stu.score);
}
void in(st stu)
{
   char score[10];
   printf("please input name:");
   gets(stu->name);
   printf("please input age:");
   gets(stu->age);
   printf("please input sex:");
   gets(stu->sex);
   printf("please input score:");
   gets(stu->score);
   stu->score=atof(score);
}
void main()
{
	struct st s={"LiMing","20","man",87.5};
    out(s);
	in(&s);
	out(s);
}
