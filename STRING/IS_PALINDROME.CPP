	int isPlaindrome(string S)
	{
	    int s = 0,e = S.length()-1;
	    while(s <= e){
	        if(S[s++] != S[e--]){
	            return 0;
	        }
	    }
	    return 1;
	}