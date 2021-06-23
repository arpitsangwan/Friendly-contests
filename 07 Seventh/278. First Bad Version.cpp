//https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int check(int s,int e){
       int mid=s+(e-s)/2;
        if(s==e){return s;}
       if(isBadVersion(mid)){
           return check(s,mid);
       } 
        return check(mid+1,e);
    }
    
    int firstBadVersion(int n) {
      return check(1,n);
       
    }
};