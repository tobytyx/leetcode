int slen = s.length(), plen = p.length();
        if(plen == 0 && slen == 0){
            return true;
        }
        if(slen == 0 || plen == 0){
            return false;
        }
        vector<bool> match(slen+1, false);
        match[0] = true;
        for(int i=0; i<plen; i++){
            bool pre = true;
            for(int j=1; j<=slen; j++){
                bool tmp = match[j];
                if(p[i] == '*'){
                    if(p[i-1] == s[j-1] || p[i-1] == '.'){
                        match[j] = match[j] || match[j-1] || match[j-2];
                    }
                    else{
                        match[j] = match[j-2];
                    }
                }
                else{
                    match[j] = pre && (p[i] == '.' || p[i] == s[j-1]);
                }
                pre = tmp;
            }
        }
        return match[slen];