# Iterative Fibonacci Series with Step Count

COUNT = 0

n = int(input("Enter number of terms: "))

first = 0
second = 1

if n < 0:
    print("Enter a valid positive number.")

else:
    for i in range(n):
        print(first, end=" ")

        next_term = first + second
        COUNT += 1

        first = second
        COUNT += 1

        second = next_term
        COUNT += 1

print("\nTotal steps:", COUNT)