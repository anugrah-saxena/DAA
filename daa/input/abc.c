#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include<time.h>

int main(int argc,char *argv[])
{
 	     struct timeval tim;
 	     double t1,t2;
             gettimeofday(&tim, NULL);
              t1=tim.tv_sec+(tim.tv_usec/1000000.0);
                   
		execvp(argv[1],argv);
	
                
             gettimeofday(&tim, NULL);
              t2=tim.tv_sec+(tim.tv_usec/1000000.0);
             printf("%9lf micro seconds elapsed for program\n",(t2-t1)*1000000);
	      
}
