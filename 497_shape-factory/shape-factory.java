/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/shape-factory
@Language: Java
@Datetime: 16-06-13 04:48
*/

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory sf = new ShapeFactory();
 * Shape shape = sf.getShape(shapeType);
 * shape.draw();
 */
interface Shape {
    void draw();
}

class Rectangle implements Shape {
    // Write your code here
    public void draw() {
        System.out.println(" ---- ");
        System.out.println("|    |");
        System.out.println(" ---- ");
    }
}

class Square implements Shape {
    // Write your code here
    public void draw() {
        System.out.println(" ---- ");
        System.out.println("|    |");
        System.out.println("|    |");
        System.out.println(" ---- ");
    }
}

class Triangle implements Shape {
    // Write your code here
    public void draw() {
        System.out.println("  /\\");
        System.out.println(" /  \\");
        System.out.println("/____\\");
        
    }
}

public class ShapeFactory {
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    public Shape getShape(String shapeType) {
        // Write your code here
        if ("Square".equals(shapeType)) return new Square();
        if ("Triangle".equals(shapeType)) return new Triangle();
        if ("Rectangle".equals(shapeType)) return new Rectangle();
        return null;
    }
}