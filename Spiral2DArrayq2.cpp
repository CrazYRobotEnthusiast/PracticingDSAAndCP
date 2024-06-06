#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> SpiralOrder(int n){
    vector <vector<int>> a(n,vector<int>(n));
    int top=0;
    int left=0;
    int bottom=a.size()-1;
    int right=a[0].size()-1;
    int direction=0;
    int r=1;
    while(top<=bottom && left<=right){
        if (direction>3) direction%=4;
        switch(direction){
            case 0:
                for(int i=left;i<=right;i++){
                    a[top][i]=r;
                    r++;
                }
                direction++;
                top++;
                break;
            case 1:
               for(int i=top;i<=bottom;i++){
                a[i][right]=r;
                r++;
               }
               direction++;
               right--;
               break;
            case 2:
               for(int i=right;i>=left;i--){
                a[bottom][i]=r;
                r++;
               }
               direction++;
               bottom--;
               break;
            case 3:
               for(int i=bottom;i>=top;i--){
                a[i][left]=r;
                r++;
               }
               direction++;
               left++;
               break;
        }
    }
    return a;

}
int main(){
    cout<<"Enter no of rows of square matric: ";
    int n;
    cin>>n;
    vector <vector<int>> a=SpiralOrder(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}