# Function to read from file and create the mapping
def create_time_distance_map(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Extracting time and distance values
    time_values = [int(val) for val in lines[0].split()[1:]]
    distance_values = [int(val) for val in lines[1].split()[1:]]

    # Creating a dictionary to map time to distance
    return dict(zip(time_values, distance_values))

def concatenate_values(time_distance_map):
    concatenated_time = ''.join(str(time) for time in time_distance_map.keys())
    concatenated_distance = ''.join(str(distance) for distance in time_distance_map.values())
    
    return int(concatenated_time), int(concatenated_distance)
# File path
file_path = 'problem13.txt'
mulitplied_num=1
# Creating the time-distance map
time_distance_map = create_time_distance_map(file_path)

concatenated_time, concatenated_distance = concatenate_values(time_distance_map)      

counter=1
while((concatenated_time-counter)*counter<concatenated_distance):
    counter+=1
counter2=concatenated_time-1
while ((concatenated_time-counter2)*counter2<concatenated_distance):
    counter2-=1

print(counter2-counter+1)

