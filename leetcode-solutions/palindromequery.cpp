class CustomDS{
    vector<int> is_match;
    vector<int> charcntA[26];
    vector<int> charcntB[26];
    int n;
    void init(string a,string b){
        n=a.length();
        is_match.assign(n,0);
        for(int i=0;i<26;i++){
            charcntA[i].assign(n,0);
            charcntB[i].assign(n,0);
        } 
        for(int i=0;i<n;i++){
            if(a[i]==b[i]){
                is_match[i]=1;
            }else{
                is_match[i]=0;
            }
            charcntA[a[i]-'a'][i]=1;
            charcntB[b[i]-'a'][i]=1;
        }
        for(int i=1;i<n;i++){
            is_match[i]+=is_match[i-1];
            for(int ch=0;ch<26;ch++){
                charcntA[ch][i]+= charcntA[ch][i-1];
                charcntB[ch][i]+= charcntB[ch][i-1];
            }
        }
    }
    bool is_same(int l,int r){
        if(l>r)return true;
        int prefix_sum = is_match[r]-(l>0?is_match[l-1]:0);
        if(prefix_sum==(r-l+1)){
            return true;
        }else{
            return false;
        }   
    }
    bool is_same_rearrage(int l,int r){
        if(l>r)return true;
        for(int ch=0;ch<26;ch++){
            int acnt = charcntA[ch][r]-(l>0?charcntA[ch][l-1]:0);
            int bcnt = charcntB[ch][r]-(l>0?charcntB[ch][l-1]:0);
            if(acnt!=bcnt)return false;
        }
        return true;
    }
    bool query(int l,int r){
        return is_same(0,l-1) && is_same_rearrage(l,r) && is_same(r+1,n-1);
    }
    vector<int> charfreq(int l,int r,bool forA){
        vector<int> fc(26,0);
        for(int ch=0;ch<26;ch++){
            if(forA)fc[ch]=charcntA[ch][r]-(l>0?charcntA[ch][l-1]:0);
            else{fc[ch]=charcntB[ch][r]-(l>0?charcntB[ch][l-1]:0);}
        }
        return fc;
    }
    bool query2(int l1,int r1,int l2,int r2){
        if(/*overlap*/){
            auto a = charfreq(l1,r1,1);
            auto need_to_remove_from_a = charfreq((/*[l1,r1]-overlap,0*/));
            
            
            auto b = charfreq(l2,r2,0);
            auto need_to_remove_from_b = charfreq((/*[l2,r2]-overlap,1*/));
            
            // left should match.
        }else{
            
        }
    }
    
}
 
 
 
 
class Solution {    
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        
    }
};