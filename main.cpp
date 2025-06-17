#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;
double TotalTime=0;
double selTime=0;
vector<int> bubbleSort(vector<int> nums) {
   int n=nums.size();
    for (int i=n;i>0;i--) {
        for (int j=1;j<i;j++) {
            if (nums[j]<nums[j-1]) {
                int temp=nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=temp;
            }
        }
    }

    return nums;
}
vector<int> selectionSort(vector<int> nums) {

    int min=nums[0];
    for(int i=0;i<nums.size();i++) {
        min=i;
        for (int j=i+1;j<nums.size();j++) {
            if (nums[j]<nums[min]) {
                min=j;
            }
        }
        if (min!=i) {
            int temp=nums[i];
            nums[i]=nums[min];
            nums[min]=temp;
        }
    }
    return nums;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int sizeArray=1000;
    int numArrays=500;
    for (int f=0;f<numArrays;f++) {
        vector<int> nums;
        for (int i=0;i<sizeArray;i++) {
            int j=rand()%sizeArray+1;
            nums.push_back(j);

        }
        auto start = high_resolution_clock::now();
        vector<int>sorted=bubbleSort(nums);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        //cout << duration.count() << "ms" << endl;
        TotalTime= TotalTime + duration.count();

    }
    for (int f=0;f<numArrays;f++) {
        vector<int> nums;
        for (int i=0;i<sizeArray;i++) {
            int j=rand()%sizeArray+1;
            nums.push_back(j);

        }
        auto start = high_resolution_clock::now();
        vector<int>sorted=selectionSort(nums);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        //cout << duration.count() << "ms" << endl;
        selTime= selTime + duration.count();

    }
    cout<<'HI GUys';
    //HELLO WORLD
    //TotalTime=TotalTime/1000;
    // for (int n:sorted) {
    //     cout<<n<<" ";
    // }

    TotalTime=TotalTime/1000000;
    selTime=selTime/1000000;
    cout<<TotalTime;
    cout<<endl;
    cout<<selTime;

    // vector<int>sortedSel=selectionSort({1,5,2,4,8,2});
    // for (int n:sortedSel) {
    //     cout<<n<<" ";
    // }

}