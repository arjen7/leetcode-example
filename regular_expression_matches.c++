
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> arr(p.size()+1,vector<bool>(s.size()+1,0));
        arr[0][0]=1;
        for(int i=0;i<p.size();i++)
            for(int j=0;j<=s.size();j++)
                if(p[i]=='*')
                    arr[i+1][j]=arr[i-1][j]||(j&&arr[i+1][j-1]&&(p[i-1]==s[j-1]||p[i-1]=='.'));
                else if(j<s.size()&&(p[i]==s[j]||p[i]=='.'))
                    arr[i+1][j+1]=arr[i][j];
                    
        /*for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++)
                cout<<arr[i][j]<<"\t";
            cout<<endl;
        }*/
        return arr[p.size()][s.size()];
    }
};
