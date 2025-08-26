import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Menu extends JFrame {

    private static final String[] BREAKFAST_ITEMS = {"Idli", "Masala Dosa", "Aloo Paratha", "Chai"};
    private static final String[] LUNCH_ITEMS = {"Veg Thali", "Chicken Curry", "Dal Tadka", "Fish Fry"};
    private static final String[] DINNER_ITEMS = {"Paneer Butter Masala", "Biryani", "Roti with Sabji", "Palak Paneer"};
    private static final String[] SNACKS_ITEMS = {"Samosa", "Pakora", "Vada Pav", "Chaat"};
    private static final String[] DRINKS_ITEMS = {"Lassi", "Masala Chai", "Coconut Water", "Buttermilk"};

    private final ArrayList<String> orderList = new ArrayList<>();
    private final JTextArea orderDisplayArea;

    public Menu() {
        setTitle("Indian Food Menu");
        setSize(500, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        // Create a main panel for the menu categories
        JPanel menuPanel = new JPanel();
        menuPanel.setLayout(new GridLayout(5, 1, 10, 10));
        menuPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Create buttons for each category
        menuPanel.add(createCategoryButton("Breakfast", BREAKFAST_ITEMS));
        menuPanel.add(createCategoryButton("Lunch", LUNCH_ITEMS));
        menuPanel.add(createCategoryButton("Dinner", DINNER_ITEMS));
        menuPanel.add(createCategoryButton("Snacks", SNACKS_ITEMS));
        menuPanel.add(createCategoryButton("Drinks", DRINKS_ITEMS));

        add(menuPanel, BorderLayout.NORTH);

        // Order display area
        JPanel orderPanel = new JPanel();
        orderPanel.setLayout(new BorderLayout(5, 5));
        orderPanel.setBorder(BorderFactory.createTitledBorder("Your Order"));

        orderDisplayArea = new JTextArea(10, 30);
        orderDisplayArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(orderDisplayArea);
        orderPanel.add(scrollPane, BorderLayout.CENTER);

        JButton placeOrderButton = new JButton("Place Order");
        placeOrderButton.addActionListener(e -> {
            if (orderList.isEmpty()) {
                JOptionPane.showMessageDialog(Menu.this, "Your cart is empty. Please add some items.");
            } else {
                JOptionPane.showMessageDialog(Menu.this, "Order placed successfully! Thank you for dining with us.");
                orderDisplayArea.setText("");
                orderList.clear();
            }
        });
        orderPanel.add(placeOrderButton, BorderLayout.SOUTH);

        add(orderPanel, BorderLayout.CENTER);

        // Image of Indian food
        JLabel imageLabel = new JLabel();
        imageLabel.setHorizontalAlignment(JLabel.CENTER);
        ImageIcon icon = new ImageIcon(new ImageIcon("food_image.jpg").getImage().getScaledInstance(150, 150, Image.SCALE_SMOOTH));
        imageLabel.setIcon(icon);
        add(imageLabel, BorderLayout.SOUTH);

        setVisible(true);
    }

    private JButton createCategoryButton(String categoryName, String[] items) {
        JButton button = new JButton(categoryName);
        button.setFont(new Font("Arial", Font.BOLD, 16));
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showItemsDialog(categoryName, items);
            }
        });
        return button;
    }

    private void showItemsDialog(String title, String[] items) {
        // Create a panel to hold the radio buttons
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        
        ButtonGroup group = new ButtonGroup();
        JRadioButton[] radioButtons = new JRadioButton[items.length];
        
        for (int i = 0; i < items.length; i++) {
            radioButtons[i] = new JRadioButton(items[i]);
            group.add(radioButtons[i]);
            panel.add(radioButtons[i]);
        }

        int result = JOptionPane.showConfirmDialog(
            this,
            panel,
            "Select " + title + " Item",
            JOptionPane.OK_CANCEL_OPTION,
            JOptionPane.PLAIN_MESSAGE
        );

        if (result == JOptionPane.OK_OPTION) {
            for (JRadioButton button : radioButtons) {
                if (button.isSelected()) {
                    orderList.add(button.getText());
                    updateOrderDisplay();
                    break;
                }
            }
        }
    }

    private void updateOrderDisplay() {
        orderDisplayArea.setText("");
        if (orderList.isEmpty()) {
            orderDisplayArea.append("No items ordered.");
        } else {
            for (int i = 0; i < orderList.size(); i++) {
                orderDisplayArea.append((i + 1) + ". " + orderList.get(i) + "\n");
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Menu::new);
    }
}