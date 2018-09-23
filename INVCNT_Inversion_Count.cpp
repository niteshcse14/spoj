// C++ program to count inversions using Binary Indexed Tree
#include<bits/stdc++.h>
using namespace std;
 #define ll long long int
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
ll getSum(ll BITree[], ll index)
{
    ll sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
 
       // Update index to that of parent in update View
       index += index & (-index);
    }
}
 
// Returns inversion count arr[0..n-1]
ll getInvCount(ll arr[], ll n)
{
    ll invcount = 0; // Initialize result
 
    // Find maximum element in arr[]
    ll maxElement = 0;
    for (ll i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];
 
    // Create a BIT with size equal to maxElement+1 (Extra
    // one is used so that elements can be directly be
    // used as index)
    ll BIT[maxElement+1];
    for (ll i=1; i<=maxElement; i++)
        BIT[i] = 0;
 
    // Traverse all elements from right.
    for (ll i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
 
        // Add current element to BIT
        updateBIT(BIT, maxElement, arr[i], 1);
    }
 
    return invcount;
}
 
// Driver program
int main()
{
    ll T, N;
    cin >> T;
    while(T--)
    {
    	cin >> N;
    	ll arr[N];
    	for(ll i = 0; i < N; i++)
    	{
    		cin >> arr[i];
    	}
    	cout << getInvCount(arr, N);
    }
    return 0;
}