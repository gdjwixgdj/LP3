# Recursive Fibonacci Series with Step Count

COUNT = 0  # Initialize step counter

# Recursive function to calculate Fibonacci number
def fibonacci(n):
    global COUNT       # Access global counter
    COUNT += 1         # Count each function call

    if n <= 1:         # Base condition
        return n

    # Recursive calls
    return fibonacci(n-1) + fibonacci(n-2)


# Take input from user
n = int(input("Enter number of terms: "))

if n <= 0:
    print("Enter a positive number.")

else:
    print("Fibonacci Series:")

    # Print Fibonacci series
    for i in range(n):
        print(fibonacci(i), end=" ")

# Display total recursive function calls
print("\nTotal Steps:", COUNT)