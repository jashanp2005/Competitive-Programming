#include <bits/stdc++.h>
using namespace std;

vector<int> lpsfind(string s) {
	int n = s.length();
	vector<int> lps(n, 0);
	int suf = 1, pre = 0;
	    
	while(suf < n){
	   if(s[suf] == s[pre]){
	       lps[suf] = pre+1;
	       suf++;
	       pre++;
	   }
	   else{
	       if(pre == 0){
	           lps[suf] = 0;
	           suf++;
	       }
	       else{
	           pre = lps[pre-1];
	       }
	   }
	}
	return lps;
}

int firstOccurence(string haystack, string needle){
    // to get first occurence of needle in haystack

    vector<int> lps = lpsfind(needle);

    int i = 0, j = 0;
    int n = haystack.length(), m = needle.length();

    while(i < n && j < m){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }
        else{
            if(j == 0) i++;
            else{
                j = lps[j-1];
            }
        }
    }
    if(j == m) return i-j;
    return -1;
}

int main() {
    

    return 0;
}