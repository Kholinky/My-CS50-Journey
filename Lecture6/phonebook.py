people = {
    "Yulia": "+1-123-123-1000",
    "David": "+1-123-122-1123",
    "John": "+1-123-121-1112",
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
