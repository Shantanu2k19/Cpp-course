/*
HASHING 
why?
support insertion, deletion and search in constant time,O(1), on average
->ordering is not preserved in hashmap, unlike an array

hash table : array of fixed size
array elements are indexed by a key, 
which is mapped to an array index (0 to tablesize-1)

operations : 
insert: table[h(key)] = value;
delete: table[h(key)] = NULL;
search: return table[h(key)];

hash function, example : h(key) = key%tableSize
hash key is generated for a given key

working:
table   ->    linked list
node**  ->   node*

IMPLEMENTATION
*/

#include<cstring>
#include<iostream>
#include "hashtable.h"
using namespace std;

//code at 234 and 234
//TWO CLASSES ARE USED, NODE AND HASHTABLE
// a bucket contains pointers, each pointer contain linked list
//class node, 3 data: key(string), value(T), next(pointer)
template<typename T>
class node{
        public:
            string key;
            T value;
            node<T> *next;

            node(string key,T v){
                this->key = key;
                value = v;
                next = NULL; //
            }
            ~node(){
                if(next!=NULL){
                    delete next;
                }
            }
};

template<typename T>
class Hashtable{
    int cs; ///Current Size
    int ts; ///Max Arr Size
    node<T>** buckets;

    void rehash(){
        node<T>** oldbuckets = buckets; //a temporary bucket to perform all the operations
        //since all the functions are written with buckets name, should'nt be changed,oldTable is deleted afterwards
        int oldTs = ts;
        ts = ts*2;  //making the new bucket twice the size
        cs = 0;
        buckets = new node<T>*[ts];  //new bucket twice as big
        
        for(int i=0; i<ts; i++){ //initiallise new memory with null
            buckets[i] = NULL;
        }

        ///Read the elements from old table and insert them into new table
        for(int i=0; i<oldTs; i++){
            node<T>*temp = oldbuckets[i];

            if(temp!=NULL){
                while(temp!=NULL){
                    insert(temp->key,temp->value); //data will be inserted in new table
                    temp  = temp->next;
                }
                ///Delete the old table i bucket linked list
                if(oldbuckets[i]!=NULL) delete oldbuckets[i];
            }  
        }
        delete [] oldbuckets;
    }

    int hashFn(string key)
    {
        int Len = key.length();
        int ans =0 ;
        int p = 1; // power, 37^0 is 1 initially

        for(int i=0; i<Len; i++){
            ans += key[i]*p;
            p = p*27;  //raised power

            p %= ts;  //done because, 27^n can be very lagre number
            ans %= ts;
            //property used : (a + b)%m = (a%m + b%m)%m
        }
        return ans;  //return index for the key
        /* hashing algo:   b        a       t   
                    ans = 2*27 + 1*27^2 + 20*27^3
                37 used because, prime shloud be ideally used for hashing
                next prime after 26(alphabets)->27 
        */
    }

    public:
    Hashtable(int table_size=7)  //default value of table
    {
        cs = 0;
        ts = table_size;
        buckets = new node<T>*[ts]; //buckets : an array of pointers of type T, size: ts
        ///initialise all addresses with NULL, remove garbage
        for(int i=0;i<ts;i++){
            buckets[i] = NULL;
        }
    }

    void insert(string key,T value)
    {
        ///Key i need the hash-index
        int idx = hashFn(key);

        node<T>*n = new node<T>(key,value);
        //insert at the head of linked list, forming chain in linkedList
        n->next = buckets[idx];
        buckets[idx] = n;

        cs++;  //increment current size

        float load_factor = (float)cs/ts;
        if(load_factor>.7){
            cout<<"Load factor is "<<load_factor<<", rehashing"<<endl;
            rehash();
        }
    }

    ///Print it
    void print(){
        ///Iterate over buckets array
        for(int i=0;i<ts;i++){
            ///Print the LL for each buckets
            node<T>*temp = buckets[i];
            cout<<"Bucket "<<i<<"->";
            while(temp!=NULL){
                cout<<temp->key<<" -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

//find the hash index for string, now search in linked list at that index
    T* search(string key){
    int i=hashFn(key);
    node<T>* temp=buckets[i];
        while(temp!=NULL){
            if(temp->key == key){
                return &(temp->value);
            }
            temp=temp->next;
        }
     return NULL;  //not found, returned T* NULL value
    }

    void erase(string key){    //deleting data
        int i=hashFn(key);  //search element
        if(i == NULL) return; //element is not found
        node<T>*target = buckets[i];   //using 2 pointers
        node<T>*temp = target;

        if(target->key == key){   //first element of LL is target
            buckets[i]=NULL;
            delete target;
            
        }
        else{    //traverse through elements for further elements in LL
            target=target->next;
            while(target!=NULL){
                if(target->key == key){  //element found
                    temp->next = target->next;
                    delete target;
                    return;
                }
                target=target->next;
                temp=temp->next;
            }
        }
        return ; 
    }
        
     
//[] operator
//here operator overloading is used for [], also it returns by reference
//so the value change is observed 
    T& operator[](string key){
        T * f = search(key);  //search 
        if(f==NULL){ //key not present
        //insert key with garbage value 
            T garbage;
            insert(key,garbage);
            f = search(key); //for index of the key inserted
            //f points to garbage (value)
        }
        return *f; //now the pointer is returned with reference
    }

};






int main()
{
    Hashtable<int> price_menu;

    price_menu.insert("Burger",120);  //inserting
    price_menu.insert("Pepsi",20);
    price_menu.insert("BurgerPizza",150);
    price_menu.insert("Noodles",25);
    price_menu.insert("Coke",40);

    price_menu.print();  //printing

    int *price = price_menu.search("Noodles");  //searching
    if(price == NULL) cout<<"not found";
    else cout<<"price is "<<*price<<endl;

    price_menu.erase("Pepsi");
    cout<<"\nafter deleting\n"<<endl;
    price_menu.print();
        
    
    //using [] operator, custom designed

    //Insert
    price_menu["Dosa"] = 60;  //if Dosa present, update price, else insert data

    //Update
    price_menu["Dosa"] += 10;  //the reference pointer will cause value change in original bucket(LL)

    //search
    cout<<"dosa price : "<<price_menu["Dosa"]<<endl;

    return 0;
}

/*
removing collisions :
1. inc the table size as no of elements increases
load factor = current_size/total_size
when lf>0.7, inc table size
    then, the new table with atleast 2x size is created,
    shilft elements,rehash the new table and delete previous one
rehashing expensive operation, takes O(N) time
*/
