
import java.util.*;

class Solution {
    public int minimumLines(int[][] stockPrices) {

        // Sort based on day
        Arrays.sort(stockPrices, (a, b) -> Integer.compare(a[0], b[0]));
        int n = stockPrices.length;
        // If only one point exists
        if (n <= 1) {
            return 0;
        }
        int lines = 1;
        for (int i = 2; i < n; i++) {
            long x1 = stockPrices[i - 1][0] - stockPrices[i - 2][0];
            long y1 = stockPrices[i - 1][1] - stockPrices[i - 2][1];
            long x2 = stockPrices[i][0] - stockPrices[i - 1][0];
            long y2 = stockPrices[i][1] - stockPrices[i - 1][1];
            
            if (y1 * x2 != y2 * x1) {
                lines++;
            }
        }

        return lines;
    }
}
