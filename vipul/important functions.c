// dsu functions start
#include<stdio.h>
#include <stdlib.h>

void make_set(int a[], int n)
{
	int i;
	for ( i = 0; i < n; ++i ) {
		a[i] = -1;
	}
}
void Union(int a[], int n1, int n2)
{
	int p1, p2;
	p1 = find_set ( n1, a);
	p2 = find_set ( n2, a);
	a[p1] = p2;
}
int find_set(int n, int a[])
{
	if ( a[n] == -1 )
		return n;
	else return find_set ( a[n], a);
	
}
// dsu end


//string functions
int myAtoi(char *str)
{
    int res = 0;  
    int sign = 1; 
    int i = 0;  

    if (str[0] == '-')
    {
        sign = -1;  
        i++; 
    }

    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    return sign*res;
}
void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
    	char tmp;
    	tmp = str[start];
    	str[start] = str[end];
    	str[end] = tmp;
        start++;
        end--;
    }
}
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;
 
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}
int myStrlen(char *a)
{
	int i;
	for ( i = 0; a[i]!='\0';i++);
	return i;
}
int main(){
	char a[]="123456";
	int b=atoi(a);
	char *c=(char *)malloc(100);
	c = itoa(b,c,10);
	printf("%d %s", myStrlen(c),c);
	
	return 0;
}
