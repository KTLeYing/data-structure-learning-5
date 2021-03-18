DelecteList(PERSON *head)
   PERSON *DElem,*next;
   DElem=head;
   while(DElem)
   {
      next=DElem->next;
	  free(DElem);
	  DElem=next;
   }
