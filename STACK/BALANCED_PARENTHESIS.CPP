char* isBalanced(char* s) {
    int len=strlen(s),top=-1;
    char stack[len];
    for(int i=0;i<len;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stack[++top]=s[i];
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(top==-1){
                return "NO";
            }
            else {
                char temp=stack[top--];
                if((s[i]==')'&&temp!='(')||(s[i]=='}'&&temp!='{')||(s[i]==']'&&temp!='[')){
                    return "NO";
                }
            }
        }
    }
    if(top>0){
        return "NO";
    }
    return "YES";
}
