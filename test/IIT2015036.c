void insert (int input, int hashtable[], int k)
{
	//key calculation
	int d = 0,i;
	int temp = input;
	while(temp!=0)
	{
		temp = temp/10;
		d++;
	}
	temp = input;
	long long int h[d+1];
	int digits [d+1];
	for(i=d;i>=1;i--)
	{		
		digits[i] = temp%10;
		temp = temp/10;
	}
	h[0] = d;
	for(i=1;i<=d;i++)
	{
		h[i] = 613 * h[i-1] + digits[i] ; 
	}
	int key =  (h[d]%k);
	//key obtained
	int flag = 0;
	while(1)
	{
		if(hashtable[key] == input)
			break;
		if(hashtable[key]==0)
		{
			hashtable[key] = input;
			break;
		}
		else
		{
			key++;	
		}
		if(key == k && flag == 0)
		{	flag = 1;
			key=0;	
		}
		if(key == k && flag == 1)
		{
			break;
		
		}	
      }
}

