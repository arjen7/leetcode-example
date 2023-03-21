class RangeModule {
    private:
    int start=0;
    int end=0;
    vector<pair<int,int>> removed;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        if(start==end){
            start=left;
            end=right;
        }
        else{
            if(left>end){
                removed.push_back(pair<int,int>(end,left));
                end=right;
            }
            else if(right<start){
                removed.push_back(pair<int,int>(right,start));
                start=left;
            }
            else{
                if(left<start)
                    start=left;
                if(right>end)
                    end=right;
            }
        }
        for(int i=0;i<removed.size();i++){
            if(left<=removed[i].first&&right>=removed[i].second)
                removed.erase(removed.begin()+i--);
            else if(left>removed[i].first&&right<removed[i].second){
                removed.push_back(pair<int,int>(right,removed[i].second));
                removed[i].second=left;
            }
            else if(right>removed[i].first&&right<removed[i].second)
                removed[i].first=right;
            else if(left<removed[i].second&&left>removed[i].first)
                removed[i].second=left;
        }
    }
    
    bool queryRange(int left, int right) {
        if(left<start||right>end)
            return false;
        else{
            for(int i=0;i<removed.size();i++){
                if(left<removed[i].first&&right>removed[i].second)
                    return false;
                if(left>=removed[i].first&&left<removed[i].second)
                    return false;
                if(right>removed[i].first&&right<=removed[i].second)
                    return false;
            }
        }
        return true;
    }
    
    void removeRange(int left, int right) {
        removed.push_back(pair<int,int>(left,right));
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
