class Solution {
  public:
    static bool fun(string a,string b){
	    string s1 = a+b;
	    string s2 = b+a;
	    return s1>s2;
	}
    string findLargest(vector<int> &vec) {
        // code here
        vector<string>arr;
        for(int i : vec){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end(),fun);
	    if(arr[0] == "0"){
	        return "0";
	    }
	    string ans = "";
	    for(auto it : arr){
	        ans += it;
	    }
	    return ans;
    }
};