    function countdown(i)
    {
        "use strict";
        var s="";
        while(i--){
            var k=i;
            for(k;k>0;k--) {
                s+=i;
            }
            s+="<br>";
        }
        return s;


    }