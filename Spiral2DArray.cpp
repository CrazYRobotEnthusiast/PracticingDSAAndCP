#include<iostream>
#include<vector>
using namespace std;

void SpiralOrder(vector<vector<int>> a){
    int top=0;
    int left=0;
    int bottom=a.size()-1;
    int right=a[0].size()-1;
    int direction=0;
    while(top<=bottom && left<=right){
        if (direction>3) direction%=4;
        switch(direction){
            case 0:
                for(int i=left;i<=right;i++){
                    cout<<a[top][i]<<" ";
                }
                direction++;
                top++;
                break;
            case 1:
               for(int i=top;i<=bottom;i++){
                cout<<a[i][right]<<" ";
               }
               direction++;
               right--;
               break;
            case 2:
               for(int i=right;i>=left;i--){
                cout<<a[bottom][i]<<" ";
               }
               direction++;
               bottom--;
               break;
            case 3:
               for(int i=bottom;i>=top;i--){
                cout<<a[i][left]<<" ";
               }
               direction++;
               left++;
               break;
        }
    }

}
int main(){
    cout<<"Enter dimensions of matrix:";
    int r1,c1;
    cin>>r1>>c1;
    vector<vector<int>> a(r1,vector <int>(c1));
    cout<<endl;
    cout<<"Enter matrix:-";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    SpiralOrder(a);
    
}