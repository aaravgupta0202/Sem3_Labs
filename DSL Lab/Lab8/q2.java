class Product {
    int id;
    String name;
    double price;

    // Constructor
    Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    // Method to display product details
    void showDetails() {
        System.out.println("Product ID : " + id);
        System.out.println("Name       : " + name);
        System.out.println("Price      : " + price);
    }
}

// Subclass Clothing
class Clothing extends Product {
    String size;
    String material;

    // Constructor
    Clothing(int id, String name, double price,
             String size, String material) {
        super(id, name, price);
        this.size = size;
        this.material = material;
    }

    // Method overriding
    @Override
    void showDetails() {
        System.out.println("Product Type : Clothing");
        System.out.println("Product ID   : " + id);
        System.out.println("Name         : " + name);
        System.out.println("Price        : " + price);
        System.out.println("Size         : " + size);
        System.out.println("Material     : " + material);
        System.out.println();
    }
}

// Subclass Electronics
class Electronics extends Product {
    int warranty;
    String brand;

    // Constructor
    Electronics(int id, String name, double price,
                int warranty, String brand) {
        super(id, name, price);
        this.warranty = warranty;
        this.brand = brand;
    }

    // Method overriding
    @Override
    void showDetails() {
        System.out.println("Product Type : Electronics");
        System.out.println("Product ID   : " + id);
        System.out.println("Name         : " + name);
        System.out.println("Price        : " + price);
        System.out.println("Warranty     : " + warranty + " years");
        System.out.println("Brand        : " + brand);
        System.out.println();
    }
}

// Main class
public class q2 {
    public static void main(String[] args) {

        // Product array containing objects of different subclasses
        Product[] products = new Product[4];

        products[0] = new Clothing(
            101, "T-Shirt", 799.0,
            "L", "Cotton"
        );

        products[1] = new Electronics(
            102, "Laptop", 55000.0,
            2, "Dell"
        );

        products[2] = new Clothing(
            103, "Jeans", 1499.0,
            "M", "Denim"
        );

        products[3] = new Electronics(
            104, "Smartphone", 25000.0,
            1, "Samsung"
        );

        System.out.println("===== E-COMMERCE PRODUCT DETAILS =====");
        System.out.println();

        // Runtime polymorphism
        for (Product product : products) {
            product.showDetails();
        }
    }
}
