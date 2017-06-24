/**
*	Welcome to CodeChef Campus Chapter Challenge 
**/
/* 
----PROBLEM - 1----

Generalized Multiplication (GM01)

    23
   x31
  ------
    23
   69x
  ------
   713
  ------

->This is an example of bad programming, a noob years ago solved this problem of multiplication of large numbers (15-20 digits). 
  While solving this problem again for larger number than he did, he messed up with the code. Do the following tasks...
1. Debug the below code	
	a.) for smaller numbers (upto 10 digits) [ex. 9999999999*9999999999]
	b.) upto 15 digits [ex. 999999999999999*999999999999999]
	c.) upto 19 digits9 [ex. 9999999999999999999*9999999999999999999]
2. Optimise it.
3. Extend the digits to as much you can.  

[Hint : You may take help from here -> https://defuse.ca/big-number-calculator.htm for the Output]

----PROBLEM - 2----

Early Databases (ED02)

File : results.txt

S.No.	Name	Branch	Year	Result
1.	Amar	CSE	2012	PASS
2.	Akbar	ECE	2014	FAIL
3.	Anthony	CSE	2014	PASS
4.	Ambar	CCE	2013	FAIL
5.	Aakash	ECE	2012	PASS

->This file contains a database of some B.E./B.Tech Students, Do the following tasks...
1. Output the details/record of 
	a.) passed students in pass.txt
	b.) students of 2012 in 2012.txt
2. You don't have read and write permissions of results.txt, pass.txt and 2012.txt. 

[Note : Record means Single Row]

----SUBMISSION----
-> Save your files with yourname-problemcode.c and send it on whatsapp or upload on git and send the urls.
-> No Submissions will be accepted after 12AM.
-> If the two codes/programs match, both will be discarded.
 
*/

#include<stdio.h>
typedef unsigned long long ull;
ull * num_to_digits(ull);
ull numlen(ull);
int main(){
	//variable declaration
	//a - 1st digit, b - 2nd digit, adigits - pointer to digits of a, bdigits - pointer to digits of b, alength - length of a, blength - length of b, sum - matrix stores the multiplication results, result - array store the result, rtp - raisetopower
	ull a, b, * adigits, * bdigits, temp=0, ttemp, i, j, k, l, x, z, n,
	alength, blength, sum[100][1000], result[1000], rtp, * r2; 
	scanf("%lld %lld", &a, &b);
	//length and numtoDigits
	alength = numlen(a);
	blength = numlen(b);
	adigits = num_to_digits(a);
	bdigits = num_to_digits(b);
	//printf("alen = %lld\nblen = %lld\n", alength, blength);
	//for(i=0; i<alength; i++) printf("%lld ", adigits[i]);printf("\n");
	//for(i=0; i<blength; i++) printf("%lld ", bdigits[i]);printf("\n");
	//middle section
	k=0, n = alength*blength;
	for(i=blength-1; i>=0; i--, k++){
		l=0;
		for(z=0; z<k; z++) sum[k][l++]=0;
		rtp=0;
		for(j=alength-1; j>=0; j--){
			
			temp = bdigits[i] * adigits[j] + rtp;
			
			if(!j && (temp > 9)){
				x=0;
				while(temp){
					sum[k][l++] = temp%10;
					temp/=10;
				}
				break;
			}
			if(j && (temp<10)){
				sum[k][l++] = temp;
				rtp=0;
			}else{
				r2 = num_to_digits(temp);
				sum[k][l++] = r2[1];
				rtp = r2[0];
			}
		}
		for(;z<n; z++) sum[k][l++]=0;
		for(z=0; z<n/2; z++){
			temp = sum[k][z];
			sum[k][z] = sum[k][n-1-z];
			sum[k][n-1-z] = temp;
		}
	}
	
	z=n-1, rtp=0;
	for(i=n-1; i>=0; i--){
		temp=0;
		for(j=0; j<blength; j++){
			temp+=sum[j][i]+rtp;
			rtp=0;
		}
		if(!i && (temp > 9)){
			x=0;
			while(temp){
				result[z--] = temp%10;
				temp/=10;
			}
			break;
		}
		if((temp<10)){
			result[z--] = temp;
			rtp=0;
		}else{
			r2 = num_to_digits(temp);
			result[z--] = r2[1];
			rtp = r2[0];
		}
	}
	i=0;
	while(!result[i++]) continue;
	i--, ttemp=0;
	while(i<n){
		printf("%lld", result[i]);
		ttemp=ttemp*10+result[i++];	
	} 
	//printf("\n\n");
	//printf("%lld\n%lld", ttemp, numlen(ttemp));
	
	return 0;
}

ull * num_to_digits(ull fnum){
	ull a[1000], i=numlen(fnum)-1;
	while(fnum){
		a[i--] = fnum%10;
		fnum/=10;
	}
	return a;
}

ull numlen(ull fnum){
	ull i=1;
	while((fnum=fnum/10)) i++;
	return i;
}

/*--EOF--*/

