class Solution {
    public boolean canAliceWin(int n) {
        return canAliceWin(n, 10);
    }

    private boolean canAliceWin(int n, int take) {
        return n >= take && !canAliceWin(n - take, take - 1);
    }
}