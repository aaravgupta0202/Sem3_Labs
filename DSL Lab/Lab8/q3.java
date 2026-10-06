class Book {
    String title;
    String author;

    // Constructor
    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    // Method to display book details
    void displayBookDetails() {
        System.out.println("Title  : " + title);
        System.out.println("Author : " + author);
    }
}

// Derived class
class EBook extends Book {
    String format;

    // Constructor
    EBook(String title, String author, String format) {
        super(title, author);
        this.format = format;
    }

    // Method to display complete e-book details
    void displayEBookDetails() {
        displayBookDetails();
        System.out.println("Format : " + format);
        System.out.println();
    }
}

// Main class
public class q3 {
    public static void main(String[] args) {

        EBook book1 = new EBook(
            "The Alchemist",
            "Paulo Coelho",
            "PDF"
        );

        EBook book2 = new EBook(
            "Wings of Fire",
            "A.P.J. Abdul Kalam",
            "EPUB"
        );

        EBook book3 = new EBook(
            "Java Programming",
            "Herbert Schildt",
            "PDF"
        );

        EBook book4 = new EBook(
            "Clean Code",
            "Robert C. Martin",
            "EPUB"
        );

        System.out.println("===== E-BOOK DETAILS =====");

        book1.displayEBookDetails();
        book2.displayEBookDetails();
        book3.displayEBookDetails();
        book4.displayEBookDetails();
    }
}