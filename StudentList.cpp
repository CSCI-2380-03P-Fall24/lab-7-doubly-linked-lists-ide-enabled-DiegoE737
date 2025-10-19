#include "StudentList.h"
#include <iostream>
using namespace std;

	// Define a constructor to initialize the list. The list starts with no Students
StudentList::StudentList() {
	head = nullptr;
	tail = nullptr;
	numStudents = 0;
}

	// return the number of students currently in the list

int StudentList::listSize() {
	return numStudents;
}

	//add a Node with a student to the front (head) of the list.
void StudentList::addFront(Student s) {
	Node* newNode = new Node (s, head, nullptr);
	if (head) head->prev = newNode;
	head = newNode;
	if (!tail) tail = head;
	numStudents++;
}

	//add a Node with a student to the back (tail) of the list.
void StudentList::addBack(Student s) {
		Node* newNode = new Node(s, nullptr, tail);
		if (tail) tail->next = newNode;
		tail = newNode;
		if (!head) head = tail;
		numStudents++;
}

	//Print out the names of each student in the list.
void StudentList::printList() {
	Node* curr = head;
	while (curr) {
		cout << curr->data.name << " (" << curr->data.id << ", " << curr->data.GPA << ")\n";
		curr = curr->next;
	}
}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
void StudentList::popBack() {
	if (!tail) return;
	Node* temp = tail;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
	numStudents--;
}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
void StudentList::popFront() {
	if (!head) return;
	Node* temp = head;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr;
	delete temp; 
	numStudents--;
}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
void StudentList::insertStudent(Student s, int index) {
	if (index <= 0) { addFront(s); return; }
	if (index >= numStudents) { addBack(s); return; }

	Node* curr = head;
	for (int i = 0; i < index - 1; i++) curr = curr->next;

	Node* newNode = new Node(s, curr->next, curr);
	curr->next->prev = newNode;
	curr->next = newNode;
	numStudents++;
}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
Student StudentList::retrieveStudent(int idNum) {
	Node* curr = head;
	while (curr) {
		if (curr->data.id == idNum) return curr->data;
		curr = curr->next;
	}
	return Student();
}



	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
void StudentList::removeStudentById(int idNum) {
	Node* curr = head;
	while (curr) {
		if (curr->data.id == idNum) {
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;

            if (curr->next) curr->next->prev = curr->prev;
            else tail = curr->prev;

            delete curr;
            numStudents--;
            return;
        }
        curr = curr->next;
    }
}

	//Change the gpa of the student with given id number to newGPA
void StudentList::updateGPA(int idNum, float newGPA) {
	
}

																																												//Add all students from otherList to this list.
																																													//otherlist should be empty after this operation.
																																														/*
																																															For example, if the list has 3 students:
																																																s1 <-> s2 <-> s3
																																																	and otherList has 2 students
																																																		s4 <-> s5
																																																			then after mergeList the currently list should have all 5 students
																																																				s1 <-> s2 <-> s3 <-> s4 <-> s5
																																																					and otherList should be empty and have zero students.
																																																						*/
																																																							void StudentList::mergeList(StudentList &otherList) {}

																																																								//create a StudentList of students whose gpa is at least minGPA.
																																																									//Return