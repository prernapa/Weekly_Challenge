/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
long long int chop (int* a, int n, int x) {
    long long int ans = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] > x) {
            ans += a[i] - x;
        }
    }
    //printf("%d ",ans);
    return ans;
}

int solve(int* a, int n, int b) {
    int max = 0;
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    //we have to binarysearch the minimum number that can chop the sticks atleast b meters 
    // the range of binary search will be 0 to max 
    int left = 0;
    int right = max;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if((chop(a, n, mid) >= b )&& (chop(a, n, mid + 1) < b) ) {
            return mid;
        }
        else if(chop(a, n, mid) > b) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
}
