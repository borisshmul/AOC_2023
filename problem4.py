def process_file(filename):
    sum_of_max_multiplied_values = 0

    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split()
            game_data = ' '.join(parts[2:]).split(';')

            max_red = max_green = max_blue = 0

            for portion in game_data:
                items = portion.strip().split(',')
                for item in items:
                    count, color = item.strip().split()
                    count = int(count)

                    if color == "red":
                        max_red = max(max_red, count)
                    elif color == "green":
                        max_green = max(max_green, count)
                    elif color == "blue":
                        max_blue = max(max_blue, count)

            max_product = max_red * max_green * max_blue
            sum_of_max_multiplied_values += max_product

    return sum_of_max_multiplied_values

# Replace 'yourfile.txt' with the path to your file
sum_of_max_multiplied_values = process_file('problem4.txt')
print("Sum of maximum multiplied values across all games:", sum_of_max_multiplied_values)
