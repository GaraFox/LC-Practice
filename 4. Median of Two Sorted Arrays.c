double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* merged = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nums1Size || j < nums2Size){
        if(i == nums1Size){
            merged[k] = nums2[j];
            j++;
        }
        else if(j == nums2Size){
            merged[k] = nums1[i];
            i++;
        }
        else{
            if(nums1[i] < nums2[j]){
                merged[k] = nums1[i];
                i++;
            }
            else{
                merged[k] = nums2[j];
                j++;
            }
        }
        k++;
    }
    
    for(int i = 0; i < (nums1Size + nums2Size); i++){
        printf("%d ", merged[i]);
    }

    if((nums1Size + nums2Size)%2 == 1){
        return merged[(nums1Size + nums2Size) / 2];
    }
    else if((nums1Size + nums2Size)%2 == 0){
        int a = merged[(nums1Size + nums2Size) / 2];
        int b = merged[(nums1Size + nums2Size) / 2 - 1];
        
        return (a + b) / 2.0;
    }

    return -1; // Add this for LD to compile. 
}