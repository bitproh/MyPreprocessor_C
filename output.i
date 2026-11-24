

int add_bonus(int x) {
    return x + 5;
}



int main(void) {
    int count = 10; 
    int total = add_bonus(count);

    
    printf("%s: %d\n", "Hello from header", total);
    return 0;
}
