#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int arr[1000]={0};
int s=1;

void Add(){
    arr[s] = rand() % 1000 + 1;
    int child=s;
    int parent = child/2;
    
    while(child>1 && arr[parent]<arr[child]) {
        int temp=arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        child=parent;
        parent=child/2;
    }
    
    s++;
}

int Delete(){
    if(s<=1) return -1;
    
    int pop = arr[1];
    arr[1] = arr[s-1];
    s--;
    
    int parent=1;
    while(1){
        int L_child = parent*2;
        int R_child = parent*2+1;
        int child=parent;
        
        if(L_child < s && arr[L_child]>arr[R_child]){
            child=L_child;
        }
        
        if(R_child < s && arr[R_child]>arr[L_child]){
            child=R_child;
        }
        
        if(child==parent) break;
        
        int temp=arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        
        parent = child;
    }
    return pop;
}

void Print(int i){
    if(i>=s)return;
    Print(i*2);
    cout << arr[i] << ' ';
    Print(i*2 + 1);;
}




int main() {
    srand(time(NULL));
    
    //5개 삽입 + 출력
    for (int i=0; i<5; i++){
        Add();
        Print(1);
        cout<<'\n';
    }
    
    //삭제 +출력
    cout<<"----------------------------"<<'\n';
    cout<<"삭제: "<<Delete()<<'\n';
    Print(1);
}