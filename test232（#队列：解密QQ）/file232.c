#include <stdio.h>
int main()
{ 
    int head,tail,q[100],i,n;
	printf("please input all the number:");
	scanf("%d",&n);
	printf("please input the numbers:");
    for(i=0;i<n;i++)            //���벢��ʼ������
		scanf("%d",&q[i]);
	head=0;
	tail=n;       //tailָ���β�ĺ�һ��λ��
	while(head<tail)
	{
	   printf("%d ",q[head]);    //��ӡ����
	   head++;       //���׳���
	   q[tail]=q[head];          //�¶��׵�����ӵ���β
	   tail++;     //�ٽ����׳���
	   head++;
	}
	return 0;
}

  //���׳���->�¶��׼ӵ���β->���µĶ��׳���....(��������һ��)