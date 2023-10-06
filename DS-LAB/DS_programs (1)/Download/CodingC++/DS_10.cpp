#include<iostream>
using namespace std;

void create_matrix(int**p, int r, int c)
{
    int val;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<"Enter value for the row "<<i+1<<" column "<<j+1<<": "<<"\n";
            cin>>val;
            p[i][j]=val;
        }
    }
}

void print_matrix(int**p, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<p[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }

}

void row_sum(int**p, int r, int c)
{
    int r_sum[r];
    for(int i=0; i<r; i++)                                         //array of row sums with dummy value(0)
    {
        r_sum[i]=0;
    }
 
    for(int i=0; i<r; i++)                                        //finding and filling correct row sums
    {
        for(int j=0; j<c; j++)
        {
            r_sum[i]=r_sum[i]+p[i][j];
        }
    }
    
    for(int i=0; i<r; i++)                                        //printing row sums
    {
        cout<<"The row sum of row "<<i+1<<"= "<<r_sum[i]<<"\n";
    }

    int rs_max=r_sum[0];
    for(int i=1; i<r; i++)                                        //finding the largest row sum
    {
        if(r_sum[i]>rs_max)
        {
            rs_max=r_sum[i];
        }
    } 
    cout<<"The largest row sum= "<<rs_max<<"\n";
}


void col_sum(int**p, int r, int c)
{
    int c_sum[c];
    for(int i=0; i<c; i++)                                         //array of column sums with dummy value(0)
    {
        c_sum[i]=0;
    }
 
    for(int i=0; i<c; i++)                                        //finding and filling correct column sums
    {
        for(int j=0; j<r; j++)
        {
            c_sum[i]=c_sum[i]+p[j][i];
        }
    }
    
    for(int i=0; i<c; i++)                                        //printing column sums
    {
        cout<<"The column sum of column "<<i+1<<"= "<<c_sum[i]<<"\n";
    }

    int cs_max=c_sum[0];
    for(int i=1; i<c; i++)                                        //finding the largest column sum
    {
        if(c_sum[i]>cs_max)
        {
            cs_max=c_sum[i];
        }
    } 
    cout<<"The largest column sum= "<<cs_max<<"\n";
}


int main()
{
    int **p;
    int r;
    int c;

    cout<<"Enter the row size: ";
    cin>>r;

    cout<<"Enter the  column size: ";
    cin>>c; 

    p=new int *[r];

    for(int i=0; i<r; i++)
    {
        p[i]=new int[c];
    }
    
    create_matrix(p, r, c);
    print_matrix(p, r, c);
    
    row_sum(p, r, c);
    col_sum(p, r, c); 

    return 0;
}

/*
Enter the  row size: 2
Enter the  column size: 2
Enter value for the row 1 column 1: 
1
Enter value for the row 1 column 2: 
2
Enter value for the row 2 column 1: 
3
Enter value for the row 2 column 2: 
4
1 2 
3 4
The row sum of row 1= 3
The row sum of row 2= 7
The largest row sum= 7
The column sum of column 1= 4
The column sum of column 2= 6
The largest column sum= 6
*/