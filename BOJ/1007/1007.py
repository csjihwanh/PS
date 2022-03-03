import itertools
import math

t = int(input())
for i in range(0, t) :
    n = int(input())
    arr = [];
    for j in range(n) :
        x,y= input().split()
        arr.append([int(x), int(y)])
    
    min_dist = 987654321
    
    for subset in itertools.combinations(arr, int(n/2)):
        sum_x,sum_y = float(0), float(0);
        
        for arr_elem in arr :
            sum_x+= arr_elem[0];
            sum_y += arr_elem[1];
        
        for arr_elem in subset :
            sum_x -= 2*arr_elem[0];
            sum_y -= 2*arr_elem[1];
        
        
        dist = float(math.sqrt(pow(sum_x,2)+pow(sum_y,2)))    
        
        if(dist < min_dist) :
            min_dist = dist;
    
    print(min_dist);