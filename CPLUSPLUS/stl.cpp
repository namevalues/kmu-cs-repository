#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
 
template <typename T>
void print(const T& v, const char *m = "") {
   cout << m << "";
   typename T::const_iterator it;
   for (it = v.begin(); it != v.end(); it++)
   {
      cout << *it<<' ';
   }
   cout << endl;
}

int main() {
   char str[10] = "123456789";
   deque<char> x;

   x.push_back('c');
   x.push_back('+');
   x.push_front('y');
   x.push_front('m');
   print(x, "x= ");

   deque<char>::iterator it;
   it = find(x.begin(), x.end(), 'c');
   it = x.insert(it, 'q');
   print(x, "1)x= ");

   it = x.insert(it, 3, '!');
   print(x, "2)x= ");

   it = x.insert(it,str+1,str+4);
   print(x, "3)x= ");
   
   vector<char> v(x.size());
   copy(x.begin(), x.end(), v.begin());
   print(v, "4)v= ");

   vector<char>::iterator v_it;
   v_it = search(v.begin(), v.end(), x.begin()+1, x.begin()+5);
   cout << "5)= " << *v_it << endl;

   v_it = v.erase(v_it);
   print(v, "6)v= ");

   v_it = remove(v.begin(), v.end(), '!');
   print(v, "7)v= ");

   v_it = v.erase(v_it, v.end());
   print(v, "8)v= ");

   cout << v[1]<<endl;
   cout << v[v.size() - 1]<<endl;

   partial_sort(v.begin(), v.begin()+2, v.end());
   print(v, "11)v= ");

   nth_element(v.begin(), v.begin()+4, v.end());
   print(v, "12)v= ");

   sort(v.begin(), v.end());
   print(v, "13)v= ");

   cout << "14)= " << binary_search(v.begin(),v.end(),'c') << endl;
   cout << "15)= " << binary_search(v.begin(), v.end(), 'u') << endl;

}