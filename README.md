# Student Management System

This program is a student management system application. You can record, list, update student information, and provide some statistical information based on their midterm and final grades.

## Features

- Add new student records
- List students (by number or by grades)
- Calculate class average
- Find the top-performing student
- Update student records


### 1. Add New Record

To add a new student record, select option `1` and enter the student's information:
- Name
- Number
- Midterm grade
- Final grade

### 2. List Records

To list student records, select option `2`. You will be presented with two options:
- `1-List by Number`
- `2-List by Grades`

Select `1` to list by number, or `2` to list by grades. If you choose to list by grades, you will need to specify the grade type (midterm or final) and the lower/upper limits for filtering.

### 3. Calculate Class Average

To calculate the class average, select option `3`. The program will calculate the average based on the students' midterm and final grades.

### 4. Show Top Performing Student by Average

To find the top-performing student, select option `4`. The program will calculate the averages and display the top student.

### 5. Update Record

To update a student record, select option `5` and enter the student's number. Then, enter the new name, midterm, and final grades.

### 0. Exit the Program

To exit the program, select option `0`.

## Functions

- `new_student`: Creates a new student.
- `add_record`: Adds a new student record to the list.
- `list_records`: Displays students in a list format.
- `list_by_number`: Lists students sorted by their numbers.
- `list_by_grades`: Lists students filtered by a specific grade range.
- `update_record`: Updates a student's information.
- `calculate_class_average`: Calculates the class average grade.
- `top_performing_student`: Finds the student with the highest average grade.



