class BrowserHistory {
public:
    list<string> ans;
    list<string>::iterator it;
    BrowserHistory(string homepage) {
        ans.push_back(homepage);
        it=ans.begin();
    }
    
    void visit(string url) {
        auto next=it;
        next++;
        ans.erase(next,ans.end());
        ans.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(steps-- && it!=ans.begin()){
            it--;
        }
        return *it; //it is apointer we need to return string stored at that pinter this process is also called dereferencing

    }
    
    string forward(int steps) {
        while(steps-- && it!=(--ans.end())){
            it++;
        }
        return *it; //it is apointer we need to return string stored at that pinter this process is also called dereferencing
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */