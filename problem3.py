def is_portion_possible(data):
    for color, count in data:
        if (color == "red" and count > 12) or \
           (color == "green" and count > 13) or \
           (color == "blue" and count > 14):
            return False
    return True

def process_file(filename):
    sum_of_possible_games = 0

    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split()
            game_number = int(parts[1].rstrip(':'))
            is_game_possible = True

            portions = ' '.join(parts[2:]).split(';')
            for portion in portions:
                color_data = []
                items = portion.strip().split(',')
                for item in items:
                    count, color = item.strip().split()
                    color_data.append((color, int(count)))

                if not is_portion_possible(color_data):
                    is_game_possible = False
                    break

            if is_game_possible:
                sum_of_possible_games += game_number

    return sum_of_possible_games

# Replace 'yourfile.txt' with the path to your file
sum_of_possible_games = process_file('problem3.txt')
print("Sum of possible game IDs:", sum_of_possible_games)
