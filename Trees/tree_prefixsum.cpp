#include<bits/stdc++.h>


//Problem : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

#define ll long long 
#define mod 1000000007
class Solution {
public:
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> prefix;
        postOrder(root, prefix);
    
        ll total = prefix[root];
        ll ans = 0;
        for(auto [x,y]: prefix)
        {
            if(x==root) continue;

            ll curr = total-y;
            ans = max(ans, curr*y);
            //cout<<x->val<<"->"<<y<<endl;
        }
        return ans%mod;
    }

    int postOrder(TreeNode* root, unordered_map<TreeNode*, int> &prefix)
    {
        if(!root) return 0;

        int l = postOrder(root->left, prefix);
        int r = postOrder(root->right, prefix);

        prefix[root] += l+r+root->val;
        return prefix[root];
    }
};

