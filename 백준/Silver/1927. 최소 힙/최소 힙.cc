#include <bits/stdc++.h>
using namespace std;
//최소힙 구현

int heap[200005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int idx = sz;
  while(idx/2 != 0 && heap[idx] < heap[idx/2]){
    swap(heap[idx], heap[idx/2]);
    idx /= 2;
  }
}

int top(){
  return heap[1];
}

void pop(){
  swap(heap[1], heap[sz]);
  heap[sz--] = 0;
  int idx = 1;
  int min = 0;
  while(1){
    int s1 = heap[idx * 2];
    int s2 = heap[idx * 2 + 1];

    if(!s1 && !s2) 
      break;
    else if(!s1) 
      min = idx * 2 + 1;
    else if(!s2) 
      min = idx * 2;
    else if(heap[idx * 2] > heap[idx * 2 + 1])
      min = idx * 2 + 1;
    else 
      min = idx * 2;

    if(heap[idx] > heap[min]){
      swap(heap[idx], heap[min]);
      idx = min;
    }
    else break;
  }
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  int n; cin >> n;
  while(n--){
    int num; cin >> num;
    if(!num){
      if(!sz) cout << 0 << '\n';
      else {
        cout << top() << '\n';
        pop();
      }
    }
    else push(num);
  }
}