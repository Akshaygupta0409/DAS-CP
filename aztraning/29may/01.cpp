void solve(){
    
    string s;
    cin>>s;
    int n=s.length();
    
    bool is_balaced = 1;
    int depth = 0;
    for(int i=0;i<n;i++){
        char v = s[i];
        if(v=='(')depth++;
        if(v==')')depth--;
        if(depth<0){ // criteria 1.
            is_balaced = 0;
            break;
        }
    }
    
    if(depth!=0)is_balaced=0;
    if(is_balaced){
        cout<<"Hey it's balanced";
    }else{
        cout<<"Correct it";
    }
}