# Function to read from file and create the mapping
def create_time_distance_map(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Extracting time and distance values
    time_values = [int(val) for val in lines[0].split()[1:]]
    distance_values = [int(val) for val in lines[1].split()[1:]]

    # Creating a dictionary to map time to distance
    return dict(zip(time_values, distance_values))

# File path
file_path = 'problem13.txt'
mulitplied_num=1
# Creating the time-distance map
time_distance_map = create_time_distance_map(file_path)

for time, distance in time_distance_map.items():
        counter=0
        # Example check: if the distance is greater than 100
        for i in range(1,time):
            if (time-i)*i > distance:
                counter+=1
        print(counter)
        mulitplied_num*=counter

# Displaying the dictionary
print(time_distance_map)
print(mulitplied_num)
