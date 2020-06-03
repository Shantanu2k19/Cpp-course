#include <iostream>
using namespace std;

bool canReadBook(int pages[],int books,int stud,int mid){
    int count =1;
    int studReading = 0;//pages[0];
    for(int i=0;i<books;i++){
        if(studReading + pages[i] > mid){
            count++;
            studReading=pages[i];
            if(count > stud) return false;
        }
        else 
        studReading += pages[i];
    }
    return true;
}

int main() {
    int books = 4;
    int stud = 2;
    int pages[] = {12,34,67,90};
    int ans = -1;   
    
    int s=pages[books-1],e=0;
    for(int i=0;i<books;i++){
        e=e+pages[i];
    }
    while(s<=e){
        int mid = (s+e)/2;
        
        if( canReadBook(pages,books,stud,mid) ){
            ans = mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans;
}
