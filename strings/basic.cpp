#include <iostream>
#include<cstring>            //for declaring string : string str
#include<algorithm>           //for sort function
using namespace std;

bool compare(string a,string b)
{
    return a<b;
/*  or for length
    return a.length()<b.length();    //for length wise sorting 
*/
}
int main() 
{
    /*  character array declaration
      1.  char arr1[]={"a","b","c","d","\0"};    always include null character in the end or it will output garbage value till null character appears
      2.  char arr2[2]={"a","b"};
      3.  char arr3[]="hello mf";   automatically terminated by null character,size will be n+1 for lull character  

      if array contain spaces use {{ cin.getline(arrayname,accept_this_max_character,'terminate_when_see_this')}} or if it doesnt use cin '
     */

    char aee[10];
    cin>>aee;
    sort(aee,aee+strlen(aee))
    cout<<aee[2]<<aee[1];
    
    string s0;
    getline(cin,s0);                  //input
    cout<<s0<<endl;
    string s("hello world");          //format 1
    string s1="lol world";            //format 2
    
    for(int i=0;i<s1.length();i++)   
    cout<<s1[i]<<".";   //printing format 1   accesing individual elements

    cout<<endl<<s<<endl<<s1<<endl;       //printing format 2

    string arr[]={"jargon","d","what","a"};     //format 3     , cant use functions sizeof() or length(), sad?! 
    sort(arr,arr+2,compare);     //sort alphabets wise (array,upto how many elements need to be sorted,condition function) general:increasing order, condition function for other conditions(length etc)
    for(int i=0;i<7;i++)  //arr[i]!='\0'
    cout<<arr[i]<<" ";  

//STRING TOKENIZER : with tokenizer, string can be seperated into tokens based upon the provided delimiter
    char arr[]="what the hell noob";    //only for character array, not for string
    char *ptr = strtok(arr," ");   //string seperated based on "delimiter"
    /*if there was string instead of character array, to convert string into array use following (in place of arr above)
       (char *)str.c_str()   or in above line char *ptr = strtok((char *)str.c_str()," ");   */
    cout<<ptr<<endl;
    while(ptr!=NULL)      //at last ptr will be null
    {   
        ptr=strtok(NULL," "); //to traverse the pointer to next delimiter
        cout<<ptr<<endl;   //when fn. is called again it expects a null pointer 
    }
} 
