public class Main {
    private int id;
    private int age;
    private String name;
    private double score;
    private static int count;

    public Main(int age, String name, double score) {
        this.id = ++count;
        this.age = age;
        this.name = name;
        this.score = score;
    }


    public toString() {
        return "id: " + id + ", age: " + age + ", name: " + name + ", score: " + score;
    }

    // main method
    public static void main(String[] args) {
        Main example1 = new Main(25, "John", 90.5);

        System.out.println(example1);
    }
}
