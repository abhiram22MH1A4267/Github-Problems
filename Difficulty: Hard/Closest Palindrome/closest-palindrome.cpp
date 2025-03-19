//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool ispalindrome(string num){
        int n = num.length();
        for(int i = 0; i < n/2; i++){
            if((num[i] != num[n-i-1])) return false;
        }
        return true;
    }

long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if (!isEvenLength) leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
    
	long long int closestPalindrome(long long int number){
	    // Code here
	    
	    string numberStr = to_string(number);
        int length = numberStr.length();
	    
        if (number < 10 || ispalindrome(numberStr)) return number;
        if (number == 11) return 9;

        
        
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);
        palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;

        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;

        for (long long candidate : palindromeCandidates) {
            if (candidate == number) continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }

        return nearestPalindrome;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends