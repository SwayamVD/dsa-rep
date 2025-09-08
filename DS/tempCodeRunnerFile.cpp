t pivot = partition(arr,s,e);
        quick(arr,0,pivot-1);
        quick(arr,pivot,e);