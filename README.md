# nimbus_project_parulnamdev_projectno85
College Examination Invigilation Scheduler
# Invigilation Schedule Generator

This project is a simple C program that automates the process of assigning invigilators (faculty members) to exam slots based on their availability. The program collects faculty details, exam slot names, and then generates a schedule using a round-robin assignment approach. The final schedule is also saved to a file named **`invigilation_schedule.txt`**.

---

## 📌 Features

* Accepts multiple faculty details (name, department, availability).
* Accepts multiple exam slot names.
* Automatically assigns available faculty to each exam slot.
* Uses circular rotation (round-robin) for fair distribution.
* Saves the generated schedule to a text file.

---

## 🔧 How It Works

1. User inputs the number of faculty members.
2. The program collects each faculty's:

   * Name
   * Department
   * Availability (1 = Yes, 0 = No)
3. User inputs the number of exam slots and their names.
4. For each slot, the program:

   * Checks current faculty availability
   * If unavailable, moves to next
   * Assigns the first available faculty found
5. If no faculty is available, the slot is assigned **"No Faculty Available"**.
6. Final schedule is printed on the screen and saved to a file.

---

## 📂 Output File

A file named **`invigilation_schedule.txt`** will be created with contents similar to:

```
Slot1 -> FacultyName1
Slot2 -> FacultyName2
Slot3 -> No Faculty Available
```

---

## ▶️ Compilation & Execution

Use the following commands in terminal:

```bash
gcc invigilation.c -o invigilation
./invigilation
```

---

## 📁 File Structure

```
|-- invigilation.c
|-- invigilation_schedule.txt  (auto-generated)
|-- README.md
```

---

## ✨ Authors

* **Praveen Patel**
* **Parul Namdev**

---
