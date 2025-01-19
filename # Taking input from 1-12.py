# Taking input from 1-12
month_number = int(input("Enter a number from 1 to 12: "))

# Mapping month number to month name
months = {
    1: "January", 2: "February", 3: "March", 4: "April",
    5: "May", 6: "June", 7: "July", 8: "August",
    9: "September", 10: "October", 11: "November", 12: "December"
}

# Displaying corresponding month
if 1 <= month_number <= 12:
    print(f"The corresponding month is {months[month_number]}")
else:
    print("Invalid input. Please enter a number from 1 to 12.")
