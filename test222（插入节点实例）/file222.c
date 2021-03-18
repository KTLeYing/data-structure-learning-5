void linsert(PERSON *p)
{
     PERSON *pa,*pb;
	 pb=head;
	 if(head==NULL)
		 head=p;
	 else
	 {
	     while(pb);
		 {
		    pa=pb;
            pb=pb->next;
		 }
		 pa->next=p;
	 }
	 p->next=NULL;
}