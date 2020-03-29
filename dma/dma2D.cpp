#include <iostream>
using namespace std;
int main() 
{
    int **arr2d=new int*[3]; //create primary array in heap, 3 units
    for(int i=0;i<3;i++)
    arr2d[i]=new int[4];  //created secondary arrays, 3 arr2days

    int counter=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr2d[i][j]=counter;
            counter++;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr2d[i][j]<<" ";
        }
        cout<<endl;
    }

    //deleting
    for(int i=0;i<3;i++)  //disallocating secondary array 
    delete []arr2d[i];
    delete []arr2d;    //disallocating primary array

    cout<<"deleted";

}
