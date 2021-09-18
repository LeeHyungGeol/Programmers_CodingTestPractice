import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] visited = new boolean[words.length];
        Queue<Node> q = new LinkedList<>();
        
        q.offer(new Node(begin, 0));
        
        while(!q.isEmpty()) {
            Node cur = q.poll();
            String temp = cur.getTmpWord();
            int count = cur.getCount();
            
            if(temp.equals(target)) {
                answer = count;
                break;
            }
            
            for(int i = 0; i < words.length; ++i) {
                int cnt = 0;
                for(int j = 0; j < words[i].length(); ++j) {
                    if(temp.charAt(j) != words[i].charAt(j)) {
                        ++cnt;
                    }
                }
                
                if(cnt == 1 && visited[i] == false) {
                    visited[i] = true;
                    q.offer(new Node(words[i], count + 1));
                }
            }
        }
        
        return answer;
    }
}

class Node {
    private String tmpWord;
    private int count;
    
    public Node(String tmpWord, int count) {
        this.tmpWord = tmpWord;
        this.count = count;
    }
    
    public String getTmpWord() {
        return this.tmpWord;
    }
    
    public int getCount() {
        return this.count;
    }
}