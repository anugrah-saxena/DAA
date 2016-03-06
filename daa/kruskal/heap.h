void swap(int x,int y,int **list)
{
   int temp,temp1,temp2;
   
   temp = list[x][0];
    temp1=list[x][1];
   temp2=list[x][2];
   list[x][0] = list[y][0];
   list[x][1] = list[y][1];
   list[x][2] = list[y][2];
   
   list[y][0] = temp;
   list[y][1] = temp1;
   list[y][2] = temp2;
   
}

void adjust( int **list,int i, int n)
{
   int j,k,kk,kkk,flag;
   k = list[i][0];
   kk=list[i][1];
   kkk=list[i][2];
   flag = 1;
   j = 2 * i;
   while(j <= n && flag)
   {
      if(j < n && list[j][0] < list[j+1][0])
      j++;
      if( k >= list[j][0])
               flag =0;
      else
      {
         list[j/2][0] = list[j][0];
         list[j/2][1] = list[j][1];
         list[j/2][2] = list[j][2];
         j = j *2;
      }
   }
   list [j/2][0] = k;
   list[j/2][1] = kk;
   list[j/2][2] = kkk;
   
}

void build_initial_heap( int **list, int n)
{
   int i;
   for(i=(n/2);i>=0;i--)
       adjust(list,i,n-1);
}

void heapsort(int **list,int n)
{
   int i;
   build_initial_heap(list,n);
   for(i=(n-2); i>=0;i--)
   {
      swap(0,i+1,list);
      adjust(list,0,i);
   }
}

