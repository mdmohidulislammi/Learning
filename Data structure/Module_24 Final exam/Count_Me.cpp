#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string sentence;
        getline(cin,sentence);
        stringstream ss(sentence);
        string word;
        map<string,int>m;
        int mx=0;
        string sen;
        while(ss>>word)
        {
            m[word]++;
            if(m[word]>mx)
            {
                mx=m[word];
                sen=word;
            }
        }
        cout<<sen<<" "<<mx<<endl;
    }
    return 0;
}
// Hints
// মডিউল 23-6 ভিডিওতে দেখানো কোডটির মতো করে ফেলতে পারেন।
// এক্সট্রা হিসেবে একটি string variable নিয়ে নিতে পারেন আন্সার ওয়ার্ডটি রাখার জন্য। 
//আরেকটি mx variable নিয়ে নিতে পারেন max count track রাখার জন্য। 
//যখনি mp[word]++ করবেন তারপর একটি কন্ডিশন দিয়ে চেক করে ফেলতে পারেন এই word এর count আপনার mx variable থেকে বেশি হয়ে গেছে কিনা। হয়ে গেলে mx variable কে আপডেট করে ফেলতে পারেন।
// এবং সাথে সাথে আন্সারের মধ্যে word টিকে রেখে দিতে পারেন। তারপর লুপ শেষে আন্সার word টি এবং
// mx variable টি প্রিন্ট করে দিলেই হবে।

