#include <stdio.h>

int main() {

    int itemCount = 0, continueShopping = 1, overnightShipping = 0, discount = 0;
    float totalPrice = 0;


    while (continueShopping || itemCount < 2) {

        char itemName[50];
        float itemPrice;

        printf("Enter item name: ");
        scanf("%s", itemName);

        printf("Enter item price: $");
        scanf("%f", &itemPrice);


        printf("Need overnight shipping? (1 for Yes, 0 for No): ");
        scanf("%d", &overnightShipping);


        float shippingCost = (itemPrice < 10) ? 2 : 3;
        if (overnightShipping) {
            shippingCost += 5;
        }


        printf("\nItem: %s\n", itemName);
        printf("Price: $%.2f\n", itemPrice);
        printf("Shipping Cost: $%.2f\n", shippingCost);


        totalPrice += (itemPrice + shippingCost);
        itemCount++;


        if (itemCount >= 2) {
            printf("\nDo you want to continue shopping? (1 for Yes, 0 for No): ");
            scanf("%d", &continueShopping);
        } else {
            printf("\nA minimum of 2 items is required for one order. Adding more items...\n");
        }
    }


    if (itemCount > 5) {
        discount = 20;
        totalPrice *= (1 - discount / 100.0);
    }


    printf("\n------ Receipt ------\n");
    printf("Items ordered: %d\n", itemCount);
    printf("Total Price: $%.2f\n", totalPrice);
    if (discount > 0) {
        printf("Discount Applied: %d%%\n", discount);
    }
    printf("Thank you for shopping with us!\n");

    return 0;
}
