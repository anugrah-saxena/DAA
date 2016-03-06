#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i;
	double x1,x2,y1,y2;
	double X,Y;
	double temp,PI=3.14159265;

// input
	printf("enter x1-coordinate of vector :");
	scanf("%lf",&x1);
	printf("enter y1-coordinate of vector :");
	scanf("%lf",&y1);

	printf("enter x2-coordinate of vector :");
	scanf("%lf",&x2);
	printf("enter y2-coordinate of vector :");
	scanf("%lf",&y2);

	X=x2-x1; Y=y2-y1;
	printf("vector is %.2lfi + %.2lfj\n",X,Y);

// magnitude of vector
	double smag,mag;

	smag=pow(X,2)+pow(Y,2);
//	printf("%.2lf\n",smag);
	mag=sqrt(smag);
	printf("magnitude of vector %.2lfi+%.2lfj is %.2lf\n",X,Y,mag);

// amplitude of vector
	double amp;

//	temp=Y/X;
//	printf("%.2lf\n",temp);
	amp=atan2(Y,X)*180/PI;					// [in degree's here]
	printf("amplitude of vector %.2lfi+%.2lfj is %.2lf\n",X,Y,amp);

// rotation of vector
	double rot;
	char str[10],sign;
	printf("enter rotation angle in degree(+/-) :");
	scanf("%s",str);
	sign=str[0];	//printf("%c\t",sign);
	for(i=0;str[i+1]!='\0';i++){str[i]=str[i+1];}
	str[i]='\0';
	rot=atof(str);	//printf("%.2lf\n",rot);

	if(sign=='-')
		amp=amp-rot;
	else
		amp=amp+rot;				// [in degree's here]
	printf("new amplitude is %.2lf\n",amp);
	X=mag*cos(amp*PI/180);	Y=mag*sin(amp*PI/180);	// projection on X & Y axis
	printf("vector after rotation is %.2lfi+%.2lfj\n",X,Y);

// another vector
	double n1,n2,m1,m2;
	double X2,Y2;

	printf("enter n1-coordinate of vector2 :");
	scanf("%lf",&n1);
	printf("enter m1-coordinate of vector2 :");
	scanf("%lf",&m1);

	printf("enter n2-coordinate of vector2 :");
	scanf("%lf",&n2);
	printf("enter m2-coordinate of vector2 :");
	scanf("%lf",&m2);

	X2=n2-n1; Y2=m2-m1;
	printf("vector is %.2lfi + %.2lfj\n",X2,Y2);
	
// intersection with another vector
	printf("vector.1:~ %.2lfi+%.2lfj +L(%.2lfi+%.2lfj)\n",x1,y1,X,Y);
	printf("vector.2:~ %.2lfi+%.2lfj +M(%.2lfi+%.2lfj)\n",n1,m1,X2,Y2);
	printf("......intermediate steps......\n");
	printf("%.2lf*%.2lf*L=%.2lf*%.2lf+%.2lf*%.2lf*M\t",X,Y,n1-x1,Y,X2,Y);
	printf("%.2lf*%.2lf*L=%.2lf*%.2lf+%.2lf*%.2lf*M\n",X,Y,m1-y1,X,Y2,X);

	temp=X*Y2+X2*Y;
	double L,M,numr=((m1-y1)*X)-((n1-x1)*Y);
	printf("M=[(%.2lf*%.2lf)-(%.2lf*%.2lf)]/(%.2lf)\n",m1-y1,X,n1-x1,Y,temp);

	if(temp==0)
	{
		if(numr==0)
			printf("INFINITE SOLUTIONS: LINES ARE OVERLAPPING\n");
		else
			printf("NO SOLUTION: LINES ARE PARALLEL\n");
	}
	else
	{
		if(X!=0){
		M=numr/temp;
		L=((n1-x1)+M*X2)/X;
		printf("point of intersection %.2lfi+%.2lfj\n",n1+M*X2,m1+M*Y2);
		}
		else
			printf("NO SOLUTION: LINES ARE PARALLEL\n");
	}
	
return 0;
}
