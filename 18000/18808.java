import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, m, k, answer;
	static class Sticker {
		int[][] area;
		Sticker(int x, int y) {
			area = new int[x][y];
		}
	}
	static Sticker[] stickers;
	static int[][] vis;
	
    static void input() throws IOException {
    	st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	k = Integer.parseInt(st.nextToken());
    	vis = new int[n][m];
    	stickers = new Sticker[k];
    	for(int i = 0;i < k; ++i) {
        	st = new StringTokenizer(br.readLine());
        	int r = Integer.parseInt(st.nextToken());
        	int c = Integer.parseInt(st.nextToken());
        	stickers[i] = new Sticker(r, c);
        	for(int x = 0;x < r; ++x) {
            	st = new StringTokenizer(br.readLine());
        		for(int y = 0;y < c; ++y) { 
        			stickers[i].area[x][y] = Integer.parseInt(st.nextToken());
        		}
        	}
    	}
    	answer = 0;
    }
    
    static void canAttach(int index) {
    	for(int r = 0;r < 4; ++r) {
			int[][] rotated = rotate(stickers[index].area.length, stickers[index].area[0].length, r, index);
    		for(int x = 0;x < n; ++x) {
    			for(int y = 0; y < m; ++y) {
    				int row = rotated.length - 1, col = rotated[0].length - 1;
    				if(!range(x, y) || !range(x + row, y) || 
    					!range(x, y + col) || !range(x + row, y + col)) continue;
    				
    				if(attached(rotated, x, y)) {
    					for(int i = x; i < x + rotated.length; ++i) {
    						for(int j = y; j < y + rotated[0].length; ++j) {
    							if(vis[i][j] == 1) continue;
    							vis[i][j] = rotated[i - x][j - y];
    							if(vis[i][j] == 1)++answer;
    						}
    					}
    					return;
    				}
    			}
    		}
    	}
    }
    
    static boolean attached(int[][] area, int x, int y) {
    	for(int i = x; i < x + area.length; ++i) {
    		for(int j = y; j < y + area[0].length; ++j) {
    			if(vis[i][j] == area[i - x][j - y] && area[i - x][j - y] == 1) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
    
    static int[][] rotate(int x, int y, int r, int index) {
    	int[][] area;
    	if(r == 0) {
    		area = new int[x][y];
    		for(int i = 0;i < x; ++i) {
    			for(int j = 0;j < y; ++j) {
    				area[i][j] = stickers[index].area[i][j];
    			}
    		}
    	} else if(r == 1) {
    		area = new int[y][x];
    		for(int i = 0;i < y; ++i) {
    			for(int j = 0;j < x; ++j) {
    				area[i][j] = stickers[index].area[x - 1 - j][i];
    			}
    		}
    	} else if(r == 2) {
    		area = new int[x][y];
    		for(int i = 0;i < x; ++i) {
    			for(int j = 0;j < y; ++j) {
    				area[i][j] = stickers[index].area[x - 1 - i][y - 1 - j];
    			}
    		}   		
    	} else {
    		area = new int[y][x];
    		for(int i = 0;i < y; ++i) {
    			for(int j = 0;j < x; ++j) {
    				area[i][j] = stickers[index].area[j][y - 1 - i];
    			}
    		}
    	}
    	return area;
    }
    
    static void solution() {
    	for(int i = 0;i < k; ++i) {
    		//1. 3중 for문 돌면서 위치 찾기
    		//방향 돌리기, x칸, y칸
    		canAttach(i);
    	}
    	System.out.println(answer);
    }
    
    static boolean range(int x, int y) {
    	return x >= 0 && x < n && y >= 0 && y < m;
    }
	
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
