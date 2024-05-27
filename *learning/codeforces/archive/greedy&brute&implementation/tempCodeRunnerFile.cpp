ng s; cin >> s;

    for (int i = 1; i < s.size(); ++i){
        if (9 - (s[i] - '0') < (s[i] - '0')){
            if (i == 0 && 9 - (s[i] - '0') == 0) continue;
            s[i] = 9 - (s[i] - '0');
        }
    }

    cou