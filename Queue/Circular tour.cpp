int tour(petrolPump p[],int n)
{
    int start=0;
    int curr_pet=0;
    int prev_pet=0;
    
    for(int i=0;i<n;i++)
    {
        curr_pet = curr_pet + (p[i].petrol - p[i].distance);
        if(curr_pet < 0)
        {
            start=i+1;   //if 'pi' fails, then no petrol pump before 'pi' can be the answer.
            prev_pet = prev_pet + curr_pet;
            curr_pet=0;
        }
    }
    
    if(prev_pet+curr_pet >=0)
    {
        return start;
    }
    
    return -1;
   //Your code here
}
