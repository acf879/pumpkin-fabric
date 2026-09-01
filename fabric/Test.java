class Test {
    private static long counter;

    public Test() {
    }

    public static void increment() {
        counter += 1;
    }

    public static long peek() {
        return counter;
    }
}
