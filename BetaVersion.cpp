#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>

using namespace std;

typedef long long int lli;

bool *arr1,*arr2;

int main()
{
	lli n,count=0;
	scanf("%lld", &n);
	clock_t t;
	t=clock();
	arr1 = (bool*)calloc(n+1,1);
	arr2 = (bool*)calloc(n+1,1);
	memset(arr1,0,n+1);
	memset(arr2,1,n+1);
	if(n>=2)
	{
		cout<<"2"<<" ";
		count++;
	}

	if(n>=3)
	{
		cout<<"3"<<" ";
		count++;
	}
	
	for(lli i=5 ; i<=n ; i=i+6)
	{
		arr1[i]=1;
		arr1[i+2]=1;
		
		lli j=0;
			while(1)
			{
				int flag=0;
				/*Equation i.*/
				lli t1=6*i*j;

				lli temp1= t1+7*i;
				/*Equation ii.*/
				lli temp2=t1+(i*i);
				/*Equation iii.*/
				lli temp3=temp2 +(12*j) +4*(i+1); 
				/*Equation iv.*/
				lli temp4= temp3 + 4*(i+2);

				if(temp1<=n)
				{
					arr2[temp1]=0;
				}
		
				else
				{
					flag++;
				}
				if(temp2<=n)
				{
					arr2[temp2]=0;
				}
				else
				{
					flag++;
				}
					if(temp3<=n)
				{
					arr2[temp3]=0;
				}
				else
				{
					flag++;
				}
				if(temp4<=n)
				{
					arr2[temp4]=0;
				}
				else
				{
					flag++;
				}

				if(flag==4)
				{
					break;
				}	
				j++;
			}	
		if(arr1[i]==1 && arr2[i]==1)
		{	
			cout<< i << " ";
			count++;
		}

		if(arr1[i+2]==1 && arr2[i+2]==1)
		{
			cout<< i+2 << " ";
			count++;	
		}					
	}	
	t=clock()-t;
    	double time=(double (t))/CLOCKS_PER_SEC;
	cout<<"\n";
	cout<<count<<endl;
	cout << "Time taken by function: "<<time<<" Seconds"<<endl;
	return 0;
}
