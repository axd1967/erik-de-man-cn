               { yy=substr($0,1,2)+0;
                 mm=substr($0,3,2)+0;
                 dd=substr($0,5,2)+0;

                 if(yy<90) 
                 { if(yy<10) yys="200"yy; else yys="20"yy;
                   
                   prediction=substr($0,59,6);

                   if(prediction!="      ")
                   { if((mm== 1)&&(dd==1)) print yys ".00",prediction;
                     if((mm== 4)&&(dd==1)) print yys ".25",prediction;
                     if((mm== 7)&&(dd==1)) print yys ".50",prediction;
                     if((mm==10)&&(dd==1)) print yys ".75",prediction;
                   }
                 }
               }
                   
