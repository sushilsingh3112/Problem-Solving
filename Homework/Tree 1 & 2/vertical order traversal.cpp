vector<vector<int>> verticalLTraversal(Node* root) {
        vector<vector<int>> ans;
       
        queue<pair<Node*, pair<int, int>>>q; 
        q.push({root,{0,0}});
       
        map<int, map<int, multiset<int>>>mp; 
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            Node* &node = front.first;
            auto coordinate = front.second;
            auto &row = coordinate.first;
            auto &col = coordinate.second;
            mp[col][row].insert(node -> data);
            if(node -> left){
                q.push({{node -> left},{row + 1, col - 1}});
            }
            if(node -> right){
                q.push({{node -> right},{row + 1, col + 1}});
            }
        }
       
        for(auto i:mp){
            auto &colmp = i.second;
            vector<int> verticalL;
            for(auto colmpi : colmp){
                auto &mset = colmpi.second;
                vertical.insert(verticalL.end(), mset.begin(), mset.end());
            }
            ans.push_back(verticalL);
        }
        return ans;
    }
