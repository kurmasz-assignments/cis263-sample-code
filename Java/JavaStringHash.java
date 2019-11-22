class JavaStringHash {

  public static int myHashCode(String s) {
    int answer = 0;
    for (int i = 0; i < s.length(); ++i) {
      answer = answer * 31 + s.charAt(i);
    }
    return answer;
  }

  public static void main(String[] args) {
    for (String s : args) {
      System.out.printf("%s: %d - %d\n", s, s.hashCode(), myHashCode(s));
    }
  }
}