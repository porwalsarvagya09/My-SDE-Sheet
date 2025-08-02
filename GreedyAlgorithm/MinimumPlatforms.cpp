/*
Minimum number of platforms required for a railway

Problem Statement: We are given two arrays that represent the arrival and departure 
times of trains that stop at the platform. We need to find the minimum number of 
platforms needed at the railway station so that no train has to wait.

Examples 1:

Input: N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}
Output:3

Example 2:

Input Format: N=2, 
arr[]={10:20,12:00}
dep[]={10:50,12:30}

Output: 1
Explanation: Before the arrival of the new train, the earlier train already departed. 
So, we don't require multiple platforms.
*/


#include <bits/stdc++.h>
using namespace std;

int countPlatform(int* arr, int* dep, int n){
    int platform = 1; //final value

    for(int i=0; i<n; i++){
        int count = 1; // count of overlapping interval of only this   iteration
        
        for(int j=i+1; j<n; j++){
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] && arr[j]<=dep[i])){
               count++; 
            }
        }
        platform = max(platform, count);   //updating the value
    }
    return platform;
}

int main(){
   
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};

    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatform(arr, dep, n)<<endl;
}

/*
Output: Minimum number of Platforms required 3

Time Complexity: O(n^2)  (due to two nested loops).

Space Complexity: O(1)  (no extra space used).
*/



/*------------APPROACH - 2----------------------*/

#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }


// Output: Minimum number of Platforms required 3

// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).

// Space complexity: O(1)  (No extra space used).