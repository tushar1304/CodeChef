#include<stdio.h>
#include<conio.h>
int smallernumbers();
int bigdigits();
int biggestdigits(); 
int smallernumbers()//for 10 digits
{	
	long int a,b;
 long  int c;
scanf("%ld%ld\n",&a,&b);
c=a*b;
printf("%ld",c);
return c;	
}
int bigdigits()//for 15 digits
{
long int a,b;
unsigned long long int c;
scanf("%ld%ld\n",&a,&b);
c=a*b;
printf("%llu",c);
return c;	
	
}
int main()
{
	smallernumbers();
	bigdigits();
}
