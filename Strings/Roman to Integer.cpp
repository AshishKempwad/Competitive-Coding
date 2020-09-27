int Solution::romanToInt(string A)
{
    int num = 0;
    int prev = 0;
    
    for(int i = A.size()-1; i>=0;i--)
    {
        switch(A[i])
        {
            case 'I' :
                if(prev <= 1)
                {
                    num = num+1;
                }
                else
                {
                    num = num - 1;
                }
                prev = 1;
                break;
                
             case 'V' :
                if(prev <= 5)
                {
                    num = num+5;
                }
                else
                {
                    num = num - 5;
                }
                prev = 5;
                break;  
                
             case 'X' :
                if(prev <= 10)
                {
                    num = num+10;
                }
                else
                {
                    num = num - 10;
                }
                prev = 10;
                break; 
                
             case 'L' :
                if(prev <= 50)
                {
                    num = num+50;
                }
                else
                {
                    num = num - 50;
                }
                prev = 50;
                break;    
            
             case 'C' :
                if(prev <= 100)
                {
                    num = num+100;
                }
                else
                {
                    num = num - 100;
                }
                prev = 100;
                break;
                
             case 'D' :
                if(prev <= 500)
                {
                    num = num+500;
                }
                else
                {
                    num = num - 500;
                }
                prev = 500;
                break; 
                
             case 'M' :
                if(prev <= 1000)
                {
                    num = num+1000;
                }
                else
                {
                    num = num - 1000;
                }
                prev = 1000;
                break;    
            default :
                 break;
        }
    }
    
    return num;
}
