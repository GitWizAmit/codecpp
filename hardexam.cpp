#include <iostream>
using namespace std;

int a[]={0,8,4,2,6,8,4,2,6};
int main() {

    int b;
    cin>>b;
    int rem = b % 8;
    if(b==0) cout<<1;
    else if(b%8==0) cout<<6;
    else cout<<a[rem];
    return 0;
}
