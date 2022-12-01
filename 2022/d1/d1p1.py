running_total = 0
current_max = 0

with open("d1.in") as file:
    for line in file.readlines():
        if line == "\n":
            if running_total > current_max:
                current_max = running_total
            running_total = 0
            print(current_max)
        else:
            running_total += int(line)

print(current_max)
