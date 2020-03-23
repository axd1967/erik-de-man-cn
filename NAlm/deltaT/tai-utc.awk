BEGIN         { mon["JAN"]=0.00;
                mon["FEB"]=0.83;
                mon["MAR"]=0.17;
                mon["APR"]=0.25;
                mon["MAY"]=0.33;
                mon["JUN"]=0.42;
                mon["JUL"]=0.50;
                mon["AUG"]=0.58;
                mon["SEP"]=0.67;
                mon["OCT"]=0.75;
                mon["NOV"]=0.83;
                mon["DEC"]=0.92;
                n=0;
              }

              { if($1 > 1990) printf "%7.2f %5.2f\n",$1+mon[$2],$7;
              }

