/** Weekly Challenge - week 4
  * 
  * @prerna(1910990964)
  * 
**/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

int ulta_b_s(int* a, int left, int right, int b) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == b) {
            return mid;
        }
        else if(b > a[mid]){
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}
int binary_search(int* a, int left, int right, int b) {
    while(left <= right) {
        int mid = (left + right) / 2;
        if(a[mid] == b) {
            return mid;
        }
        else if(a[mid] > b) {
            right = mid - 1;
        }
        else if(a[mid] < b) {
            left = mid + 1;
        }
    }
    return -1;
}
int solve(int* a, int n, int b) {
    //finding bitonic point in O(log N) 
    int left = 0;
    int right = n-1;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(a[mid] > a[mid - 1] && a[mid] < a[mid + 1]) {
            left = mid + 1;
        }
        else if(a[mid] < a[mid - 1] && a[mid] > a[mid + 1]) {
            right = mid - 1;
        }
        else if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1]) {
            mid = mid;// mid now stores the final ans i.e index of bitonic point.
            //printf("%d\n",mid);
            break;
        }
        //mid now have index of bitonic point
    }


    if(b == a[mid]) {
        return mid;
    }
    else {
        int l = binary_search(a, 0, mid, b);
        int r = ulta_b_s(a, mid , n - 1, b);
        if(l == -1 ) {
            return r;
        }
        return l;
    }
    return 0;
}
