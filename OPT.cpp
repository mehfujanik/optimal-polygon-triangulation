#include<bits/stdc++.h>
using namespace std;

int n;
double weight[100][2];

int input_polygon()
{
    cout<<"\tInput must be a clockwise convex polygon!"<<endl;
    cout<<"1. Input from file"<<endl<<"2. Input from keyboard"<<endl;
    int x;
    cin>>x;
    system("CLS");
    if(x == 2)
    {
        cout<<"\nEnter the number of vertex of the polygon:";
        cin>>n;
        if(n<3)
        {
            cout<<"\nNo possible polygon!"<<endl;
            return 0;
        }
        else
        {
            for(int i = 0; i<n; i++)
            {
                cout<<"Vertex #"<<i+1<<": ";
                for(int j = 0; j<2; j++)
                {
                    cin>>weight[i][j];
                }
            }
        }
    }
    else if(x==1)
    {
        ifstream p;
        p.open("input.txt");
        p>>n;
        if(n<3)
        {

            cout<<"\nNo possible polygon!"<<endl;
            return 0;
        }
        else
        {
            for(int i = 0; i<n; i++)
            {
                //cout<<"Vertex #"<<i+1<<": ";
                for(int j = 0; j<2; j++)
                {
                    float t;
                    p>>t;
                    weight[i][j] = t;
                }
            }
            for(int i = 0; i<n; i++)
            {
                cout<<"Vertex #"<<i+1<<": ";
                for(int j = 0; j<2; j++)
                {

                    cout<<weight[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }



}

double perimeter(int a, int b, int c)
{
    double x1, y1, x2, y2;
    x1 = weight[a][0];
    y1 = weight[a][1];
    x2 = weight[b][0];
    y2 = weight[b][1];
    double x = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    x1 = weight[a][0];
    y1 = weight[a][1];
    x2 = weight[c][0];
    y2 = weight[c][1];
    double y = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    x1 = weight[b][0];
    y1 = weight[b][1];
    x2 = weight[c][0];
    y2 = weight[c][1];
    double z = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return x+y+z;
}

void calculate_OPT()
{
    double OP[n][n];

    for(int counter = 0; counter<n; counter++)
    {
        int i = 0;
        for(int j = counter; j<n; j++)
        {
            if(j<i+2)
            {
                OP[i][j] = 0;
            }
            else
            {
                OP[i][j] = 1000000;
                for(int k = i+1; k<j; k++)
                {
                    double temp = OP[i][k] + OP[k][j] + perimeter(i, j, k);
                    if(temp < OP[i][j])
                    {
                        OP[i][j] = temp;
                    }
                }
            }
            i++;
        }
    }

    cout<<endl<<"Optimal Polygon Triangulation is: "<<OP[0][n-1]<<endl;

}


int main ()
{
x:
    int terminator = input_polygon();
    if(terminator == 0)
    {
        goto x;
    }
    calculate_OPT();
}
