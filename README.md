# delete_testing
Test speed of delete method.

Initial Results:
LinkedList best
Vector/StlList about the same.

The console output is csv, and can be imported into google spreadsheets to generate the plot in this markdown.

General algorithm is:
For Vector:  Populate n items, start timer, delete n items (use iterator through n items), stop timer.
For Linked List:  Populate n items, start timer, delete n items (loop through n items), stop timer.
For Stl List:  Populate n items, start timer, delete n items (use iterator through n items), stop timer.

![Delete Performance](images/Delete Performance (linear).png)