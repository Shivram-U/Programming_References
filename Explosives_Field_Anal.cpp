#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*DOCS:



Test cases:

Test Case 1
10
10
100
E N E N E N E N E N 
N E N E N E N E N E 
E N E N E N E N E N 
N E N E N E N E N E 
E N E N F N E N E N 
N E N E N E N E N E 
E N E N E N E N E N 
N E N E N E N E N E 
E N E N E N E N E N 
N E N E N E N E N E 
*/
void Print_Matr(char Matr[60][60],int R,int C)
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<'|'<<Matr[i][j]<<'|';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int Exp_Check(int* R1,int* C1,int N,int r,int c)
{
    for(int i=0;i<N;i++)
    {
        if(R1[i] == r && C1[i] == c)
            return 1;
    }
    return 0;
}

int  Evaluate_Time_Elapse_Of_Explosion(char Matr[60][60],int T,int R,int C)
{
	int cyc_com=1,c2 =1,Tot_time=0,n=0,prog=0;
   	int R1[200],C1[200],N=0;
   	while(cyc_com)
   	{
       	n=0;
       	prog=0;
       
       	// Data Analysis
       		printf("Cycle Begin:\n");
       		Print_Matr(Matr,R,C);
       	//
		for(int i=0;i<R;i++)
      	{
			for(int j=0;j<C;j++)
			{
              		n=0;
               		if(Matr[i][j] == 'F')
               		{
                   		Matr[i][j] = '#';
               		}
                		if(Matr[i][j] == '#' && !Exp_Check(R1,C1,N,i,j))
                		{
                   		if(i-1>=0)
                   		{
                       			if(Matr[i-1][j] == 'E')
                        		{
	                            		Matr[i-1][j] = '#';
      	                      		R1[N] = i-1;
      	                      		C1[N++] = j;
      	                      		n++;
      	                  	}
      	                 		if(j+1<C && Matr[i-1][j+1] == 'E')
      	                  	{
      	                      		Matr[i-1][j+1] = '#';
      	                      		R1[N] = i-1;
      	                      		C1[N++] = j+1;
      	                      		n++;
      	                  	}
      	                 		if(j-1>=0 && Matr[i-1][j+1] == 'E')
      	                  	{   
     	                        		Matr[i-1][j+1] = '#';
      	                       		R1[N] = i-1;
     		                       		C1[N++] = j+1;
      	                       		n++;
      	                  	}
     	              		}
     		              	if(i+1<R)
     		              	{
     		              	     	if(Matr[i+1][j] == 'E')
     		              	     	{    
     	         		     	         	Matr[i+1][j] = '#';
     	              		         	R1[N] = i+1;
                   		         	C1[N++] = j;
                   		         	n++;
                   		     	}
                   		     	if(j-1>=0 && Matr[i+1][j-1] == 'E')
                   		     	{    
                   		         	Matr[i+1][j-1] = '#';
                   		         	R1[N] = i+1;
                   		         	C1[N++] = j-1;
                   		         	n++;
                        		}
                   		     	if(j+1<=C && Matr[i+1][j+1] == 'E')
                   		     	{   
                   		          	Matr[i+1][j+1] = '#';
                   		          	R1[N] = i+1;
                   		          	C1[N++] = j+1;
                   		          	n++;
                   			}
                   		}
                   		if(j+1<C)
                   		{
                   			if(Matr[i][j+1] == 'E')
                   			{
                        	    		Matr[i][j+1] = '#';
                        	    		R1[N] = i;
                        	    		C1[N++] = j+1;
                        	    		n++;
                        		}
                        		if(i+1<R && Matr[i+1][j+1] == 'E')
                        		{
                        	    		Matr[i+1][j+1] = '#';
                        	    		R1[N] = i+1;
                        	    		C1[N++] = j+1;
                        	    		n++;
                        		}
                        		if(i-1>=0 && Matr[i-1][j+1] == 'E')
                        		{
                        	    		Matr[i-1][j+1] = '#';
                        	    		R1[N] = i-1;
                        	   		C1[N++] = j+1;
                        	    		n++;
                        		}
                   		}
                   		if(j-1>=0)
                   		{
                       			if(Matr[i][j-1] == 'E')
                       			{
                        	   		Matr[i][j-1] = '#';
                        	   		R1[N] = i;
                        	   		C1[N++] = j-1;
                        	   		n++;
                       			}
                       			if(i+1<R && Matr[i+1][j-1] == 'E')
                       			{
                        	   		Matr[i+1][j-1] = '#';
                        	   		R1[N] = i+1;
                        	   		C1[N++] = j-1;
                        	   		n++;
                       			}
                       			if(i-1>=0 && Matr[i-1][j-1] == 'E')
                        		{
                        	    		Matr[i-1][j-1] = '#';
                        	    		R1[N] = i-1;
                        	    		C1[N++] = j-1;
                        	    		n++;
                        		}
					}
                    		if(n>0)
                    		{
                        		//print_mat(a,r,c);
                        		prog=1;
                    		}
				}	
           		}	
       	}		
		if(prog == 0)
		{
      		cyc_com=0;
      	}
      	else
      		Tot_time+=T;
      	N=0;
      	Print_Matr(Matr,R,C);
      	printf("\nCycle END\n");
	}
   	return Tot_time;
}

int Explosives_Count(char Matr[60][60],int r,int c)
{
    int C1=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(Matr[i][j] == 'E')
                C1++;
        }
    }
    return C1;
}

void Get_Field_Matr(char Matr[60][60],int R,int C)
{
	for(int i=0;i<R;i++)
	{
  		for(int j=0;j<C;j++)
        	{
            	scanf("%c ",&Matr[i][j]);
        	}
    	}
}
int main()
{
    	char Field_Matr[60][60];
    	int Rows,Cols,Deton_Time,Exp_Count,Expl_TimeE;
      cout<<"Enter Rows";
	cin>>Rows;
	cout<<"Enter Columns:";
	cin>>Cols;
	cout<<"Enter the Time of Detonation of Explosives";
    	cin>>Deton_Time;
	cin.ignore();
    	cout<<"Enter the Elements of the field Matrix:";
    	Get_Field_Matr(Field_Matr,Rows,Cols);   
    	
    	cout<<"Provided Data : \n";
    	cout<<"Rows : "<<Rows<<'\n'<<"Columns : "<<Cols<<'\n';
    	cout<<"Detonation time : "<<Deton_Time<<'\n';
    	Print_Matr(Field_Matr,Rows,Cols);
    	
    	Expl_TimeE = Evaluate_Time_Elapse_Of_Explosion(Field_Matr,Deton_Time,Rows,Cols);
    	Print_Matr(Field_Matr,Rows,Cols);
    	Exp_Count = Explosives_Count(Field_Matr,Rows,Cols);
    	
    	cout<<"Field Analysis After Explosion: \n";
    	Print_Matr(Field_Matr,Rows,Cols);
    	cout<<"\nTime Elapsed : "<<Expl_TimeE<<'\n';
    	cout<<"Explosives remaining : "<<Exp_Count<<'\n';
}
