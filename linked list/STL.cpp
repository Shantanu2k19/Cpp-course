#include <bits/stdc++.h>
using namespace std;

void showlist(list <int> lol){
   list<int> :: iterator it;
   for(it = lol.begin(); it!=lol.end(); it++){
      cout<<*it<<endl;
   }
}


int main() {
   list <int> l1;
   for(int i=0;i<10;i++){
      l1.push_back(i*i);
   }
   showlist(l1);
   
	return 0;
}
