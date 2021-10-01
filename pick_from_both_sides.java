//Interview Bit -> ARRAYS
//Pick From Both Sides
// 
// Prerna@1910990964
// 
public class Solution {
    public int solve(int[] A, int B) {
        int n = A.length;
        int sum = 0;
        int i, j = n - 1;
	//finding sum od first B elements
	for(i = 0; i < B; i++) {
            sum += A[i];
        }
        int ans = sum;
	//subtrtracting from begining and adding the last element 
	//1 2 3 4 5
	//1+2    
	//3-2+5
	//1-1+5+4
	//
        while(B != 0) {
            B--;
            i--;
            sum -= A[i];
            sum += A[j];
            j--;
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}

