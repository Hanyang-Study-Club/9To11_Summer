// 65                                                                 90
// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 12 11 10 9 8 7 6 5 4 3 2 1   
// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R S T U V W X Y Z 
class Solution {
    
    public int alp(char c){
        int n1 = c-65;
        int n2 = 91-c;
        return n1>n2?n2:n1;
    }
    
    public int solution(String name) {
        int size = name.length();
        int answer = 0;
        
        char[] c_n = name.toCharArray();
        
        int cursor = size - 1; // 오른쪽으로만 움직였을 경우 --> 커서 이동의 최대값

        int a_end = 0;
        for(int i = 0; i < size; i++){
            answer+=alp(c_n[i]);
            if(i+1 < size && c_n[i+1] == 'A'){
                a_end = i+1;
                for(int a = i+2; a < size; a++){
                    if(c_n[a] == 'A') a_end = a;
                    else break;
                }

                int right = i*2 + (size-a_end-1);
                int left = (size-a_end-1)*2 + i;
                //System.out.println(a_end+"   "+right + "   " + left);
                int dir = right> left ? left : right;
                cursor = cursor > dir ? dir : cursor;
            }
            
        }
              //  System.out.println(alp('A')+ " "+cursor);
        return answer + cursor;
    }
}
