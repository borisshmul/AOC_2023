def has_adjacent_symbol(matrix, row, col):
    for r in range(max(0, row - 1), min(len(matrix), row + 2)):
        for c in range(max(0, col - 1), min(len(matrix[r]), col + 2)):
            if r == row and c == col:
                continue
            if matrix[r][c] != '.' and not matrix[r][c].isdigit():
                return True
    return False

def sum_part_numbers(schematic):
    part_numbers_sum = 0

    for row in range(len(schematic)):
        col = 0
        while col < len(schematic[row]):  
            char = schematic[row][col]
            if char.isdigit():
                number = char
                col += 1
                while col < len(schematic[row]) and schematic[row][col].isdigit():
                    number += schematic[row][col]
                    col += 1
                for i in range(len(number)):
                    if has_adjacent_symbol(schematic, row, col - len(number) + i):
                        part_numbers_sum += int(number)
                        #print(number)
                        break
            else:
                col += 1
    
    return part_numbers_sum

def read_schematic_from_file(file_path):
    with open(file_path, 'r') as file:
        return [line.strip() for line in file.readlines()]

schematic = read_schematic_from_file('problem6.txt')

sum_of_part_numbers = sum_part_numbers(schematic)
print("Sum of part numbers:", sum_of_part_numbers)
