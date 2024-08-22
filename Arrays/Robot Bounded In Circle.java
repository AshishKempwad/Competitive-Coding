class Solution {
    public boolean isRobotBounded(String instructions) {
        int x = 0;
        int y = 0;
        int dir = 0;

        int dx[][] = {{0,1},{1,0},{0,-1},{-1,0}};

        for(int i=0;i<instructions.length();i++){
            if(instructions.charAt(i) == 'R'){
               dir = (dir+1)%4;
            }else if(instructions.charAt(i) == 'L'){
                dir = (dir+3)%4;
            }else{
                x += dx[dir][0];
                y += dx[dir][1];
            }
        }

        return x == 0 && y == 0 || dir > 0;
    }
}
