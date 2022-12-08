/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    void rserialize(TreeNode *root, string& str){
        if(root == nullptr){
            str+="None,";
        }else{
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for(auto& ch: data){
            if(ch == ','){
                dataArray.push_back(str);
                str.clear();
            }else{
                str.push_back(ch);
            }
        }
        if(!str.empty()){
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }

    TreeNode* rdeserialize(list<string>& dataArray){
        if(dataArray.front() == "None"){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }



};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));